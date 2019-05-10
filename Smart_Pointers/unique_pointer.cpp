#include <iostream>
#include <memory>
#include <vector>

class B 
{
public:
    B () {}
    B (int n) : id(n) 
    {
        std::cout << "B::B" << std::endl;
    }
    virtual void bar() 
    {
        std::cout << "B::bar" << std::endl;
    }
    virtual ~B()
    {
        std::cout << "B::~B" << std::endl;
    }
    int id;
};

class D : public B
{
public:
    D () {}
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

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

int main()
{
    std::unique_ptr<D> p = std::make_unique<D>(1);
    std::cout << p.get() << std::endl;
    p->bar();
    std::cout << "=====================" << std::endl;
    // Move a unique pointer
    std::unique_ptr<D> q = std::move(p);
    // p no longer owns the object
    std::cout << p.get() << std::endl;
    std::cout << q.get() << std::endl;
    q->bar();
    std::cout << "=====================" << std::endl;
    std::unique_ptr<D> s = pass_through(std::move(q));
    std::cout << q.get() << std::endl;
    std::cout << s.get() << std::endl;
    std::cout << "=====================" << std::endl;
    pass_through(std::move(s));
    // Now you have lost this object
    // Destructors were called
    std::cout << s.get() << std::endl;
    std::cout << "=====================" << std::endl;

    std::unique_ptr<D> d(new D(2));
    std::vector<std::unique_ptr<B>> v;
    v.push_back(std::make_unique<D>(3));
    v.push_back(std::move(d));
    v.emplace_back(new D(4));
    // Runtime polymorphism
    for(auto & p : v)
    {
        p->bar();
    }
    std::cout << "=====================" << std::endl;
    std::unique_ptr<D[]> ap{new D[3]};
    std::cout << "=====================" << std::endl;

    D * m = new D(8);
    std::unique_ptr<D> t(m);
    // This will cause problem
    // std::unique_ptr<D> w(m);
    std::cout << "=====================" << std::endl;
}