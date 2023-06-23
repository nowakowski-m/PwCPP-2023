#include <iostream>
#include <iomanip>

double downDouble(int N) {
    
    double sum = 0;
    
    for (int i = 1; i <= N; i++) {
        sum += 1.0 / i;
    }

    return sum;
}

double upDouble(int N) {

    double sum = 0;
    
    for (int i = N; i >= 1; i--) {
        sum += 1.0 / i;
    }

    return sum;
}

float downFloat(int N) {

    float sum = 0;

    for (int i = 1; i <= N; i++) {
        sum += 1.0f / i;
    }

    return sum;
}

float upFloat(int N) {
    
    float sum = 0;
    
    for (int i = N; i >= 1; i--) {
        sum += 1.0f / i;
    }
    
    return sum;
}

int main() {
    
    int N1 = 100;
    int N2 = 100000;
    int N3 = 100000000;

    std::cout << "Sum using doubles:" << std::endl;

    std::cout << "N = " << N1 << ", ";
    std::cout << "down(N) = " << std::setprecision(20) << downDouble(N1) << ", ";
    std::cout << "up(N) = " << std::setprecision(20) << upDouble(N1) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(20) << upDouble(N1) - downDouble(N1) << std::endl;

    std::cout << "N = " << N2 << ", ";
    std::cout << "down(N) = " << std::setprecision(20) << downDouble(N2) << ", ";
    std::cout << "up(N) = " << std::setprecision(20) << upDouble(N2) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(20) << upDouble(N2) - downDouble(N2) << std::endl;

    std::cout << "N = " << N3 << ", ";
    std::cout << "down(N) = " << std::setprecision(20) << downDouble(N3) << ", ";
    std::cout << "up(N) = " << std::setprecision(20) << upDouble(N3) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(20) << upDouble(N3) - downDouble(N3) << std::endl;

    std::cout << std::endl << "Sum using floats:" << std::endl;

    std::cout << "N = " << N1 << ", ";
    std::cout << "down(N) = " << std::setprecision(8) << downFloat(N1) << ", ";
    std::cout << "up(N) = " << std::setprecision(8) << upFloat(N1) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(8) << upFloat(N1) - downFloat(N1) << std::endl;

    std::cout << "N = " << N2 << ", ";
    std::cout << "down(N) = " << std::setprecision(8) << downFloat(N2) << ", ";
    std::cout << "up(N) = " << std::setprecision(8) << upFloat(N2) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(8) << upFloat(N2) - downFloat(N2) << std::endl;

    std::cout << "N = " << N3 << ", ";
    std::cout << "down(N) = " << std::setprecision(8) << downFloat(N2) << ", ";
    std::cout << "up(N) = " << std::setprecision(8) << upFloat(N3) << ", ";
    std::cout << "up(N) - down(N) = " << std::setprecision(8) << upFloat(N3) - downFloat(N3) << std::endl;

    return 0;
}