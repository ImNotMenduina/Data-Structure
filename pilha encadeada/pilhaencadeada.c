#include<stdio.h>
#include<stdlib.h>
#define MALLOC(x) ((x*) malloc(sizeof(x)))

struct caractere
{
    char letra ; 
    struct caractere* proximo ; 
} ; 
typedef struct caractere NO ; 

struct stack 
{
    NO* top ; 
} ; 
typedef struct stack PILHA ; 

void pilha_libera(PILHA* stack);
int verifica_exp(char* e , PILHA* stack);
int pop_from_stack(PILHA* stack);
int feicho(char c);
void push_to_stack(char c , PILHA* stack);
PILHA* pilha_cria (void);

int main()
{
    PILHA* p ; 
    p = pilha_cria() ; 

    int op ; 

    do
    {
        printf("1 - Inserir expressao\n2 - Sair\n//> ") ;
        scanf("%d" , &op) ; 

        switch(op)
        {
            case 1:
                char e[30] ; int error ;  
                printf("insira a expressao : ") ; 
                scanf(" %[^\n]" , e) ; 
                error = verifica_exp(e , p) ; 
                
                if(error == 0)
                    printf("ha algum erro na expressao\n\n") ; 
                else
                    printf("PERFEITO!\n\n") ; 
            break ; 

            case 2:

            break ; 
        } 
    }while(op != 2) ; 
    

    return 0 ; 
}

int verifica_exp(char* e , PILHA* stack)
{
    int error ; 
    for(int i=0 ; e[i]!='\0' ; i++)
    {
        if(e[i] == '(' || e[i] == '{' || e[i] == '[')
        {
            printf("abre : %c \n" , e[i]) ; 

            push_to_stack(e[i] , stack) ; 
        }
        else if(e[i] == ')' || e[i] == '}' || e[i] == ']')
        {
            printf("abre : %c \n" , e[i]) ;

            if(pop_from_stack(stack)!= feicho(e[i])) return 0 ; 
            
        }
    }
    return 1 ; 
}

void push_to_stack(char c , PILHA* stack)
{
    NO* novo = MALLOC(NO) ; 
    novo->letra = c ; 
    novo->proximo = stack->top ; 
    stack->top = novo ; 
}

int pop_from_stack(PILHA* stack)
{
    NO* temp ; 
    char c ;  
    temp = stack->top ; 
    c = temp->letra ; 
    stack->top = temp->proximo ; 
    free(temp) ;
    printf("TO DENTRO DO POP ---- LETRA %c\n" , c) ;  
    return c ; 
}

int feicho(char c)
{
    if(c == ')') return '(' ; 
    if(c == '}') return '{' ; 
    if(c == ']') return '[' ; 
}
void pilha_libera(PILHA* stack)
{
    NO* t ; 
    NO* q = stack->top ; 
    while(q != NULL)
    {
        t = q->proximo ; 
        free(q) ; 
        q = t ; 
    }
    free(stack) ; 
}

PILHA* pilha_cria (void)
{
PILHA* p = MALLOC(PILHA);
p->top = NULL;
return p;
}