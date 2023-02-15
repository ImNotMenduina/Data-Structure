#include<stdio.h>
#include<stdlib.h>

struct no
{
    int numero ;
    struct no* prox ;
} ; 
typedef struct no NO ; 

struct pilha_ptr
{
    NO* topo ; 
} ; 
typedef struct pilha_ptr PILHA ; 

PILHA* create_stack()
{
    PILHA* stack = (PILHA*) malloc(sizeof(PILHA)) ; 
    stack->topo = NULL ; 
    return stack ;  
}

void push_to_stack(PILHA* stack)
{
    printf("NUMERO : ") ;
    int k ; 
    scanf("%d" , &k) ; 

    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    novo->numero = k ; 

    novo->prox = stack->topo ;
    stack->topo = novo ;  
}

void pop_from_stack(PILHA* stack)
{   
    if(stack == NULL || stack->topo == NULL) exit(100) ; 

    int sum = 0 ; 
    NO* aux = stack->topo ; 
    //NO* q = NULL ;

    while(aux != NULL)
    {
        stack->topo = aux->prox ;
        sum += aux->numero ; 
        free(aux) ; 
        aux = stack->topo ; 
    }
    free(stack) ; 

    printf("SOMA : %d\n"  , sum)  ; 
}

int main()
{   
    PILHA* stack = create_stack() ; 

    int op ; 

        do
        {
            printf("1.(I) 2.(D) 3.(P) 4.(PR) 0.(E)\n//> ") ;
            scanf("%d" , &op) ; 

            switch (op)
            {
            case 1:
                push_to_stack(stack) ; 
                break;
            case 2:
                //remove_info(lst) ;
                break ;
            case 3:
                pop_from_stack(stack) ; 
                break;
            case 4:
                //print_reverse(lst) ; 
                break ;  
            default:
                break;
            } 
        } while (op != 0);


    return 0 ; 
}