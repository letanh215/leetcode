#include "SelectionSort.h"

void selectionSort(int array[], int size) {
  int min_index = 10000;
  for (int i = 0; i < size; i++) {
    min_index = i;
    for (int j = i+1; j < size; j++){
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
    if (i != min_index) {
      int temp = array[i];
      array[i] = array[min_index];
      array[min_index] = temp;
    }
  }
}