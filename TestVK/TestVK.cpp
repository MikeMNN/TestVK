#include <iostream>

#include "TestClass.h"

int main()
{
  int n;
  char c;
  std::cout << "Введите количество искомых повторений:" << std::endl;
  std::cin >> n;
  FirstNRepeatingStream* n_repeat = new FirstNRepeatingStream(n);
  do {
    std::cout << "Введите следующий символ:" << std::endl;
    std::cin >> c;
    std::cout << n_repeat->next(c) << std::endl;
  } while (c != '0');
}