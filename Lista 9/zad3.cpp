#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>

std::string removePunctuation(const std::string& word) {
    std::string result;
    std::copy_if(word.begin(), word.end(), std::back_inserter(result), [](char c) {
        return std::isalnum(c);
    });
    return result;
}

int main() {

    std::string filename = "test.txt";

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Nie można otworzyć pliku." << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;

    std::string word;
    while (file >> word) {
        word = removePunctuation(word);
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        wordCount[word]++;
    }

    file.close();

    std::vector<std::pair<std::string, int>> wordOccurrences;
    for (const auto& pair : wordCount) {
        wordOccurrences.push_back(pair);
    }

    std::sort(wordOccurrences.begin(), wordOccurrences.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::cout << "Numer   Liczba   Słowo" << std::endl;
    int count = 1;
    for (const auto& pair : wordOccurrences) {
        std::cout << count << "       " << pair.second << "       " << pair.first << std::endl;
        count++;
    }

    return 0;
}