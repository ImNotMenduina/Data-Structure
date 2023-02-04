#include<stdio.h>
#include<stdlib.h>
typedef struct no
{
    int valor ; 
    struct no* prox ; 
}NO ; 


void busca(NO* lista , int valor) ; 
NO* DELETAR(NO* lista , int valor) ; 
NO* insert(NO* lista , int valor) ; 
void imprime(NO* lista) ; 


int main()
{
    NO *lista = NULL; 
    lista = insert(lista , 29) ;    
    lista = insert(lista , 11) ;  
    lista = insert(lista , 22) ;  
    lista = insert(lista , 33) ;   

    busca(lista ,11) ; 
    lista = DELETAR(lista ,33) ;    
    imprime(lista) ; 

    return 0 ; 
}

void busca(NO* lista , int valor)
{
    NO* k = lista; 
    
    while(k->valor != valor)
    {
       k = k->prox ; 
       if(k == NULL)
            break ;  
    }

    if(k == NULL)
    {
        printf("elemento nao encontrado") ; 
    }
    else
    {
        printf("\n\nelemento encontrado!") ; 
    }
}


NO* insert(NO* lista , int valor)
{
    NO* novo = (NO*)malloc(sizeof(NO)) ; 
    (*novo).valor = valor ; 
    (*novo).prox = lista ; 
    return novo ; 
}
void imprime(NO* lista)
{   
   
        NO* ponteiro = lista ;
        printf("\n\nIMPRIME LISTA : ") ;  
        while(ponteiro != NULL)
        {
            printf("%d-" , ponteiro->valor) ;
            ponteiro = ponteiro->prox ;  
        }
        printf("\n\n") ; 
        
}


NO* DELETAR(NO* lista , int valor)
{
    NO* anterior = NULL ; 
    NO* ponteiro = lista ; 
    
    while(ponteiro!=NULL && ponteiro->valor!=valor)
    {
        anterior = ponteiro ; 
        ponteiro = ponteiro->prox ; 
    }

    if(ponteiro == NULL)
        printf("\nelemento nao encontrado\n") ;
    if(anterior == NULL)
    {
        lista = ponteiro->prox ; 
        printf("\nelemento removido do inicio !\n") ; 
    } 
   
    return lista ; 
}