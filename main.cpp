#include <iostream>

float divide(float numerator, float denominator) {
  if (denominator == 0) {
    throw "Tried to divide by 0";
  }
  std::cout << "== Returning from divide" << std::endl;
  return numerator / denominator;
}

int main(int argc, char const *argv[]) {
  float v = divide(16, 0);
  std::cout << "v = " << v << std::endl;
  return 0;
}
