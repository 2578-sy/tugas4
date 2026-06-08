#ifndef FILEIO_H
#define FILEIO_H

#define MAX_WORDS 100000
#define MAX_LENGTH 100

extern char words[MAX_WORDS][MAX_LENGTH];
extern char tempWords[MAX_WORDS][MAX_LENGTH];
extern int wordCount;

int loadFile(const char *filename);

#endif
