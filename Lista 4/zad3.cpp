#include <iostream>

int main(int argc, char* argv[]) {

    double numsSum = 0;
    double currNum = 0;
    bool printSum = true;
    std::string arg;

    for (int i = 1; i < argc; i++) {

        arg = argv[i];

        if (arg == "--help" || arg   == "-h") {
            printSum = false;
            std::cout << "Program sumuje liczby podane jako argumenty polecenia.\nNa przykład ./a.out 1 2 3, output: 6\n";
        }

        else {
            currNum = std::stod(arg);
            numsSum += currNum;
        }
    }

    if (printSum == true) {
        std::cout << "Suma: " << numsSum << "\n";
    }

    return 0;
}