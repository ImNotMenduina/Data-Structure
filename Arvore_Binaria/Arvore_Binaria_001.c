#include<stdio.h>
#include<stdlib.h>
struct no
{
    int info ; 
    struct no* dir ; 
    struct no* esq ; 
} ; typedef struct no ARVORE ;

ARVORE* criar_arvore()
{
    return NULL ;    
}

ARVORE* inserir (ARVORE* a, int v)
{
if (a==NULL) {
    a = (ARVORE*)malloc(sizeof(ARVORE));
    a->info = v;
    a->esq = a->dir = NULL;
}
else if (v < a->info)
    a->esq = inserir(a->esq,v);
else /* v >= a->info */
    a->dir = inserir(a->dir,v);
printf("A : %d\n\n" , a->info) ; 
return a;
}

void imprime (ARVORE* a)
{
if (a != NULL) {
    imprime(a->esq);
    printf("%d\n",a->info);
    imprime(a->dir);
}
}

int main()
{
    ARVORE* a = criar_arvore() ; 
    a = inserir(a , 10) ;  
    a = inserir(a , 20) ; 
    a = inserir(a , 5) ;
    a = inserir(a , 15) ; 
    imprime(a) ; 

    return 0 ; 
}

//LUCAS MENDUIÑA aa