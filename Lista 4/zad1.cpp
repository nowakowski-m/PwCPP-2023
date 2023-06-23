#include <iostream>
#include <vector>

double operator * (std::vector<double> &x, std::vector<double> &y) {
    double product = 0;
    for (int i = 0; i <= (x.size()); i++) {
        product += (x[i] * y[i]);
    }

    return product;
}

int main() {

    std::vector<double> v = {2.0, 4.0, 8.0};
    std::vector<double> w = {8.0, 4.0, 2.0};

    double result = v*w;

    std::cout << "Dot product: " << result << "\n";

    return 0;
}

