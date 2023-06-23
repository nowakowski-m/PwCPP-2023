#include <iostream>
#include <numeric> // for std::gcd

class Fraction {
public:
    Fraction(int64_t num, int64_t den = 1)
        : numerator(num), denominator(den) { normalize(); }
    Fraction(const Fraction& other)
        : numerator(other.numerator), denominator(other.denominator) {}

    int64_t numerator;   // licznik
    int64_t denominator; // mianownik

    Fraction& operator+=(const Fraction& other) {
        int64_t lcm = std::lcm(denominator, other.denominator);
        numerator = numerator * (lcm / denominator) + other.numerator * (lcm / other.denominator);
        denominator = lcm;
        normalize();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        int64_t lcm = std::lcm(denominator, other.denominator);
        numerator = numerator * (lcm / denominator) - other.numerator * (lcm / other.denominator);
        denominator = lcm;
        normalize();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        normalize();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        numerator *= other.denominator;
        denominator *= other.numerator;
        normalize();
        return *this;
    }

    Fraction operator+() const { return *this; }
    Fraction operator-() const { return Fraction(-numerator, denominator); }

    Fraction operator+(const Fraction& other) const {
        return Fraction(*this) += other;
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(*this) -= other;
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(*this) *= other;
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(*this) /= other;
    }

    double to_double() const {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

private:
    void normalize() {
        if (denominator == 0) {
            std::cerr << "Error: zero denominator" << std::endl;
            return;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int64_t gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    return os << frac.numerator << "/" << frac.denominator;
}