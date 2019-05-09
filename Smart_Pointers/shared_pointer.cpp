#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

// To compile, do not forget to use -pthread:
// g++ -pthread shared_pointer.cpp -o shared_pointer

class Base
{
public:
    Base(int n) : id(n)
    {
        std::cout << "Base Constructor Called for Base Instance Id " << id << std::endl;
    }
    ~Base() 
    {
        std::cout << "Base Destructor Calledfor Base Instance Id " << id << std::endl;
    }
    int id;
};
 
class Derived: public Base
{
public:
    Derived(int n) : Base(n)
    {
        std::cout << "Derived Constructor Called for Derived Instance Id " << id << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived Destructor Called for Derived Instance Id " << id << std::endl;
    }
    void printId()
    {
        std::cout << "Derived Instance Id " << id << std::endl;
    }
};

void thread_func(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // Shared pointer is thread safe
    std::shared_ptr<Base> lp = p;
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << lp.get() << " "<< lp.use_count() << std::endl;
    }
}
 
int main()
{
    // Two ways to create shared pointers
    // make_shared
    std::shared_ptr<Base> p1 = std::make_shared<Derived>(1);
    std::cout << "=============" << std::endl;
    // shared_ptr constructor
    std::shared_ptr<Derived> p2(new Derived(2));
    std::cout << "*************" << std::endl;
    p1 = p2;
    // Here the first Derived instance was destroyed.
    std::cout << "^^^^^^^^^^^^^" << std::endl;

    // Get C pointer from smart pointer
    Derived * p3 = p2.get();

    // Check how many smart pointers pointing to the same instance
    // 2 pointers pointing to the same instance: p1 and p2
    std::cout << p1.use_count() << std::endl;
    
    // Reset p1
    // p1 no longer point to the instance
    p1.reset();

    // Got 0 use count
    std::cout << p1.use_count() << std::endl;
    // The instance was still pointer by p2
    // Got 1 use count
    std::cout << p2.use_count() << std::endl;

    // p1 points to the instance again
    p1 = p2;
    // Got 2 use count
    std::cout << p1.use_count() << std::endl;

    // If we delete the instance 2
    p2->printId();
    delete p3;
    // The smart pointer does not know the instance was deleted.
    // Still got 2 use count
    std::cout << p2.use_count() << std::endl;
    // But the instance was just destroyed
    p2->printId();
    // Best practice: Try to avoid using C pointer with C++ smart pointers

    // Make a new smart pointer to a new instance
    std::shared_ptr<Derived> p4(new Derived(4));

    // Play with threads
    std::cout << "=============" << std::endl;
    std::cout << p4.get() << " "<< p4.use_count() << std::endl;
    std::thread t1(thread_func, p4), t2(thread_func, p4), t3(thread_func, p4);
    p4.reset();
    std::cout << p4.get() << " "<< p4.use_count() << std::endl;
    // Synchronize
    t1.join();
    t2.join();
    t3.join();
    std::cout << "*************" << std::endl;
    // Destructor of instance 2 will still be called
    // Although it has already been deleted by delete p3
}