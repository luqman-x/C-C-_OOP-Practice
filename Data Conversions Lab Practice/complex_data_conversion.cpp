#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Member function: addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Member function: subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Member function: comparison
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Friend function: input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Friend function: output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nFirst Complex: " << c1;
    cout << "\nSecond Complex: " << c2;
    cout << "\nSum: " << sum;
    cout << "\nDifference: " << diff;

    if (c1 == c2)
        cout << "\nThe two complex numbers are equal.\n";
    else
        cout << "\nThe two complex numbers are not equal.\n";

    return 0;
}
