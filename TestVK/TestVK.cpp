#include <iostream>

#include "TestClass.h"

int main()
{
  int n;
  char c;
  std::cout << "Enter reuqired amount of repeats:" << std::endl;
  std::cin >> n;
  while (std::cin.fail() || n <= 0) {
    std::cout << "Enter correct reuqired amount of repeats(integer >=0):" << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> n;
  }

  FirstNRepeatingStream* n_repeat = new FirstNRepeatingStream(n);
  do {
    std::cout << "Enter next char:" << std::endl;
    std::cin >> c;
    std::cout << n_repeat->next(c) << std::endl;
  } while (c != '0');
}
