#include <iostream>
#include <json>

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

class Rational {
public:
    Rational(int n, int d) : num(n), den(d) {
        auto div = gcd(n, d);
        num /= div;
        den /= div;
    }

    Rational operator+(Rational other) const{
        return Rational(num * other.den + den * other.num, den * other.den);
    }

    Rational operator*(Rational other) const{
        return Rational(num * other.num, den * other.den);
    }

    friend std::ostream& operator<<(std::ostream&, Rational);

private:
    int num, den;
};

std::ostream& operator<<(std::ostream& out, Rational r) {
    out << r.num << '/' << r.den;
    return out;
}

int main() {
    Rational r(2, 3), r0(48, 72);

    std::cout << r + r0 << std::endl;
}
