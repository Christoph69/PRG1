// main.cpp
#include "../inc/tree.h"

int main(int argc, char const *argv[]) {
  Knoten *baum    = nullptr;
  int     eingabe = 0;
  float   zahl    = 574.4;
  std::printf("%lx\n", *(unsigned long *)(&zahl));

  for (int i = 0; i < 5; i++) {
    printf("Bitte Zahl[%d]: ", i);
    std::scanf("%d", &eingabe);
    insertNode(&baum, eingabe);
  }
  outputTree(&baum);
  return 0;
}
