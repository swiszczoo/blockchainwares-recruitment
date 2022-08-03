#include <fc/static_variant.hpp>
#include <iostream>

int main() {
  fc::static_variant<int, float> test = 2.2f;
  std::cout << test.get<float>() << std::endl;

  return 0;
}
