#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplifyFraction();
    }
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplifyFraction() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
    Fraction operator+(const Fraction& secondFraction) const {
        int newNumerator = (numerator * secondFraction.denominator) + (secondFraction.numerator * denominator);
        int newDenominator = denominator * secondFraction.denominator;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator-(const Fraction& secondFraction) const {
        int newNumerator = (numerator * secondFraction.denominator) - (secondFraction.numerator * denominator);
        int newDenominator = denominator * secondFraction.denominator;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator*(const Fraction& secondFraction) const {
        int newNumerator = numerator * secondFraction.numerator;
        int newDenominator = denominator * secondFraction.denominator;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator/(const Fraction& secondFraction) const {
        int newNumerator = numerator * secondFraction.denominator;
        int newDenominator = denominator * secondFraction.numerator;
        return Fraction(newNumerator, newDenominator);
    }
    void displayFraction() const {
        cout << numerator << "/" << denominator;
    }
};
int main() {
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
    Fraction sum = fraction1 + fraction2;
    cout << "Sum: ";
    sum.displayFraction();
    cout << endl;
    Fraction difference = fraction1 - fraction2;
    cout << "Difference: ";
    difference.displayFraction();
    cout << endl;
    Fraction product = fraction1 * fraction2;
    cout << "Product: ";
    product.displayFraction();
    cout << endl;
    Fraction quotient = fraction1 / fraction2;
    cout << "Quotient: ";
    quotient.displayFraction();
    cout << endl;
    return 0;
}