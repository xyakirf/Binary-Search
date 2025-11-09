#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return ERROR_INVALID_INPUT;
    }

    const char *type = "r";
    FILE* fp = fopen(argv[1], type);
    if (fp == NULL) {
        return ERROR_OPEN_FILE;
    }

    int integerCountInFile = 0; 
    int temp;
    while (fscanf(fp, "%d", &temp) == 1) {
        integerCountInFile++;
    }

    if (integerCountInFile <= 0) {
        fclose(fp);
        return ERROR_EMPTY_FILE;
    }

    int* arr = allocateArray(integerCountInFile, sizeof(int));
    if (arr == NULL) {
        fclose(fp);
        return ERROR_ALLOCATION_FILE;
    }

    rewind(fp);

    for (int i = 0; i < integerCountInFile; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            free(arr);
            fclose(fp);
            return ERROR_INVALID_INPUT;
        }
    }

    int result = binarySearch(arr, integerCountInFile, atoi(argv[2]));
    if (result == -1) {
        printf("no sigma\n");
    } else {
        printf("target %d index %d\n", atoi(argv[2]), result);
    }

    free(arr);
    fclose(fp); 

    return SUCCESS;
}

int binarySearch(const int arr[], int integerCountInFile, int target) {
    int low = 0;
    int high = integerCountInFile - 1;
    int mid;

    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void* allocateArray(int size, size_t sizeType) {
    void* arr = malloc(size * sizeType);
    if (!arr) {
        return NULL;
    }
    return arr;
}
