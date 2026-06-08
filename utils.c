#include <stdio.h>
#include <string.h>

#include "fileio.h"
#include "utils.h"

void copyWords(void)
{
    int i;

    for(i=0;i<wordCount;i++)
        strcpy(tempWords[i],words[i]);
}

void swapString(char a[],
                char b[])
{
    char temp[MAX_LENGTH];

    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

void printWords(void)
{
    int i;

    if(wordCount <= 100)
    {
        for(i=0;i<wordCount;i++)
            printf("%s\n",
                   tempWords[i]);
    }
    else
    {
        printf("\n10 kata pertama:\n");

        for(i=0;i<10;i++)
            printf("%s\n",
                   tempWords[i]);

        printf("\n10 kata terakhir:\n");

        for(i=wordCount-10;
            i<wordCount;
            i++)
        {
            printf("%s\n",
                   tempWords[i]);
        }
    }
}
