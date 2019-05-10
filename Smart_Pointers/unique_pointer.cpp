#include <iostream>
#include <memory>

class B 
{
public:
    B (int n) : id(n) 
    {
        std::cout << "B::B" << std::endl;
    }
    virtual void bar() 
    {
        std::cout << "B::bar" << std::endl;
    }
    virtual ~B() = default;
    int id;
};

class D : public B
{
public:
    D(int n) : B(n)
    {
        std::cout << "D::D" << std::endl;
    }
    ~D() 
    {
        std::cout << "D::~D" << std::endl;
    }
    void bar() override 
    {
        std::cout << "D::bar" << std::endl;
    }
};

int main()
{
    std::unique_ptr<D> p = std::make_unique<D>(1);
}