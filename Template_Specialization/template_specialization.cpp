#include <iostream> 

// Template specialization functions
template <typename T>
void func(T a)
{
    std::cout << "Main template func prints: " << a << std::endl;
}

template <>
void func(int a)
{
    std::cout << "Specialized template func prints: " << a << std::endl;
}

// Template specialization classes
template <typename T>
class A
{
public:
    A(T x): value1(x)
    {
        std::cout << "Class created using main template class" << std::endl;
    };
private:
    T value1;
};

template <>
class A<int>
{
public:
    A(int x, int y): value1(x), value2(y)
    {
        std::cout << "Class created using specialized template class" << std::endl;
    };
private:
    int value1;
    int value2;
};

int main()
{
    func<float>(1);
    func<int>(1);

    A<float> a1(1);
    A<int> a2(1 ,1);
}