#include <iostream>

// More complicated typedef
typedef int int_t, *intp_t, (&fp)(int, float), arr_t[10];

int my_int_func(int x, float y)
{
    return x;
}

int main()
{
    int a[3] = {5,6,7};
    int_t b = 0;
    intp_t c = a + 1;
    int (*d) (int, float);
    d = &my_int_func;
    int e = d(8, 1.1);
    fp f = my_int_func;
    int g = f(8, 1.1);
    arr_t h = {8,9,10};
    
    for (int i = 0; i < sizeof(a)/sizeof(int); i ++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << b << std::endl;
    std::cout << *c << std::endl;
    std::cout << e << std::endl;
    std::cout << g << std::endl;
    for (int i = 0; i < sizeof(h)/sizeof(int); i ++)
    {
        std::cout << h[i] << std::endl;
    }
    return 0;
}