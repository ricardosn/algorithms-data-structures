#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearchRecursive(int arr[], int l, int r, int x, bool DEBUG) {
    
    if(r >= l) {
        int m = l + r / 2;

        if(DEBUG) printf("R > M: %d - ARR[M]: %d - L: %d - R: %d \n", m, arr[m], l, r);

        if(arr[l]==x) return l;
        if(arr[r]==x) return r;
        if(arr[m]==x) return m;

        // Ignore right half
        if(arr[m] > x)
            return binarySearchRecursive(arr, l, m -1, x, DEBUG);
        
        // Ignore left half
        else
            return binarySearchRecursive(arr, m + 1, r, x, DEBUG);
    }

    return -1;
}

int binarySearchIterative(int arr[], int l, int r, int x, bool DEBUG) {
    while(l <= r) {
        int m = l + r / 2;
        if(DEBUG) printf("I > M: %d - ARR[M]: %d - L: %d - R: %d \n", m, arr[m], l, r);

        if(arr[l]==x) return l;
        if(arr[r]==x) return r;
        if(arr[m]==x) return m;

        // Ignore right half
        if(arr[m] > x)
            r = m - 1;
        
        // Ignore left half
        else
            l = m + 1;
        
    }
    // Not found
    return -1;
}

int main() {
    const bool DEBUG = true;
    
    int arr[] = {2, 3, 4, 10, 40, 41, 42, 43, 44, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    if(DEBUG) printf("%zu (size of ARR) / %zu (size of ARR first element) = %d (N)\n", sizeof(arr), sizeof(arr[0]), n);

    int resIterative = binarySearchIterative(arr, 0, n-1, x, DEBUG);

    int resRecursive = binarySearchRecursive(arr, 0, n-1, x, DEBUG);

    printf("Result: %d - %d", resIterative, resRecursive);

    return 0;

}