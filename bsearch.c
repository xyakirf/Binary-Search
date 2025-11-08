#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_FILE 1
#define ERROR_EMPTY_FILE 2
#define ERROR_ALLOCATION_FILE 3
#define ERROR_NOT_FOUND 4

int biSearch(int arr[], int count, int target);

int main() {
    FILE *fp = fopen("abc.txt", "r");
    if(fp == NULL){
        printf("Error\n");
        return ERROR_OPEN_FILE;
    }

    int count = 0; // counts how many numbers in the file
    int temp;
    while(fscanf(fp, "%d",&temp) == 1)
        count++;

    if(count > 0){
        return ERR_EMPTY_FILE;
        }

    int* arr = malloc(count * sizeof(int));
    if (arr == NULL){
        printf("no sigma\n");
        return ERROR_ALLOCATION_FILE;
    }

    rewind(fp);
    for(int i = 0; i < count; i++){
        fscanf(fp, "%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int result = biSearch(arr, count, target);
    if (result == -1)
        printf("no sigma");
    else
        printf("target %d index %d\n" ,target ,result);

    free(arr);
    return 0;
}

int biSearch(const int arr[] , int count , int target){
    int low = 0 
    int high = count -1;

    while(low <= high){
        int mid = low + ((high - low) / 2);

        if(arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // if not found 
}