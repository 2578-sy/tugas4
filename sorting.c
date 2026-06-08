#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"
#include "fileio.h"
#include "utils.h"

/*=========================================================
  BUBBLE SORT
=========================================================*/
void bubbleSort(SortStats *s)
{
    int i, j;

    for(i = 0; i < wordCount - 1; i++)
    {
        int swapped = 0;

        for(j = 0; j < wordCount - i - 1; j++)
        {
            s->comparisons++;

            if(strcmp(tempWords[j],
                      tempWords[j + 1]) > 0)
            {
                swapString(tempWords[j],
                           tempWords[j + 1]);

                s->swaps++;
                swapped = 1;
            }
        }

        if(!swapped)
            break;
    }
}

/*=========================================================
  SELECTION SORT
=========================================================*/
void selectionSort(SortStats *s)
{
    int i, j;

    for(i = 0; i < wordCount - 1; i++)
    {
        int min = i;

        for(j = i + 1; j < wordCount; j++)
        {
            s->comparisons++;

            if(strcmp(tempWords[j],
                      tempWords[min]) < 0)
            {
                min = j;
            }
        }

        if(min != i)
        {
            swapString(tempWords[i],
                       tempWords[min]);

            s->swaps++;
        }
    }
}

/*=========================================================
  INSERTION SORT
=========================================================*/
void insertionSort(SortStats *s)
{
    int i;

    for(i = 1; i < wordCount; i++)
    {
        char key[MAX_LENGTH];

        strcpy(key, tempWords[i]);

        int j = i - 1;

        while(j >= 0)
        {
            s->comparisons++;

            if(strcmp(tempWords[j], key) > 0)
            {
                strcpy(tempWords[j + 1],
                       tempWords[j]);

                s->swaps++;
                j--;
            }
            else
            {
                break;
            }
        }

        strcpy(tempWords[j + 1], key);
    }
}

/*=========================================================
  MERGE SORT
=========================================================*/
static void merge(int left,
                  int mid,
                  int right,
                  SortStats *s)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char (*L)[MAX_LENGTH] =
        malloc(n1 * sizeof(*L));

    char (*R)[MAX_LENGTH] =
        malloc(n2 * sizeof(*R));

    if(L == NULL || R == NULL)
    {
        printf("Gagal mengalokasikan memori.\n");

        free(L);
        free(R);

        exit(1);
    }

    int i, j, k;

    for(i = 0; i < n1; i++)
        strcpy(L[i], tempWords[left + i]);

    for(i = 0; i < n2; i++)
        strcpy(R[i], tempWords[mid + 1 + i]);

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        s->comparisons++;

        if(strcmp(L[i], R[j]) <= 0)
        {
            strcpy(tempWords[k], L[i]);
            i++;
        }
        else
        {
            strcpy(tempWords[k], R[j]);
            j++;
        }

        s->swaps++;
        k++;
    }

    while(i < n1)
    {
        strcpy(tempWords[k], L[i]);

        i++;
        k++;

        s->swaps++;
    }

    while(j < n2)
    {
        strcpy(tempWords[k], R[j]);

        j++;
        k++;

        s->swaps++;
    }

    free(L);
    free(R);
}

static void mergeSortRec(int left,
                         int right,
                         SortStats *s)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRec(left, mid, s);
        mergeSortRec(mid + 1, right, s);

        merge(left, mid, right, s);
    }
}

void mergeSort(SortStats *s)
{
    mergeSortRec(0,
                 wordCount - 1,
                 s);
}

/*=========================================================
  QUICK SORT
=========================================================*/
static int partitionQS(int low,
                       int high,
                       SortStats *s)
{
    char pivot[MAX_LENGTH];

    strcpy(pivot, tempWords[high]);

    int i = low - 1;
    int j;

    for(j = low; j < high; j++)
    {
        s->comparisons++;

        if(strcmp(tempWords[j], pivot) < 0)
        {
            i++;

            swapString(tempWords[i],
                       tempWords[j]);

            s->swaps++;
        }
    }

    swapString(tempWords[i + 1],
               tempWords[high]);

    s->swaps++;

    return i + 1;
}

static void quickSortRec(int low,
                         int high,
                         SortStats *s)
{
    if(low < high)
    {
        int pi =
            partitionQS(low,
                        high,
                        s);

        quickSortRec(low,
                     pi - 1,
                     s);

        quickSortRec(pi + 1,
                     high,
                     s);
    }
}

void quickSort(SortStats *s)
{
    quickSortRec(0,
                 wordCount - 1,
                 s);
}
