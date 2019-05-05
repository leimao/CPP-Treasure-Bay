#include <iostream>

/*
 * Virtual function and dynamic cast
 * Modified from 
 * https://www.geeksforgeeks.org/virtual-function-cpp/
 */

class Base 
{ 
public: 
    void fun_1() 
    {
        std::cout << "base-1" << std::endl;
    } 
    virtual void fun_2()
    {
        std::cout << "base-2" << std::endl;
    } 
    virtual void fun_3() 
    {
        std::cout << "base-3" << std::endl;
    } 
    virtual void fun_4() 
    {
        std::cout << "base-4" << std::endl;
    } 
}; 
  
class Derived : public Base  
{ 
public: 
    void fun_1() 
    {
        std::cout << "derived-1" << std::endl;
    } 
    void fun_2() 
    {
        std::cout << "derived-2" << std::endl;
    } 
    void fun_4(int x) 
    {
        std::cout << "derived-4" << std::endl;
    } 
}; 


class A
{
public:
    virtual void func_1()
    {
        std::cout << "Virtual method from class A" << std::endl;
    }
    void func_2()
    {
        std::cout << "Non-virtual method from class A" << std::endl;
    }

};

class B: public A
{
public:
    virtual void func_1()
    {
        std::cout << "Virtual method from class B" << std::endl;
    }
    void func_2()
    {
        std::cout << "Non-virtual method from class B" << std::endl;
    }

};

class C: public A
{
public:
    virtual void func_1()
    {
        std::cout << "Virtual method from class C" << std::endl;
    }
    void func_2()
    {
        std::cout << "Non-virtual method from class C" << std::endl;
    }

};

class D: public B, public C
{
public:
    virtual void func_1()
    {
        std::cout << "Virtual method from class D" << std::endl;
    }
    void func_2()
    {
        std::cout << "Non-virtual method from class D" << std::endl;
    }

};

int main() 
{ 
    Base *p; 
    Derived obj1; 
    // Up cast 
    // No need to use dynamic_cast
    p = &obj1; 
  
    // Early binding because fun1() is non-virtual 
    // in base 
    p->fun_1(); 
  
    // Late binding (RTP) 
    p->fun_2(); 
  
    // Late binding (RTP) 
    p->fun_3(); 
  
    // Late binding (RTP) 
    p->fun_4(); 
  
    // Early binding but this function call is 
    // illegal(produces error) because pointer 
    // is of base type and function is of 
    // derived class 
    // p->fun_4(5); 

    A a;
    B b;
    C c;
    D d;

    A * p_a = &a;
    B * p_b = &b;
    C * p_c = &c;
    D * p_d = &d;

    // Up cast
    // Always successful
    (dynamic_cast<A *> (p_b))->func_1();
    (dynamic_cast<A *> (p_b))->func_2();

    (dynamic_cast<B *> (p_d))->func_1();
    (dynamic_cast<B *> (p_d))->func_2();

    (dynamic_cast<C *> (p_d))->func_1();
    (dynamic_cast<C *> (p_d))->func_2();

    // Down cast
    B * p_b_new = dynamic_cast<B *> (p_a);
    if (p_b_new == nullptr)
    {
        std::cout << "Unsuccessful casting" << std::endl;
    }

    C * p_c_new = dynamic_cast<C *> (p_b);
    if (p_c_new == nullptr)
    {
        std::cout << "Unsuccessful casting" << std::endl;
    }
} 