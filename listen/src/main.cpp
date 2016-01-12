// main.cpp
#include "../inc/listen.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  List tegut;

  initializeList(&tegut);
  std::cout << "Ausgabe first: " << tegut.first << std::endl;
  std::cout << "Ausgabe last: " << tegut.last << std::endl;

  for (int i = 0; i < 3; i++) {
    insert0(&tegut, insertArtikel());

    // std::cout << "Ausgabe first: " << tegut.first << std::endl;
    // std::cout << "Ausgabe last: " << tegut.last << std::endl;
  }

  insertLast(&tegut, insertArtikel());
  insertPos(&tegut, insertArtikel(), 2);
  outputList(&tegut);

  std::cout << "Nach remove0:" << std::endl;
  remove0(&tegut);
  outputList(&tegut);

  std::cout << "Nach removePos:" << std::endl;
  removePos(&tegut, 1);
  outputList(&tegut);

  return 0;
}
