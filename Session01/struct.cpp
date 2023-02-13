#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char name[100];     // 100
    double score[10];   // 80
    char studentId[15]; // 15
} budi;

int main (){
    Student kevin;
    int *p = (int*)malloc(10 * sizeof(int));
    // printf("%d\n", sizeof(kevin));
    // printf("%d\n", sizeof(long long int));
    p[0] = 10;
    *(p+1) = 17;
    printf("%d\n", p[1]);
    
    Student* pin = &kevin;
    pin = (Student*)malloc(sizeof(Student));
    strcpy(pin->name, "Davin");
    strcpy((*pin).name, "Davin");
    return 0;
}