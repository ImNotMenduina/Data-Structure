#include<stdio.h>
#include<stdlib.h>

struct no
{
    int info ; 
    struct no* proximo ; 
} ; 
typedef struct no* LISTA ; 
typedef struct no NO ; 

LISTA* criar()
{
    LISTA* lst = (LISTA*) malloc(sizeof(LISTA)) ; 
    if(lst)
        *lst = NULL ;
}

//inserir inicio
void inserir(LISTA* lst)
{
    int info ; 
    printf("//> ") ; 
    scanf("%d" , &info) ; 

    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    novo->info = info ; 

    if(*lst == NULL)
    {   
        *lst = novo ;
        novo->proximo = novo ; 
    }
    else
    {
        NO* aux = *lst ; 
        while(aux->proximo != *lst)
            aux = aux->proximo ; 

        aux->proximo = novo ; 
        novo->proximo = *lst ; 
        *lst = novo ; 
    }
    
}

void inserir_final(LISTA* lst)
{   
    
    if(lst == NULL) exit(100) ; 

    printf("< INSERIR FINAL //> ") ; 
    int info ; 
    printf("//> ") ; 
    scanf("%d" , &info) ; 

    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    novo->info = info ; 

    NO* aux = *lst ; 

    if(*lst == NULL)
    {
        novo->proximo = novo ; 
        *lst = novo ; 
    }
    else
    {
        while(aux->proximo != *lst)
            aux = aux->proximo ; 

        aux->proximo = novo ; 
        novo->proximo = *lst ; 
    }
}

void buscar(LISTA* lst , int info)
{   
    if(*lst != NULL)
     {  
        NO* aux = *lst ; 
        
            while(aux->proximo != *lst && aux->info != info)
                aux = aux->proximo ; 

                if(aux -> info == info) 
                    printf("< Elemento Encontrado //> %d \n" , aux->info ); 
                else
                    printf("< Elemento nao encontrado //> \n");  
    }
    else
    {
        printf("< Lista Vazia //> \n") ; 
    }
}


void remover(LISTA* lst)
{
        int op ;
        printf("1 - REMOVER ELEMENTO\n2 - LIBERAR LISTA\n") ;  
        printf("//> ") ; 
        scanf("%d" , &op) ;

        if(op == 1)
        {       
                if(lst == NULL) exit(1) ; 

                NO* aux, *checkpoint ; 

                int info ; 
                printf("//> ") ; 
                scanf("%d" , &info) ; 
                
                aux = *lst ; 

                
                while(aux->proximo != *lst && aux->info != info)
                {
                    checkpoint = aux ; 
                    aux = aux->proximo ; 
                }

                if(aux == NULL)
                {
                    printf("NOT FOUND \n\n") ; 
                }
                else if(aux == *lst)
                {
                    *lst = aux->proximo ; 
                    free(aux) ; 
                }
                else
                {
                    checkpoint->proximo = aux->proximo ; 
                    free(aux) ; 
                }
        } 
        else if(op == 2)
        {
                if(*lst == NULL) exit(100) ; 
                NO* aux = *lst ; 
                NO* k = NULL ;

                do{
                    k = aux->proximo ; 
                    free(aux) ; 
                    aux = k ; 
                }while(aux != *lst) ; 

                *lst = NULL ; 
        }
}

void imprime_lista(LISTA* lst)
{   
    if(*lst == NULL) exit(100) ; 

    printf("< LISTA CIRCULAR ---//> ") ; 
    NO* aux = *lst ; 
    do{
        printf("%d " , aux->info) ; 
        aux = aux->proximo ; 
        
    }while(aux != *lst) ; 

    printf("\n") ; 
}

int main()
{   
    LISTA* lst = criar() ; 
    /* inserir(lst) ; 
    inserir(lst) ;  */
    inserir(lst) ;  
    inserir(lst) ;
    imprime_lista(lst) ;  
    buscar(lst , 10) ; 
    remover(lst) ;
    imprime_lista(lst) ; 
    inserir_final(lst) ;  
    inserir_final(lst) ;  
    imprime_lista(lst) ; 


    return 0 ; 
}