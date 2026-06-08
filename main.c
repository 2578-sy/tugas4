#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"
#include "utils.h"

void runSort(int original[],
             int n,
             int choice)
{
    int *arr =
        (int*)malloc(n * sizeof(int));

    copyArray(original, arr, n);

    SortStats stats = {0, 0};

    clock_t start = clock();

    switch(choice)
    {
        case 1:
            insertionSort(arr, n, &stats);
            break;

        case 2:
            bubbleSort(arr, n, &stats);
            break;

        case 3:
            selectionSort(arr, n, &stats);
            break;

        case 4:
            mergeSort(arr, n, &stats);
            break;

        case 5:
            quickSort(arr, n, &stats);
            break;
    }

    clock_t end = clock();

    double elapsed =
        (double)(end - start)
        / CLOCKS_PER_SEC;

    printArray(arr, n);

    printf("\nPerbandingan : %lld\n",
           stats.comparisons);

    printf("Pertukaran   : %lld\n",
           stats.swaps);

    printf("Waktu        : %.6f detik\n",
           elapsed);

    free(arr);
}

int main()
{
    srand(time(NULL));

    int n;
    int pilihan;

    printf("Masukkan Jumlah Bilangan (n): ");
    scanf("%d", &n);

    int *data =
        (int*)malloc(n * sizeof(int));

    generateRandom(data, n);

    printf("Random data selesai\n");

    do
    {
        printf("\n");
printf("1. INSERTION SORT\n");
printf("2. BUBBLE SORT\n");
printf("3. SELECTION SORT\n");
printf("4. MERGE SORT\n");
printf("5. QUICK SORT\n");
printf("6. BANDINGKAN SEMUA METODE\n");
printf("7. RANDOM ULANG DATA\n");
printf("8. SELESAI\n");

printf("Pilihan: ");
scanf("%d", &pilihan);

switch(pilihan)
{
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        runSort(data, n, pilihan);
        break;

    case 6:
        compareAllSorts(data, n);
        break;

    case 7:

        free(data);

        printf("Masukkan Jumlah Bilangan (n): ");
        scanf("%d", &n);

        data =
            (int *)malloc(n * sizeof(int));

        generateRandom(data, n);

        printf("Random ulang selesai.\n");
        break;

    case 8:
        printf("Program selesai.\n");
        break;

    default:
        printf("Pilihan tidak valid.\n");
}

    while(pilihan != 8);

    free(data);

    return 0;
}

void compareAllSorts(int original[], int n)
{
    const char *names[5] =
    {
        "Insertion",
        "Bubble",
        "Selection",
        "Merge",
        "Quick"
    };

    int method;

    printf("\n==============================================================\n");
    printf("%-12s %-15s %-15s %-10s\n",
           "METODE",
           "COMPARE",
           "SWAP",
           "WAKTU(s)");
    printf("==============================================================\n");

    for(method = 1; method <= 5; method++)
    {
        int *arr =
            (int *)malloc(n * sizeof(int));

        copyArray(original, arr, n);

        SortStats stats = {0, 0};

        clock_t start = clock();

        switch(method)
        {
            case 1:
                insertionSort(arr, n, &stats);
                break;

            case 2:
                bubbleSort(arr, n, &stats);
                break;

            case 3:
                selectionSort(arr, n, &stats);
                break;

            case 4:
                mergeSort(arr, n, &stats);
                break;

            case 5:
                quickSort(arr, n, &stats);
                break;
        }

        clock_t end = clock();

        double elapsed =
            (double)(end - start)
            / CLOCKS_PER_SEC;

        printf("%-12s %-15lld %-15lld %.6f\n",
               names[method - 1],
               stats.comparisons,
               stats.swaps,
               elapsed);

        free(arr);
    }

    printf("==============================================================\n");
}
