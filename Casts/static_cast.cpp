#include <iostream>

// Static cast check type conversion compatibility at compile time
// No check at run time
// Could be dangerous since no runtime check.

class Base 
{
public:
    Base(int x): v1(x) {};
    int v1;
}; 

class PrivateDerived : private Base 
{
public:
    PrivateDerived(int x):Base(x) {};
    int v2 = 100;
}; 

class PublicDerived : public Base 
{
public:
    PublicDerived(int x):Base(x) {};
    int v2 = 100;
}; 

class Random
{

};

int main()
{
    int z = 122;
    char c = 'z';

    // Pass type conversion compatibility check
    float zf1 = static_cast<float> (z);
    std::cout << zf1 << std::endl;

    // Not pointer type
    // Not allowed
    // float zf2 = reinterpret_cast<float> (z);
    // std::cout << zf2 << std::endl;

    int zc1 = static_cast<int> (c);
    std::cout << zc1 << std::endl;

    // Not pointer type
    // Not allowed
    // int zc2 = reinterpret_cast<int> (c);
    // std::cout << zc2 << std::endl;

    // Pass at compile time
    // Result incorrect
    float * p1_z = (float *) &z;
    std::cout << * p1_z << std::endl;
    int * p1_c = (int *) &c;
    std::cout << *p1_c << std::endl;

    // Static cast does compile time compatibility check
    // Raise compile time error
    // float * p2_z = static_cast<float *> (&z);
    // std::cout << * p2_z << std::endl;
    // int * p2_c = static_cast<int *> (&c);
    // std::cout << * p2_c << std::endl;
    
    // Pass at compile time
    // Reinterpret cast does not check type conversion compatibilities.
    // Result incorrect
    float * p3_z = reinterpret_cast<float *> (&z);
    std::cout << * p3_z << std::endl;
    int * p3_c = reinterpret_cast<int *> (&c);
    std::cout << * p3_c << std::endl;

    // Use static cast to cast void pointers from and to
    int i = 10; 
    void * v = static_cast<void *>(&i); 
    int * ip = static_cast<int *>(v); 
    std::cout << *ip << std::endl;

    PrivateDerived prd(33);
    Base * p1_prd = (Base *) &prd;
    // v1 Invisible 
    // std::cout << prd.v1 << std::endl;
    // Peek the private member variables
    // Does not make sense in practice
    std::cout << p1_prd->v1 << std::endl;
    // Not allowed
    // Base * p2_prd = static_cast<Base *> (&prd);

    PublicDerived pud(44);
    Base * p1_pud = (Base *) &pud;
    // v1 Invisible 
    std::cout << pud.v1 << std::endl;
    std::cout << p1_pud->v1 << std::endl;
    Base * p2_pud = static_cast<Base *> (&pud);
    std::cout << p2_pud->v1 << std::endl;
    // Not allowed
    // std::cout << p2_pud->v2 << std::endl;

    // Be careful of using static cast
    Base b(22);
    // This passed compile check but unsafe
    PublicDerived * pb = static_cast<PublicDerived *> (&b);
    // Result is incorrect and does not make sense
    std::cout << pb->v2 << std::endl;

}

