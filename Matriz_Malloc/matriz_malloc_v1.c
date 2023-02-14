#include<stdio.h>
#include<stdlib.h>
#define LIN 5
#define COL 5


/* struct lista {
    char nome[81];
    float nota;
    struct lista *prox;
};
typedef struct lista LISTA; */

int main()
{
    int** m = (int**) malloc(sizeof(int*)*LIN) ;
    

/*     int a = sizeof(LISTA) ; 
    int b = sizeof(LISTA*) ; 
    int x = sizeof(int) ; 
    int y = sizeof(int**) ; 
    printf("sizeof(int) - %d\nsizeof(int*) - %d\nLISTA - %d\nLISTA* - %d\n" , x , y , a , b) ;  */

    for(int i=0 ; i<LIN ; i++)
    {
        *(m + i) = (int*)malloc(sizeof(int)*COL) ; 
        if(*m == NULL) exit(100) ; 
    }

    for(int i=0 ; i<LIN ; i++)
    {
        for(int j=0 ; j<COL ; j++)
        {
            if(i==0 && j==0)
                m[i][j] = 9 ; 
            else
                m[i][j] = 5 ; 
        }
    }

    printf("%d\n\n" , **m) ; 

    for(int i=0 ; i<LIN ; i++)
    {
        for(int j=0 ; j<COL  ; j++)
        {
            
            printf("%d " , m[i][j]) ; 
        }
        printf("\n") ; 
    }
    
    
    return 0 ; 
}