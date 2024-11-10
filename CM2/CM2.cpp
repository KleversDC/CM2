#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator(numerator), denominator(denominator) {
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    void display() const {
        cout << numerator << "/" << denominator;
    }
};

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0)
        : real(real), imaginary(imaginary) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denom,
            (imaginary * other.real - real * other.imaginary) / denom);
    }

    void display() const {
        cout << real << " + " << imaginary << "i";
    }
};

int main() {
    Fraction f1(3, 4), f2(2, 5);
    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;

    cout << "Fraction Operations:" << endl;
    cout << "Sum: "; sum.display(); cout << endl;
    cout << "Difference: "; diff.display(); cout << endl;
    cout << "Product: "; prod.display(); cout << endl;
    cout << "Quotient: "; quot.display(); cout << endl;

    Complex c1(3, 4), c2(1, 2);
    Complex c_sum = c1 + c2;
    Complex c_diff = c1 - c2;
    Complex c_prod = c1 * c2;
    Complex c_quot = c1 / c2;

    cout << "\nComplex Number Operations:" << endl;
    cout << "Sum: "; c_sum.display(); cout << endl;
    cout << "Difference: "; c_diff.display(); cout << endl;
    cout << "Product: "; c_prod.display(); cout << endl;
    cout << "Quotient: "; c_quot.display(); cout << endl;
}
