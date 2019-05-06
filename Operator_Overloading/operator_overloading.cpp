#include <iostream>
#include <string>

class Complex
{
public:
    Complex() {};
    // Could be used as conversion constructor
    Complex(int r): real(r), imag(0) {};
    Complex(int r, int i): real(r), imag(i) {};
    // Operator overloading
    // It is a normal function with key word operator and an operator symbol
    // Binary operator
    Complex operator + (const Complex & obj) const
    {
        Complex result(real + obj.real, imag + obj.imag);
        return result;
    }
    // Unary operator
    void operator -- ()
    {
        real --;
        imag --;
    } 
    void print()
    {
        std::cout << real << " + i" << imag << std::endl;
    }
    // The global operator function is made friend of this class so 
    // that it can access private members 
    friend Complex operator - (const Complex & c1, const Complex & c2); 
    // Conversion operator
    operator std::string() const
    {
        return std::to_string(real) + " + i" + std::to_string(imag);
    }
private:
    int real;
    int imag;
};

// Global operator
Complex operator - (const Complex &c1, const Complex &c2) 
{ 
     return Complex(c1.real - c2.real, c1.imag - c2.imag); 
} 

int main()
{
    Complex a(1,2);
    Complex b(4,5);
    a.print();
    b.print();
    Complex c;
    c = a + b;
    c.print();
    // Somehow you could only put the unary operator at the left side
    // Might have some way to get around
    --a;
    a.print();
    Complex d = b - a;
    d.print();
    std::string complex1 = std::string(d);
    std::cout << complex1 << std::endl;
    // Call conversion constructor
    d = 30;
    d.print();
}
