#include<stdio.h>
#include<stdlib.h>

struct no
{
    int numero ; 
    struct no* proximo ; 
} ; 
typedef struct no NO ; 

struct stack 
{
    NO* no_top ; 
} ; 
typedef struct stack STACK ; 

STACK* criar_pilha()
{
    STACK* pil = (STACK*) malloc(sizeof(STACK)) ; 
    if(pil != NULL)
        pil->no_top = NULL ; 
    return pil ; 
}

STACK* push(STACK* pil , int i)
{
    if(pil == NULL) exit(1) ; 
        if(i == 1 || i == 0)
        {
            return pil ; 
        }
        else
        {
            NO* novo = (NO*) malloc(sizeof(NO)) ; 
            novo->numero = i ; 
            novo->proximo = pil->no_top ; 
            pil->no_top = novo ; 
            return push(pil , --i) ; 
        }
}


int pop(STACK* pil)
{

    if(pil->no_top == NULL || pil == NULL) return -1 ; 

    int fatorial = 1.0 , k ; 
    NO* aux ; 
    while(pil->no_top != NULL)
    {
        aux = pil->no_top ; 
        pil->no_top = aux->proximo ; 
        k = aux->numero ; 
        free(aux) ; 
        fatorial = fatorial * k ;  
    }
    return fatorial ; 
}

int main()
{

    STACK* pilha = criar_pilha() ; 
    pilha = push(pilha , 6) ; 
    int FATORIAL = pop(pilha) ; 

    printf("</ Fatorial : %d />\n" , FATORIAL) ; 

    return 0 ;
}