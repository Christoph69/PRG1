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
    std::cout << "Ausgabe first: " << tegut.first << std::endl;
    std::cout << "Ausgabe last: " << tegut.last << std::endl;
  }

  outputList(&tegut);


  return 0;
}
