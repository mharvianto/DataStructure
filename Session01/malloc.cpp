#include<stdio.h>
#include<stdlib.h>

int arr[1000000] = {};

int main () {
    getchar();
    int* a = (int*)malloc(500000000 * sizeof(int));
    for (int i = 0; i < 500000000; i++) {
        a[i] = 0;
    }
    getchar();
    a = (int*)calloc(500000000, sizeof(int));
    // a = (int*)malloc(500000000 * sizeof(int));
    for (int i = 0; i < 500000000; i++) {
        a[i] = 0;
    }
    getchar();
    a = (int*)realloc(a, 100000000 * sizeof(int));
    getchar();
    free(a);
    getchar();
    return 0;
}