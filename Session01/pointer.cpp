#include <stdio.h>

int main(){
    int a = 10;
    int *p = &a;
    printf("%d %d %d\n", *p, p, &a);
    int arr[100];
    arr[0] = 13;
    arr[1] = 2;
    printf("%d %d %d\n", *arr, *(arr+1), &arr[1]);
    return 0;
}