#include<stdio.h>
#include<stdlib.h>
struct no
{
    int info ; 
    struct no* proximo ; 
} ; 
typedef struct no* LISTA ; 
typedef struct no NO ; 

LISTA* cria_lista()
{
    LISTA* lst = (LISTA*) malloc(sizeof(LISTA)) ; 
    if(lst != NULL)
        *lst = NULL ; 
    return lst ; 
}

LISTA* inserir(LISTA* lst) 
{
    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    if(novo == NULL) exit(5) ; 
    int k ; 
    printf("insira o elelemto : ") ; 
    scanf("%d" , &k) ; 

    novo->info = k ; 

    if(*lst == NULL)
    {
        novo->proximo = *lst ; 
        *lst = novo ; 
    }
    else
    {
        NO* aux = *lst ; 
        NO* checkpoint = NULL ; 
        while(aux != NULL && aux->info < k)
        {
            checkpoint = aux ; 
            aux = aux->proximo ; 
        }
        if(aux == NULL)
        {
            checkpoint->proximo = novo ; 
            novo->proximo = NULL ; 
        }
        else if(aux == *lst)
        {
            novo->proximo = aux ; 
            *lst = novo ; 
        }
        else
        {
            novo->proximo = aux ; 
            checkpoint->proximo = novo ; 
        }
    }
    
}

void printar(LISTA* lst)
{
    NO* k = *lst ; 
    while(k!=NULL)
    {
        printf("%d " , k->info) ; 
        k = k->proximo ; 
    }
}

int main()
{
    LISTA* lst ;
    lst = cria_lista() ; 
    inserir(lst) ; 
    inserir(lst) ;
    inserir(lst) ; 
    inserir(lst) ; 
    printar(lst) ; 
    
 


//     printar(lst) ; 


    return 0 ; 
}