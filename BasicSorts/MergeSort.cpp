#include "MergeSort.h"


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
  
  int leftSize = midIndex - leftIndex + 1;
  int rightSize = rightIndex - midIndex;

  int arr1[leftSize];
  int arr2[rightSize];

  for (int i = 0; i < leftSize; i++) {
    arr1[i] = array[leftIndex + i];
  }

  for (int i = 0; i < rightSize; i++) {
    arr2[i] = array[midIndex + i + 1];
  }

  int index = leftIndex;
  int i = 0;
  int j = 0;

  while (i < leftSize && j < rightSize) {
    if (arr1[i] < arr2[j]) {
      array[index] = arr1[i];
      i++; 
    } else {
      array[index] = arr2[j];
      j++;
    }
    index++;
  }

  while (i < leftSize) {
    array[index] = arr1[i];
    i++;
    index++;
  }

  while (j < rightSize) {
    array[index] = arr2[j];
    j++;
    index++;
  }
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex) return;

  int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
  mergeSort(array, leftIndex, midIndex);
  mergeSort(array, midIndex+1, rightIndex);

  merge(array, leftIndex, midIndex, rightIndex);
}