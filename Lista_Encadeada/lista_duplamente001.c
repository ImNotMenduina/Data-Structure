#include<stdio.h>
#include<stdlib.h>

struct lista 
{
    int info ; 
    struct lista* proximo ; 
    struct lista* anterior ; 
} ; 
typedef struct lista LISTA ; 

LISTA** create_list()
{
    LISTA** lst = (LISTA**) malloc(sizeof(LISTA*)) ; 
    if(lst != NULL)
        *lst = NULL ; 
    
    return lst ; 
}

void create_info(LISTA** lst)
{
    printf("insira o numero : ") ; 
    int k ; 
    scanf("%d" , &k) ; 

    LISTA* novo = (LISTA*)malloc(sizeof(LISTA)) ; 
    novo->info = k ; 

    if(*lst == NULL)
    {
        novo->proximo = *lst ; 
        novo->anterior = NULL ; 
    }
    else
    {
        novo->proximo = *lst ; 
        novo->anterior = NULL ; 
        (*lst)->anterior = novo ; 
    }
    *lst = novo ; 
}

void remove_info(LISTA** lst)
{
    if(*lst == NULL || lst == NULL) exit(100) ; 

    printf("insira o numero : ") ; 
    int k ; 
    scanf("%d" , &k) ; 

    LISTA* aux = *lst ;
    LISTA* checkpoint = NULL ;  
    while(aux && aux->info != k)
    {
        checkpoint = aux ; 
        aux = aux->proximo ; 
    }
    if(aux == NULL)
    {
        printf("elemento nao encontrado \n") ; 
    }
    else if(aux == *lst)
    {
        *lst = (*lst)->proximo ; 
        (*lst)->anterior = NULL ; 
        free(aux) ;
    }
    else
    {
        aux->anterior->proximo = aux->proximo ; 
        aux->proximo->anterior = aux->anterior ;
        free(aux) ; 
    }
}

void printt(LISTA** lst)
{
    if(*lst != NULL)
    {
        printf("</ Print />\n") ; 
        LISTA* aux = *lst ; 
        while(aux != NULL)
        {
            printf("%d " , aux->info) ; 
            aux = aux ->proximo ; 
        }
        printf("\n") ;

    }
    else
    {
        printf("</ Lista_Vazia />\n") ;
    } 
}

void print_reverse(LISTA** lst)
{
    if(*lst != NULL)
    {
        printf("</ Print_Reverse />\n") ; 
        LISTA* aux = *lst ; 
        while(aux->proximo != NULL)
        {
            aux = aux->proximo ; 
        }
        while(aux != NULL)
        {
            printf("%d " , aux->info) ; 
            aux = aux->anterior ; 
        }
        printf("\n") ; 
    }
    else
    {
        printf("</ Lista_Vazia />\n") ;
    }
}

int main()
{

    LISTA** lst = create_list() ; 

    int op ; 

    do
    {
        printf("1.(I) 2.(D) 3.(P) 4.(PR) 0.(E)\n//> ") ;
        scanf("%d" , &op) ; 

        switch (op)
        {
        case 1:
            create_info(lst) ; 
            break;
        case 2:
            remove_info(lst) ;
            break ;
        case 3:
            printt(lst) ; 
            break;
        case 4:
            print_reverse(lst) ; 
            break ;  
        default:
            break;
        } 
    } while (op != 0);
    

    return 0 ; 
}