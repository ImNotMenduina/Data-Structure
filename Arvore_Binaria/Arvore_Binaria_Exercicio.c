#include<stdio.h>
#include<stdlib.h>

struct no
{
    float info; 
    struct no* dir ; 
    struct no* esq ; 
} ; 
typedef struct no ARV ; 

ARV* criar_arvore_vazia()
{
    return NULL ; 
}

ARV* inserir_elemento(ARV* a , int k)
{
    if(a == NULL)
    {
        ARV* novo = (ARV*)malloc(sizeof(ARV)) ; 
        novo->info = k ; 
        novo->dir = NULL ; 
        novo->esq = NULL ; 
        return novo ; 
    }
    else if(k > a->info)
        a->dir = inserir_elemento(a->dir, k) ; 
    else 
        a->esq = inserir_elemento(a->esq , k) ; 
    return a ; 
}

ARV* buscar_elemento(ARV* a, int info)
{
    if(a == NULL)
        return NULL ;
    else if(info < a->info)
        return buscar_elemento(a->esq, info) ; 
    else if(info > a->info)
        return buscar_elemento(a->dir, info) ; 
    else
        return a ; 
}

ARV* imprime(ARV* a)
{
    if(a!=NULL)
    {
        imprime(a->esq) ; 
        printf("%f " , a->info) ; 
        imprime(a->dir) ; 
    }
}

int main()
{
    ARV* a = criar_arvore_vazia() ; 
    a = inserir_elemento(a , 9) ; 
            printf("%f " , a->info) ; 

    a = inserir_elemento(a, 12) ; 
    a = inserir_elemento(a , 3) ; 
    a = inserir_elemento(a , 7) ;
 
    
    ARV* fetch = buscar_elemento(a , 1) ; 
    if(fetch)
        printf("elemento encontrado") ; 
    else
        printf("NULL") ;

    printf("imprime : ") ; 
    imprime(a) ;  

    return 0 ; 
}
