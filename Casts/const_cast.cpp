#include <iostream>

/*
 * const_cast
 * Remove const properties from variables temporarily.
 * Best practice:
 * Do anything reasonable using const_cast.
 * Do not try to modify const values!
 */

class A
{
public:
    A(int x): v1(x) {};
    // const function
    void weird_func(int x) const
    {
        // const_cast modifies non-const member even inside const method
        // The type of this: const A *
        (const_cast<A *> (this)) -> v1 = x;
        // (const_cast<A *> (this)) -> v2 = x; // Not allowed
        // const_cast only cast types of pointer types and references 
        // (const_cast<int> (v2)) = x; // Incorrect syntax
        // This should be undefined behavior
        // A weird way even to modify const members
        *(const_cast<int *> (&v2)) = x;
    }
    void printMyself() const
    {
        std::cout << v1 << std::endl;
        std::cout << v2 << std::endl;
    }
    // This method takes a pointer to int as input
    void printOutside(int * ptr) const
    {
        std::cout << *ptr << std::endl;
    }
    // This should be undefined behavior
    void modify_func(int x)
    {
        int * ptr = const_cast<int *> (p_v2);
        *ptr = x;
    }
private:
    int v1;
    const int v2 = 10;
    const int * p_v2 = &v2;
};

void weird_func(int * ptr) 
{ 
    *ptr = 999;
} 

int main()
{
    A a(1);
    a.printMyself();
    a.weird_func(5);
    a.printMyself();
    a.modify_func(50);
    a.printMyself();

    const int g = 100;
    // pointer to const int
    const int * p_g = &g;
    // a.printOutside(p_g); // Not allowed
    // Pass const removed pointer to function
    a.printOutside(const_cast<int *> (p_g));

    const int h = 100;
    const int * p_h = &h;
    int * ptr_h =  const_cast<int *> (p_h);
    // This is undefined behavior
    weird_func(ptr_h);
    std::cout << h << std::endl;
    // This is undefined behavior
    *ptr_h = 999;
    std::cout << h << std::endl;


    int i = 97;
    char c;
    const int * p_i = &i;
    // No basic type change is allowed
    // c = *(const_cast<char *> (p_i)); // Not allowed
    // This old school C styled cast is allowed
    c = *((const char *) p_i);
    std::cout << c << std::endl;
}