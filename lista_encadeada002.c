#include<stdio.h>
#include<stdlib.h> 

typedef struct lista
{
    int valor ; 
    struct lista *proximo ; 
}lista ; 

lista* cria_lista()
{
        return (NULL) ;
} 

lista* inserir(lista* lst , int valor)
{
    //agora vou criar um novo no da lista
    lista* no = (lista*) malloc(sizeof(lista)) ; 
    (*no).valor = valor ; 
    (*no).proximo = lst ; 
    return no ; 
}

void imprime(lista* lst )
{
    lista* p ; 
    for(p = lst ; p != NULL ; p = (*p).proximo)
        printf("[%d]" , (*p).valor) ; 
}

int main()
{
    lista* mylist ; 
    mylist = cria_lista() ; 

    int op ; 
    do
    {
        printf("1 - Inserir elemento\n2 - Imprimir\n5 - Sair\nESCOLHA : ") ; 
        scanf("%d" , &op) ;

        switch(op)
        {
            case 1: 
                int x ; 
                printf("Insira o elemento : ") ; 
                scanf("%d" , &x) ; 

                mylist = inserir(mylist , x) ; 
                break ; 
            case 2: 
                imprime(mylist) ;
                printf("\n") ;  
                break ; 
            case 5: 
                break ; 
            default:
                printf("senha invalida") ; 
        } 
    } while (op != 5);
    
    
    imprime(mylist) ; 


    return 0 ; 
}