#include <iostream>
#include <vector>
#include <algorithm>

struct Sortuj {
    bool operator()(int a, int b) {
        return (a % 10) < (b % 10);
    }
};

void bez_lambda() {

    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 6, 8};
    
    std::sort(v.begin(), v.end(), Sortuj());
    
    for (auto i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void z_lambda() {

    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 6, 8};
    
    std::sort(v.begin(), v.end(),
        [](int a, int b) {
            return (a % 10) < (b % 10);
        });

    for (auto i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main() {

    std::cout << "Bez użycia lambda:\n";
    bez_lambda();
    std::cout << "Z użyciem lambda:\n";
    z_lambda();
    
    return 0;
}