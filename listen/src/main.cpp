// main.cpp
#include "../inc/listen.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  List tegut;

  tegut.first = nullptr;
  tegut.last  = nullptr;
  std::cout << "Ausgabe first: " << tegut.first << std::endl;
  std::cout << "Ausgabe last: " << tegut.last << std::endl;


  return 0;
}
