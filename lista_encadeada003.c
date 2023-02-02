#include<stdio.h>
#include<stdlib.h>

typedef struct NO
{
    int valor ; 
    struct NO* proximo ; 
}NO ; 

NO* insertElement(NO* lista , int valor)
{
    NO* novoNo = (NO*)malloc(sizeof(NO)) ; 
    (*novoNo).valor = valor ; 
    (*novoNo).proximo = lista ; 
    return novoNo ; 
}

void imprime(NO *lista)
{
    NO *l ; 
    for(l = lista ; l!=NULL ; l = (*l).proximo)
        printf("%d " , (*l).valor) ; 
}

int main()
{

    NO* lista = NULL ; int op ; 
    ; 

    //INSERIR ELEMENTO NA LISTA 
    do
    {
        printf("1 - Inserir elemento\n2 - Imprimir Lista\n3 - Sair\n") ; 
        printf("ESCOLHA : ") ; 
        
        scanf("%d" , &op) ;
        switch(op)
        {
            case 1: 
                int x ; 
                printf("INSIRA UM ELEMENTO PARA COLOCAR NA LISTA : ") ; 
                scanf("%d" , &x) ; 
                lista = insertElement(lista , x) ; 
                printf("SUCESSO!\n\n") ; 
            break ; 
            
            case 2:
                imprime(lista) ; 
                printf("\n") ; 
            break ;

            case 5: 
            break ;  
        } 


    }while(op != 5) ; 


    return 0 ; 
}