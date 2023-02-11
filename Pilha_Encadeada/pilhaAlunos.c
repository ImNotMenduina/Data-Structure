#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno
{
    char* nome ; 
    int matricula ;
    float n1 ; 
    float n2 ;
    struct aluno* proximo ;  
} ; 
typedef struct aluno ALU_NO; 

struct stack
{
    ALU_NO* topo ; 
} ; 
typedef struct stack STACK ; 

STACK* cria_pilha(); 
void push_aluno(STACK* p) ; 
void pop_aluno(STACK* p) ; 
void pop_aluno(STACK* p);
void free_stack(STACK* p) ; 



int main()
{

STACK* stack = cria_pilha() ; 
int op ; 

do
{
    printf("1 - inserir aluno\n2 - calcular medias\n3 - (free) elementos\n0 - SAIR\n//>") ; 
    scanf("%d" , &op) ; 

    switch (op)
    {
    case 1:
        push_aluno(stack) ; 
        printf("---aluno inserido---\n") ; 

        break;
    case 2: 
            pop_aluno(stack) ; 
        break ;    
    case 3: 
        free_stack(stack) ; 
        break ;  
    case 0: 

        break ; 

    default:
        printf("insira um op valido\n\n") ; 
        break;
    }
} while (op != 0);


}

STACK* cria_pilha()
{
    STACK* novo = (STACK*) malloc(sizeof(STACK)) ; 
    novo->topo = NULL ; 
    return novo ; 
}

void push_aluno(STACK* p)
{
    ALU_NO* aluno = (ALU_NO*) malloc(sizeof(ALU_NO)) ; 
    char nome[40] ; 
    int tam = 0 ; 

    printf("insira o nome do aluno : ") ; 
    scanf(" %[^\n]" , nome) ;

    for(int i = 0 ; nome[i]!='\0' ; i++)
    {
        tam++ ; 
    }  

    aluno->nome = (char*) malloc(sizeof(nome)) ; 
    strcpy(aluno->nome , nome) ; 

    printf("insira a matricula : ") ; 
    scanf("%d" , &(aluno->matricula)) ; 

    printf("N1 : ") ; 
    scanf("%f" , &(aluno->n1)) ; 

    printf("N2 : ") ; 
    scanf("%f" , &(aluno->n2)) ; 

    aluno->proximo = p->topo ;
    p->topo = aluno ;  
}


void pop_aluno(STACK* p)
{ 
    if(p->topo != NULL)
    { 
        ALU_NO* temp ; 
        for(temp = p->topo ; temp!=NULL ; temp = temp->proximo)
        {
            p->topo = temp->proximo ; 
            float media = (temp->n1 + temp->n2)/2 ; 

            printf("ALUNO : %15s\n" , temp->nome) ; 
            printf("MATRICULA : %15d\n" , temp->matricula) ; 
            printf("MEDIA : %15f\n" , media) ; 
            printf("\n\n") ; 
            free(temp);  
        }
    }

    else
    {
        printf("\n\n----nao ha alunos na pilha----\n\n") ; 
    }

}

void free_stack(STACK* p)
{
    ALU_NO* temp = p->topo ; 
    ALU_NO* aux ; 

    while(temp != NULL)
    {
        aux = temp->proximo ; 
        free(temp) ; 
        temp = aux ; 
    }
    p->topo = temp ; 
}