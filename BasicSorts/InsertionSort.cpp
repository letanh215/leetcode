#include "InsertionSort.h"


void insertionSort(int array[], int size) {

  for (int i = 1; i < size; i++) {
    int j = i;
    while (j > 0) {
      if (array[j] < array[j-1]) {
        int temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
        j--;
      } else {
        break;
      }
    }
  }
}