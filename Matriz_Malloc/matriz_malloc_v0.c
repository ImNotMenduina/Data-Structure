#include<stdio.h>
#include<stdlib.h>
#define LIN 5
#define COL 5
int main()
{
    int* a ; 
    a = (int*) malloc(sizeof(int)*COL*LIN) ; 

    for(int i=0 ; i<LIN ; i++)
    {
        for(int j=0 ; j<COL ; j++)
        {
            a[i*COL + j] = 5 ;  
        }
    }

    for(int i=0 ; i<LIN ; i++)
    {
        for(int j=0 ; j<COL ; j++)
        {
            printf("%d " , a[i*COL + j]) ; 
        }
        printf("\n") ; 
    }

    return 0 ; 
}