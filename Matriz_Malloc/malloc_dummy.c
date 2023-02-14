#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **v = (int**)malloc(sizeof(int) * 5) ; 
    printf("%p" , v) ; 

    return 0 ; 
}