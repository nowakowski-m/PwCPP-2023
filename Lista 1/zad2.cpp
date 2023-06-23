#include <iostream>
#include <math.h>

int main() {

    double ta[31];
    double tb[31];
    double pia[31];
    double pib[31];
    double n = 30;
    ta[0] = (1 / (sqrt(3)));
    tb[0] = (1 / (sqrt(3)));

    for (int i = 0; i <= 30; i++) {
        ta[i+1] = (((sqrt((ta[i] * ta[i]) + 1)) - 1) / ta[i]);
        tb[i+1] = (tb[i] / (((sqrt((ta[i] * ta[i]) + 1)) + 1)));
        pia[i] = 6 * pow(2, i) * ta[i];
        pib[i] = 6 * pow(2, i) * tb[i];
        
        if ((std::to_string(pia[i]) == "-nan") || (pia[i] == 0)) {
            std::cout << "A: " << pia[i] << "\t\t | \t B: " << pib[i] << std::endl;
        }

        else {
            std::cout << "A: " << pia[i] << "\t | \t B: " << pib[i] << std::endl;
        }
    }
}