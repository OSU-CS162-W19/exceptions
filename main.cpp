#include <iostream>

float divide(float numerator, float denominator) {
  return numerator / denominator;
}

int main(int argc, char const *argv[]) {
  float v = divide(16, 0);
  std::cout << "v = " << v << std::endl;
  return 0;
}
