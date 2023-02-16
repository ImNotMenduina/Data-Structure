#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct no
{
    int num ; 
    struct no* prox ; 
} ; 
typedef struct no NO ; 

struct pil
{
    NO* topo ; 
} ; 
typedef struct pil Pilha ; 

struct calc
{
    char f[21] ; 
    Pilha* p ; 
} ; 
typedef struct calc CALC ; 

void operando(Pilha* stack , int i) ; 
int operador(Pilha* stack , char op) ; 
Pilha* criar_pilha() ; 
void calcula() ; 


int main()
{

    calcula(); 

    return 0; 
}

Pilha* criar_pilha()
{
    Pilha* stack = (Pilha*) malloc(sizeof(Pilha)) ; 
    if(stack == NULL ) exit(1) ; 
        stack->topo = NULL ; 
    return stack ; 
}

void calcula()
{
    printf("insira a expressao:  ") ; 
    char exp[21] ; 
    scanf("%s" , exp) ; 

    CALC calculadora ; 
    strcpy(calculadora.f , exp) ; 
    calculadora.p = criar_pilha() ;
    int result ; 
    for(int i=0 ; calculadora.f[i]!='\0' ; i++)
    {
        if(calculadora.f[i] == '+' || calculadora.f[i] == '-' || 
            calculadora.f[i] == '*' || calculadora.f[i] == '/')
        {
            result = operador(calculadora.p , calculadora.f[i]) ; 
            operando(calculadora.p , result) ; 
        }
        else
        {
            int k = (1-'1') + calculadora.f[i] ; 
            operando(calculadora.p , k) ; 
        }
    }

    printf("</ resposta : %d /> \n\n" , result) ;
}

void operando(Pilha* stack , int i)
{
    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    if(novo == NULL) exit(1) ; 

    novo->num = i ; 
    novo->prox = stack->topo ; 
    stack->topo = novo ; 
}

int operador(Pilha* stack , char op)
{
    NO* aux = stack->topo ; 
    stack->topo = aux->prox ; 

    int a = aux->num ; 
    aux = stack->topo ; 
    stack->topo = aux->prox ; 
    int b = aux->num ; 
    free(aux) ; 

    if(op == '+')
        return a+b ; 
    if(op == '-')
        return a-b ;
    if(op == '*')
        return a*b ; 
    if(op == '/') 
        return a/b ; 
}