#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    os << vec[i];
    if (i != vec.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

int main() {

  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::cout << numbers << std::endl;

  return 0;
}