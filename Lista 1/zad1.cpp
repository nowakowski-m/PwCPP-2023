#include <iostream>
#include <math.h>

double exampleA(double n) {

    double ans;

    for (double j = 1; j <= n; j++) {
        double up = pow((-1), (j+1));
        double down = ((2*j) - 1);
        ans += (up / down);
    }

    return (ans * 4);
}

double exampleB(double n) {

    double ans = 1;

    for (double j = 1; j <= n; j++) {
        double up = 4 * (j * j);
        double down = (4 * (j * j)) - 1;
        ans *= (up / down);
    }

    return (ans * 2);
}

double exampleC(double n) {

    double ans;

    for (double j = 1; j <= n; j++) {
        double up = 1;
        double down = ((2*j) - 1) * ((2*j) - 1);
        ans += (up / down); 
    }

    return (sqrt(ans * 8));

}

int main() {

    std::cout << "Example A: " << exampleA(1000000) << " == " << (exampleA(1000000) / M_PI) << " Pi" << std::endl;
    std::cout << "Example B: " << exampleB(1000000) << " == " << (exampleB(1000000) / M_PI) << " Pi" << std::endl;
    std::cout << "Example C: " << exampleC(1000000) << " == " << (exampleC(1000000) / M_PI) << " Pi" << std::endl;
    
    return 0;
}