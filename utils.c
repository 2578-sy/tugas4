#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void generateRandom(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        arr[i] = rand();
}

void copyArray(int source[], int destination[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        destination[i] = source[i];
}

void printArray(int arr[], int n)
{
    int i;

    if(n <= 100)
    {
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);

        printf("\n");
    }
    else
    {
        printf("10 data pertama:\n");

        for(i = 0; i < 10; i++)
            printf("%d ", arr[i]);

        printf("\n10 data terakhir:\n");

        for(i = n - 10; i < n; i++)
            printf("%d ", arr[i]);

        printf("\n");
    }
}
