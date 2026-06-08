#include <stdlib.h>
#include "sorting.h"

void bubbleSort(int arr[], int n, SortStats *stats)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for(j = 0; j < n - i - 1; j++)
        {
            stats->comparisons++;

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                stats->swaps++;
                swapped = 1;
            }
        }

        if(!swapped)
            break;
    }
}

void selectionSort(int arr[], int n, SortStats *stats)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            stats->comparisons++;

            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            stats->swaps++;
        }
    }
}

void insertionSort(int arr[], int n, SortStats *stats)
{
    int i;

    for(i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0)
        {
            stats->comparisons++;

            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                stats->swaps++;
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[],
           int left,
           int mid,
           int right,
           SortStats *stats)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        stats->comparisons++;

        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        stats->swaps++;
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;

        stats->swaps++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;

        stats->swaps++;
    }

    free(L);
    free(R);
}

void mergeSortRec(int arr[],
                  int left,
                  int right,
                  SortStats *stats)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRec(arr,
                     left,
                     mid,
                     stats);

        mergeSortRec(arr,
                     mid + 1,
                     right,
                     stats);

        merge(arr,
              left,
              mid,
              right,
              stats);
    }
}

void mergeSort(int arr[],
               int n,
               SortStats *stats)
{
    mergeSortRec(arr,
                 0,
                 n - 1,
                 stats);
}

int partitionQS(int arr[],
                int low,
                int high,
                SortStats *stats)
{
    int pivot = arr[high];

    int i = low - 1;
    int j;

    for(j = low; j < high; j++)
    {
        stats->comparisons++;

        if(arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            stats->swaps++;
        }
    }

    {
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        stats->swaps++;
    }

    return i + 1;
}

void quickSortRec(int arr[],
                  int low,
                  int high,
                  SortStats *stats)
{
    if(low < high)
    {
        int pi =
            partitionQS(arr,
                        low,
                        high,
                        stats);

        quickSortRec(arr,
                     low,
                     pi - 1,
                     stats);

        quickSortRec(arr,
                     pi + 1,
                     high,
                     stats);
    }
}

void quickSort(int arr[],
               int n,
               SortStats *stats)
{
    quickSortRec(arr,
                 0,
                 n - 1,
                 stats);
}
