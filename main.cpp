#include <iostream>

#include <exception>

class DivideByZeroException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Tried to divide by 0.";
  }
};

class DivideBySevenException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Tried to divide by 7.";
  }
};

float divide(float numerator, float denominator) {
  float* v = new float;
  // try {
  //   if (denominator == 0) {
  //     throw "divided by 0";
  //   }
  // } catch (const char* e) {
  //   std::cerr << "Exeption caught in divide(): " << e << std::endl;
  // }
  if (denominator == 0) {
    delete v;
    throw DivideByZeroException();
  }
  if (denominator == 7) {
    delete v;
    throw DivideBySevenException();
  }
  *v = numerator / denominator;
  float returnval = *v;
  delete v;
  std::cout << "== Returning from divide" << std::endl;
  return returnval;
}

int main(int argc, char const *argv[]) {
  float v = 0;
  try {
    v = divide(16, 0);
  } catch (std::exception& e) {
    std::cerr << "Woops!  Bad division: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Woops!  Some exception was thrown." << std::endl;
  }
  //  catch (DivideByZeroException& e) {
  //   std::cerr << "Woops!  Tried to divide by 0: " << e.what() << std::endl;
  // } catch (DivideBySevenException& e) {
  //   std::cerr << "Woops!  Tried to divide by 7: " << e.what() << std::endl;
  // }

  std::cout << "v = " << v << std::endl;
  return 0;
}
