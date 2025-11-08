#include <stdio.h>
#include <stdlib.h>

int biSearch(int arr[], int count, int target);

int main(){
    FILE *fp = fopen("abc.txt", "r");
    if(fp == NULL){
        printf("Error\n");
        return 1;
    }

    int count = 0;
    int temp;
    while(fscanf(fp, "%d",&temp) == 1)
        count++;

    if(count == 0){
        printf("no sigma\n");
        return 1;
        }

    int *arr = malloc(count * sizeof(int));
    if (arr == NULL){
        printf("no sigma\n");
        return 1;
    }

    rewind(fp);
    for(int i = 0 ; i < count ; i++){
        fscanf(fp,"%d",&arr[i]);
    }

    int target;
    printf("target");
    scanf("%d", &target);

    int result = biSearch(arr,count,target);
    if (result == -1)
        printf("no sigma");
    else
        printf("target %d index %d\n" , target , result);

    free(arr);
    return 0;
}

int biSearch(int arr[] , int count , int target){
    int low = 0, high = count -1;

    while(low <= high){
        int mid = low + (high-low) /2;

        if(arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;

    }
    return -1;
}