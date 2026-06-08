#ifndef SORTING_H
#define SORTING_H

typedef struct
{
    long long comparisons;
    long long swaps;
    double timeUsed;
} SortStats;

void insertionSort(SortStats *s);
void bubbleSort(SortStats *s);
void selectionSort(SortStats *s);
void mergeSort(SortStats *s);
void quickSort(SortStats *s);

#endif
