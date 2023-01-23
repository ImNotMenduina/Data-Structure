#include<stdio.h>
#include<stdlib.h>


typedef struct NO 
{
    int valor ; 
    struct NO *proximo ; 
}NO ; 

typedef struct LISTA
{
    int tam ; 
    struct NO *inicio ; 
}LISTA ; 

void inserir_no_inicio(LISTA *lista , int valor)
{
    NO *novo_no = malloc(sizeof(NO)) ; 
    (*novo_no).valor = valor ; 
    (*novo_no).proximo = (*lista).inicio ; 
    
    (*lista).inicio = novo_no ; 
    (*lista).tam++ ; 
}

void imprime_lista(NO *K)
{
  if(K != NULL)
  {
    printf("%d - " , K->valor) ;
    imprime_lista(K->proximo) ; 
  }
  else
  {
    printf("\n") ; 
  }
}

int main()
{
    LISTA lista ; 
    //inicializar os atributos da lista 
    lista.tam = 0 ; 
    lista.inicio = 0 ;   

    int op , valor ; 
    do
    {
        printf("1 - inserir no inicio\n2 - Imprimir\n5 - Sair\n") ; 
        scanf("%d" , &op) ; 
        switch(op)
        {
            case 1:
                printf("Digite um valor : ") ; 
                scanf("%d" , &valor) ; 
                inserir_no_inicio(&lista , valor) ; 
                break ; 
            case 2: 
                imprime_lista(lista.inicio) ; 
                break ; 
            case 5: 
                printf("finalizando....") ; 
                break ; 
            default:
                printf("op nao valida") ; 
        }

    }while(op != 5) ; 
    

    return 0 ; 
}