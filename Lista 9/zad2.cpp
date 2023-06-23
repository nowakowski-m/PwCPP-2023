#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <iterator>
#include <set>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1)
            os << " ";
        }
    os << "]";
    
    return os;
}

int main() {
    
    std::vector<int> vector1(10);
    std::vector<int> vector2(10);

    std::iota(vector1.begin(), vector1.end(), 0);
    std::cout << "Wektor z liczbami od 0 do 9: " << vector1 << std::endl;

    int sum = std::accumulate(vector1.begin(), vector1.end(), 0);
    std::cout << "Suma elementów wektora 1: " << sum << std::endl;

    std::transform(vector1.begin(), vector1.end(), vector1.begin(), [](int num) {
    return num * num;
    });
    std::cout << "Wektor z kwadratami liczb: " << vector1 << std::endl;

    std::generate(vector2.begin(), vector2.end(), []() {
    return rand() % 15;
    });

    std::cout << "Wektor z losowymi liczbami od 0 do 14: " << vector2 << std::endl;

    auto maxElement = std::max_element(vector2.begin(), vector2.end());
    std::cout << "Maksymalny element z wektora 2: " << *maxElement << std::endl;

    std::sort(vector2.begin(), vector2.end());
    std::cout << "Posortowany wektor 2: " << vector2 << std::endl;

    auto uniqueEnd = std::unique(vector2.begin(), vector2.end());
    vector2.erase(uniqueEnd, vector2.end());
    std::cout << "Wektor 2 bez duplikatów: " << vector2 << std::endl;

    std::vector<int> vector3;
    std::set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(vector3));
    std::cout << "Iloczyn mnogościowy wektora 1 i 2: " << vector3 << std::endl;

    return 0;
}
