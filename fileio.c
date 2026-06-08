#include <stdio.h>
#include "fileio.h"

char words[MAX_WORDS][MAX_LENGTH];
char tempWords[MAX_WORDS][MAX_LENGTH];
int wordCount = 0;

int loadFile(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Gagal membuka file %s\n",
               filename);
        return 0;
    }

    wordCount = 0;

    while(fscanf(fp,"%99s",
                 words[wordCount]) == 1)
    {
        wordCount++;

        if(wordCount >= MAX_WORDS)
            break;
    }

    fclose(fp);

    return wordCount;
}
