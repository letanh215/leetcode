#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int array[], int firstIndex, int secondIndex);
int pivot(int array[], int pivotIndex, int endIndex);
void quickSort(int array[], int leftIndex, int rightIndex);

#endif // QUICKSORT_H
