#ifndef SORTING_H
#define SORTING_H

typedef struct
{
    long long comparisons;
    long long swaps;
} SortStats;

void bubbleSort(int arr[], int n, SortStats *stats);
void selectionSort(int arr[], int n, SortStats *stats);
void insertionSort(int arr[], int n, SortStats *stats);
void mergeSort(int arr[], int n, SortStats *stats);
void quickSort(int arr[], int n, SortStats *stats);

#endif
