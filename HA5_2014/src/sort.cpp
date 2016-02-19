bool isSorted(int *array, unsigned int first, unsigned int end) {
  bool gueltig = first < end - 1;

  for (; first < end - 1 && gueltig; first++) {
    gueltig = array[first] <= array[first + 1];
  }
  return gueltig;
}

static void swap(int *array, int index1, int index2) {
  int buffer = array[index2];

  array[index2] = array[index1];
  array[index1] = buffer;
}

bool bubbleSort(int *array, unsigned int first, unsigned int end) {
  bool swapped = first < end - 1;

  if (!swapped) return false;

  while (end - 1 > first && swapped) {
    swapped = false;

    for (int i = first; i < end - 1; i++) {
      if (array[i] > array[i + 1]) {
        swap(array, i, i + 1);
        swapped = true;
      }
    }
    end--;
  }
  return !swapped;
}

bool selectionSort(int *array, unsigned int first, unsigned int end) {
  bool gueltig = first < end - 1;
  int  iMin    = 0;

  for (int i = first; i < end - 1; i++) {
    iMin = i;

    for (int j = i + 1; j < end; j++) {
      if (array[j] < array[iMin]) iMin = j;
    }

    if (iMin != i) swap(array, i, iMin);
  }
  return gueltig;
}

static void smallstElementToFront(int *array, unsigned int first,
                                  unsigned int end) {
  int iMin = first;

  for (int i = first + 1; i < end; i++) {
    if (array[i] < array[iMin]) iMin = i;
  }
  int tmp = array[iMin];

  while (iMin > 0) {
    array[iMin] = array[iMin - 1];
    iMin        = iMin - 1;
  }
  array[0] = tmp;
}

bool insertSort(int *array, unsigned int first, unsigned int end) {
  bool gueltig = first < end - 1;

  if (!gueltig) return gueltig;

  smallstElementToFront(array, first, end);

  for (int i = first + 2; i < end; i++) {
    int j   = i - 1;
    int tmp = array[i];

    while (tmp < array[j]) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = tmp;
  }
  return gueltig;
}

void quickSort(int *array, unsigned int first, unsigned int end) {
  if (first + 1 >= end) return;

  int  left = first, right = end - 1;
  bool down = true;

  while (left < right) {
    if (array[left] > array[right]) {
      swap(array, left, right);
      down = !down;
    }

    if (down) right--;
    else left++;
  }
  quickSort(array, first,     left);
  quickSort(array, right + 1, end);
}
