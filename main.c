#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fileio.h"
#include "sorting.h"
#include "utils.h"

/*=========================================================
  Menjalankan satu metode sorting
=========================================================*/
void runSort(int choice)
{
    copyWords();

    SortStats s = {0, 0, 0};

    clock_t start = clock();

    switch(choice)
    {
        case 1:
            insertionSort(&s);
            break;

        case 2:
            bubbleSort(&s);
            break;

        case 3:
            selectionSort(&s);
            break;

        case 4:
            mergeSort(&s);
            break;

        case 5:
            quickSort(&s);
            break;
    }

    clock_t end = clock();

    s.timeUsed =
        (double)(end - start)
        / CLOCKS_PER_SEC;

    printWords();

    printf("\nPerbandingan : %lld\n",
           s.comparisons);

    printf("Pertukaran   : %lld\n",
           s.swaps);

    printf("Waktu        : %.6f detik\n",
           s.timeUsed);
}

/*=========================================================
  Membandingkan seluruh metode sorting
=========================================================*/
void compareAll(void)
{
    SortStats result[5];

    int i;

    for(i = 0; i < 5; i++)
    {
        result[i].comparisons = 0;
        result[i].swaps = 0;
        result[i].timeUsed = 0;
    }

    for(i = 1; i <= 5; i++)
    {
        copyWords();

        clock_t start = clock();

        switch(i)
        {
            case 1:
                insertionSort(&result[i - 1]);
                break;

            case 2:
                bubbleSort(&result[i - 1]);
                break;

            case 3:
                selectionSort(&result[i - 1]);
                break;

            case 4:
                mergeSort(&result[i - 1]);
                break;

            case 5:
                quickSort(&result[i - 1]);
                break;
        }

        clock_t end = clock();

        result[i - 1].timeUsed =
            (double)(end - start)
            / CLOCKS_PER_SEC;
    }

    const char *name[5] =
    {
        "Insertion",
        "Bubble",
        "Selection",
        "Merge",
        "Quick"
    };

    printf("\n==============================================================\n");
    printf("%-12s %-15s %-15s %-10s\n",
           "METODE",
           "COMPARE",
           "SWAP",
           "WAKTU");

    printf("==============================================================\n");

    for(i = 0; i < 5; i++)
    {
        printf("%-12s %-15lld %-15lld %.6f\n",
               name[i],
               result[i].comparisons,
               result[i].swaps,
               result[i].timeUsed);
    }

    printf("==============================================================\n");
}

/*=========================================================
  Main Program
=========================================================*/
int main(void)
{
    char filename[256];
    int menu;

    printf("Masukkan nama file: ");
    scanf("%255s", filename);

    if(loadFile(filename) == 0)
    {
        return 1;
    }

    if(wordCount == 0)
    {
        printf("File kosong.\n");
        return 1;
    }

    printf("Jumlah kata dibaca: %d\n",
           wordCount);

    do
    {
        printf("\n");
        printf("1. INSERTION SORT\n");
        printf("2. BUBBLE SORT\n");
        printf("3. SELECTION SORT\n");
        printf("4. MERGE SORT\n");
        printf("5. QUICK SORT\n");
        printf("6. BANDINGKAN SEMUA METODE\n");
        printf("7. SELESAI\n");

        printf("Pilihan: ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                runSort(menu);
                break;

            case 6:
                compareAll();
                break;

            case 7:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while(menu != 7);

    return 0;
}
