#include <iostream>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <unistd.h>

std::complex<double> *generateComplexNums(int size) {

    using namespace std::complex_literals;
    std::complex<double> *complexTab = new std::complex<double>[size];

    for (int i = 0; i < size; i++) {
        std::srand(std::time(nullptr));
        double real = (std::rand() % 210 - 100) / 10.0;
        double imaginary = (std::rand() % 210 - 100) / 10.0;
        complexTab[i] = std::complex<double> (real, imaginary);
        usleep(1000000);
    }

    return complexTab;
}

int main() {

    int size = 5;
    std::complex<double> *complexNums = generateComplexNums(size);
    double absTab[size];

    std::cout << "Complex nums list:" << "\n";

    for (int i = 0; i < size; i++) {
        if (i == (size - 1))
            std::cout << complexNums[i];
        else
            std::cout << complexNums[i] << ", ";
    }

    std::cout << "\n" << "Just absolute values:" << "\n";

    for (int i = 0; i < size; i++) {
        absTab[i] = std::abs(complexNums[i]);
        if (i == (size - 1))
            std::cout << absTab[i];
        else
            std::cout << absTab[i] << ", ";
    }

    std::qsort
    (
        absTab,
        size,
        sizeof(double),
        [](const void* x, const void* y)
        {
            auto x_abs = *static_cast<const double*>(x);
            auto y_abs = *static_cast<const double*>(y);
            if (x_abs < y_abs) return -1;
            if (x_abs > y_abs) return 1;
            return 0;
        }
    );

    std::cout << "\n" << "Sorted absolute values:" << "\n";

    for (int i = 0; i < size; i++) {
        if (i == (size - 1))
            std::cout << absTab[i];
        else
            std::cout << absTab[i] << ", ";
    }

    std::cout << "\n";

    return 0;
}