#include<iostream> 

class Base 
{ 
public: 
    Base()      
    {
        std::cout << "Constructing Base" << std::endl;
    } 
    ~Base()
    {
        std::cout << "Destructing Base" << std::endl;
    }
    void print1()
    {
        std::cout << "Print from Base::print1" << std::endl;
    }
    virtual void print2()
    {
        std::cout << "Print from Base::print2" << std::endl;
    }
}; 

class Derived: public Base 
{
public: 
    Derived()      
    {
        std::cout << "Constructing Derived" << std::endl;
    } 
    ~Derived() 
    {
        std::cout << "Destructing Derived" << std::endl;
    }

    void print1()
    {
        std::cout << "Print from Derived::print1" << std::endl;
    }
    void print2()
    {
        std::cout << "Print from Derived::print2" << std::endl;
    }
}; 

class NewBase 
{ 
public: 
    NewBase()      
    {
        std::cout << "Constructing NewBase" << std::endl;
    } 
    virtual ~NewBase()
    {
        std::cout << "Destructing NewBase" << std::endl;
    }
    void print1()
    {
        std::cout << "Print from NewBase::print1" << std::endl;
    }
    virtual void print2()
    {
        std::cout << "Print from NewBase::print2" << std::endl;
    }
}; 

class NewDerived: public NewBase 
{
public: 
    NewDerived()      
    {
        std::cout << "Constructing NewDerived" << std::endl;
    } 
    ~NewDerived() 
    {
        std::cout << "Destructing NewDerived" << std::endl;
    }

    void print1()
    {
        std::cout << "Print from NewDerived::print1" << std::endl;
    }
    void print2()
    {
        std::cout << "Print from NewDerived::print2" << std::endl;
    }
}; 

  
int main() 
{
    Derived * d = new Derived();
    d->print1();
    delete d;
    std::cout << "================" << std::endl;
    d = new Derived();
    Base * b = d;
    d->print1();
    d->print2();
    b->print1();
    b->print2();
    // Base class object was deleted
    // Only destructor from Base was called
    delete b;
    d->print1();
    // d->print2(); // Not allowed
    delete d;
    std::cout << "================" << std::endl;
    NewDerived * nd = new NewDerived();
    NewBase * nb = nd;
    // Both destructors were called
    // After the derived class destructor was called
    // The base class destructor will be called
    delete nb;
} 