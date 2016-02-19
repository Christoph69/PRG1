#include "../inc/sort.h"
#include <cstdio>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

void printArray(int *array, int elements) {
  for (int i = 0; i < elements; i++) {
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int array[10] = { 10, 3, 2, 5, 6, 7, 6, 11, 9, 23 };

  printArray(array, LEN(array));

  // bubbleSort(array, 0, LEN(array));
  // selectionSort(array, 0, LEN(array));
  // insertSort(array, 0, LEN(array));
  quickSort(array, 0, LEN(array));
  printArray(array, LEN(array));

  return 0;
}
