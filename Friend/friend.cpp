#include <iostream>

/*
 * Modified from 
 * https://www.geeksforgeeks.org/friend-class-function-cpp/
 */

class A;
class B;

class A
{
public:
    A():a(0) {};
    void showB(B& x);
    // Friend class
    // Grant class B access to the private members of class A
    friend class B; 
private:
    int a;
};

class B
{
public:
    B():b(0) {};
    void showA(A& x);
    // Friend function
    // Grant A::showB1 function to the private members of class A
    friend void A::showB(B& x);
    friend void globalShowB(B& x);
private:
    int b;
};

void A::showB(B& x)
{
    std::cout << "B::b=" << x.b << std::endl;
}

void B::showA(A& x)
{
    std::cout << "A::a=" << x.a << std::endl;
}

void globalShowB(B& x)
{
    std::cout << "B::b=" << x.b << std::endl;
}

int main()
{
    A a;
    B b;
    b.showA(a);
    a.showB(b);
    globalShowB(b);
    return 0;
}