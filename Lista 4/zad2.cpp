#include <iostream>
#include <cmath>

double find_root(double (*f)(double),double a,double b,double tolerance = 1e-10) {

    double arg = 0.0;

    while ((b-a) > tolerance) {
        arg = (a + b) / 2.0; 

        if ((f(a) * f(arg)) < 0)
            b = arg;
        else
            a = arg;
    }
   
    return arg;
}

double cosX(double x) {
    return cos(x) - x;
}

double cosHalf(double x) {
    return cos(x) - 0.5;
}

int main() {

    std::cout << "Wartość pierwiastka z cos(x) = x: " << find_root(cosX, 0.0, 2.0) << "\n";
    std::cout << "Wartość pierwiastka z cos(x) = 0.5: " << find_root(cosHalf, 0.0, 1.5) << "\n";
}