#include <iostream>
using namespace std;
class Complex {
private:
    double real;  
    double imag;  
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
    }
    Complex operator/(const Complex& other) const {
        double denominator = (other.real * other.real) + (other.imag * other.imag);
        return Complex(((real * other.real) + (imag * other.imag)) / denominator,
            ((imag * other.real) - (real * other.imag)) / denominator);
    }
    void displayComplex() const {
        cout << "(" << real << " + " << imag << "i)";
    }
};
int main() {
    Complex complex1(2, 3);
    Complex complex2(1, -1);
    Complex sum = complex1 + complex2;
    cout << "����: ";
    sum.displayComplex();
    cout << endl;
    Complex difference = complex1 - complex2;
    cout << "г�����: ";
    difference.displayComplex();
    cout << endl;
    Complex product = complex1 * complex2;
    cout << "�������: ";
    product.displayComplex();
    cout << endl;
    Complex quotient = complex1 / complex2;
    cout << "������: ";
    quotient.displayComplex();
    cout << endl;
    return 0;
}