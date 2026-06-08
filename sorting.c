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
