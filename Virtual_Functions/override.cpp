#include <iostream>

class Base
{
public:
    Base() {}
    Base(int n) : id(n) {}
    virtual void printId1()
    {
        std::cout << "Base ID: " << id << " from printId1." << std::endl;
    }
    virtual void printId2()
    {
        std::cout << "Base ID: " << id << " from printId2." << std::endl;
    }
    virtual void printId3()
    {
        std::cout << "Base ID: " << id << " from printId3." << std::endl;
    }
private:
    int id;
};

class Derived : public Base
{
public:
    Derived() {}
    Derived(int n) : id(n) {}
    void printId1() override
    {
        std::cout << "Derived ID: " << id << "from printId1." << std::endl;
    }
    void printId2()
    {
        std::cout << "Derived ID: " << id << "from printId2." << std::endl;
    }
    // Here we have a typo when we try to override printId3 from Base class
    // It compiles but a undesired printId4 method was added
    void printId4()
    {
        std::cout << "Derived ID: " << id << "from printId3." << std::endl;
    }
    // This will raise compiletime error when we have a typo
    /*
    void printId5() override
    {
        std::cout << "Derived ID: " << id << "from printId3." << std::endl;
    }
    */
    
private:
    int id;
};

int main()
{
    Base b(1);
    Derived d(2);

    b.printId1();
    d.printId1();

    b.printId2();
    d.printId2();

    b.printId3();
    d.printId4();
}
