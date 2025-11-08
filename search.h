#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>

// Error Messages
typedef enum {
    SUCESS = 0,
    ERROR_OPEN_FILE = 1,
    ERROR_EMPTY_FILE = 2,
    ERROR_ALLOCATION_FILE = 3,
    ERROR_INVALID_INPUT = 4
} ErrorCode;

int binarySearch(const int arr[], int numbersInFile, int target);
int* allocateIntArray(int size);

#endif
