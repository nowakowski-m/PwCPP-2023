#include <iostream>
#include <array>

int suma(const int tab[], unsigned size) {

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += tab[i];
    }

    return sum;
}

void sumaRes(const int tab[], unsigned size, int *result) {

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += tab[i];
    }

    *result = sum; 
}

void pisz(const int* tab, size_t size, std::ostream *out) {
    
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (i == (size - 1))
            *out << tab[i];
        else
            *out << tab[i] << ", ";
    } 
}

void iota(int tab[], unsigned size) {
    
    for (int i = 0; i <= (size -1); i++) {
        tab[i] = i;
    }
}

void reverse(int *tab, size_t size) {

    int tempTab[size];
    int k = 0;

    for (int i = 0; i < size; i++) {
        tempTab[i] = tab[i];
    }

    for (int j = (size - 1); j >= 0; j--) {
        tab[k] = tempTab[j];
        k++;
    }
}

int dot_product(const int *tab1, const int *tab2, size_t size) {
 
    int vector_sum = 0;
 
    for (int i = 0; i < size; i++) {
        vector_sum += tab1[i] * tab2[i];
    }
 
    return vector_sum;
}

int main() {

    int result = 0;
    int size = 5;
    std::ostream *out = &std::cout;
    int testArray[size] = {10, 20, 30, 40, 50};
    int testArray2[size] = {1, 2, 3, 4, 5};
    int emptyArray[size];

    // ex. A
    std::cout << "function 'suma':\t|\t" << suma(testArray, size) << "\n";

    // ex. B
    sumaRes(testArray, size, &result);
    std::cout << "function 'sumaRes':\t|\t" << result << "\n";

    // ex. C
    std::cout << "function 'pisz':\t|\t";
    pisz(testArray, size, out);
    std::cout << "\n";

    // ex. D
    std::cout << "function: 'iota':\t|\t";
    iota(emptyArray, size);
    for (int i = 0; i <= (size - 1); i++) {
        if (i == (size - 1))
            std::cout << emptyArray[i];
        else
            std::cout << emptyArray[i] << ", ";
    }
    std::cout << "\n";

    // ex. E
    std::cout << "function 'reverse':\t|\t";
    reverse(testArray, size);
    for (int i = 0; i < size; i++) {
        if (i == (size - 1))
            std::cout << testArray[i];
        else
            std::cout << testArray[i] << ", ";
    }
    std::cout << "\n";

    // ex. F
    std::cout << "function 'dot_product':\t|\t" << dot_product(testArray, testArray2, size) << "\n";

    // main return
    return 0;

}