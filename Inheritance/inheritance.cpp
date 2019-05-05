#include <iostream>

// https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance

class A
{
public:
    int x = 1;
    // Constructor
    A() {}
    A(int v1, int v2, int v3): x(v1), y(v2), z(v3) 
    {
        std::cout << "This is constructor from A" << std::endl;
        printFromPublic();
    }
    int printFromPublic()
    {
        std::cout << "Print from public method" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    }
    int callFromPublic()
    {
        std::cout << "Call from public method" << std::endl;
        printFromProtected();
        printFromPrivate();
    }
protected:
    int y = 2;
    int printFromProtected()
    {
        std::cout << "Print from protected method" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    }
private:
    int z = 3; 
    int printFromPrivate()
    {
        std::cout << "Print from private method" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    }
};

// Public Inheritance
class B : public A
{
public:
    // Constructor
    B() {}
    B(int v1, int v2): i(v1), j(v2) {}
    B(int v1, int v2, int v3, int v4, int v5)
    {
        i = v1;
        j = v2;
        x = v3;
        y = v4;
        // z = v5; // Not allowed. z is not accessible from B.
        callPublicFromB();
    }
    int printFromB()
    {
        // x is public
        // y is protected
        // z is not accessible from B
        std::cout << "Print from B" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        // std::cout << z << std::endl; // Not allowed
    }
    int callPublicFromB()
    {
        std::cout << "Call from B" << std::endl;
        callFromPublic();
    }
private:
    int i;
    int j;
};

// Protected Inheritance
class C : protected A
{
public:
    C() {}
    C(int v1, int v2, int v3): A(v1, v2, v3), i(v1), j(v2), k(v3) 
    {
        callPublicFromC();
    }
    int printFromC()
    {
        // x is protected
        // y is protected
        // z is not accessible from C
        std::cout << "Print from C" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        // std::cout << z << std::endl; // Not allowed
    }
    int callPublicFromC()
    {
        std::cout << "Call from C" << std::endl;
        callFromPublic();
    }
private:
    int i;
    int j;
    int k;
};

// Private Inheritance
class D : private A
{
public:
    int printFromD()
    {
        // x is private
        // y is private
        // z is not accessible from D
        std::cout << "Print from D" << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        // std::cout << z << std::endl; // Not allowed
    }
    int callPublicFromD()
    {
        std::cout << "Call from D" << std::endl;
        callFromPublic();
    }
};

int main()
{
    A a;
    a.printFromPublic();
    // a.printFromProtected(); // Not allowed
    // a.printFromPrivate(); // Not allowed
    a.callFromPublic();

    std::cout << "===================" << std::endl;

    B b;
    b.printFromPublic();
    b.callFromPublic();
    b.printFromB();
    b.callPublicFromB();

    std::cout << "===================" << std::endl;

    C c;
    // c.printFromPublic(); // Not allowed
    // c.callFromPublic(); // Not allowed
    c.printFromC();
    c.callPublicFromC();

    std::cout << "===================" << std::endl;

    D d;
    // d.printFromPublic(); // Not allowed
    // d.callFromPublic(); // Not allowed
    d.printFromD();
    d.callPublicFromD();
    std::cout << "===================" << std::endl;

    A aa(4, 5, 6);

    std::cout << "===================" << std::endl;

    B bb(10, 11, 12, 13, 14);

    std::cout << "===================" << std::endl;

    C cc(7, 8, 9);
}