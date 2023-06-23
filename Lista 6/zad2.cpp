#include "zad1.h"
#include <cmath>

void calculateSumA() {
    Fraction sum(0);
    for (int i = 1; i <= 10; ++i) {
        sum += Fraction(1, i * (i + 1));
        std::cout << "N = " << i << ", sum = " << sum << ", value = " << sum.to_double() << std::endl;
    }
}

void calculateSumB() {
    Fraction sum(0);
    for (int i = 1; i <= 10; ++i) {
        sum += Fraction(std::pow(-1, i + 1), i);
        std::cout << "N = " << i << ", sum = " << sum << ", value = " << sum.to_double() << std::endl;
    }
}

void calculateSumC() {
    Fraction sum(0);
    for (int i = 1; i <= 10; ++i) {
        sum += Fraction(1, std::pow(2, i) * i);
        std::cout << "N = " << i << ", sum = " << sum << ", value = " << sum.to_double() << std::endl;
    }
}

int main() {

    calculateSumA();
    calculateSumB();
    calculateSumC();

    return 0;
}