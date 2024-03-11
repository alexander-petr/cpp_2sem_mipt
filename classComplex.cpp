#include <iostream>
#include <fstream>

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double real, double imag) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    Complex operator*(int scalar) {
        return Complex(real * scalar, imag * scalar);
    }

    Complex operator++() {
        real += 1;
        return *this;
    }

    Complex operator++(int) {
        Complex old = *this;
        real += 1;
        return old;
    }


    double getReal() {
        return real;
    }

    double getImag() {
        return imag;
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex) {
        out << complex.real << " + " << complex.imag << "i";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Complex& complex) {
        in >> complex.real >> complex.imag;
        return in;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(2, 3);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex multipliedByScalar = c1 * 3;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Multiplied by scalar: " << multipliedByScalar << std::endl;


    std::cout << "c1 after post-increment: " << c1++ << std::endl;


    std::cout << "c1 after pre-increment: " << ++c1 << std::endl;

    std::ofstream file("complex.txt");
    file << product << "," << sum;
    file.close();
}
