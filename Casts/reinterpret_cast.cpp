#include <iostream>

/*
 * reinterpret_cast
 * Does not do type check for pointer type conversion compatibilities.
 * It is the most dangerous cast.
 * Know what you are doing before using it.
 */

/*
 * Modified from
 * https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
 */

class A { 
public: 
    void func_a() 
    { 
        std::cout << "In class A" << std::endl; 
    } 
    int a1 = 100;
    int a2 = 200;
}; 
  
class B { 
public: 
    void func_b() 
    { 
        std::cout << "In class B" << std::endl; 
    } 
    int b = 300;
}; 
  
struct C 
{ 
    int x = 1; 
    int y = 2; 
    char c = 'z'; 
    bool b = true; 
}; 


int main() 
{ 
    // Creating object of class B 
    B * b = new B(); 
  
    // Converting the pointer to object 
    // Referenced of class B to class A 
    A * ptr_a = reinterpret_cast<A *>(b); 
  
    // Accessing the function of class A 
    ptr_a->func_a(); 
    std::cout << "A::a1: "<< ptr_a->a1 << std::endl;
    // Undefined behavior
    std::cout << "A::a2: "<< ptr_a->a2 << std::endl;

    delete b;

    // Creating an object of struct C
    C c;
    int * ptr_c_int = reinterpret_cast<int *> (&c);
    std::cout << *ptr_c_int << std::endl;
    ptr_c_int ++;
    std::cout << *ptr_c_int << std::endl;
    ptr_c_int ++;
    char * ptr_c_char = reinterpret_cast<char *> (ptr_c_int);
    std::cout << *ptr_c_char << std::endl;
    ptr_c_char ++;
    bool * ptr_c_bool = reinterpret_cast<bool *> (ptr_c_char);
    std::cout << *ptr_c_bool << std::endl;
    ptr_c_bool ++;

    // Check the size of the variables
    std::cout << "C: " << sizeof(c) << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "char: " << sizeof(char) << std::endl;
    std::cout << "bool: " << sizeof(bool) << std::endl;

    // Check the pointer offsets
    std::cout << "ptr_c_int - &c: " << (size_t) ptr_c_int - (size_t) (&c) << std::endl;
    std::cout << "ptr_c_char - ptr_c_int: " << (size_t) ptr_c_char - (size_t) ptr_c_int << std::endl;
    std::cout << "ptr_c_bool - ptr_c_char: " << (size_t) ptr_c_bool - (size_t) ptr_c_char << std::endl;

    // 'z': 122
    int ascii = 122;
    char * z = reinterpret_cast<char *> (&ascii);
    std::cout << z << std::endl;

    return 0; 
} 