#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int min_idx;

    for(int i = 0; i < n-1; i++) {
        min_idx = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d - %d \n", i, arr[i]);
    }
}

int main() {

    int arr[] = {5,74,85,41,7,2,4,1};
    int n = sizeof(arr) / sizeof(arr[0]); 

    selectionSort(arr, n);
    
    printArray(arr, n);
    
    return 0;
    
}