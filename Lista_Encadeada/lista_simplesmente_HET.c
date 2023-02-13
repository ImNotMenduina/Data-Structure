/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno
{
    char nome[10] ; 
    float n1 , n2 , n3  ;
} ; 
struct professor
{
    char nome[10] ; 
    char disciplina[10] ; 
} ; 
typedef struct professor PROF ; 
typedef struct aluno ALUNO ; 

struct no
{
    int tipo ; 
    void* elemento ; 
    struct no* proximo ; 
} ; 
typedef struct no* LISTA ; 
typedef struct no NO ; 

LISTA* criar_lista()
{
    LISTA* lst = (LISTA*) malloc(sizeof(LISTA)) ; 
    if(lst)
        *lst = NULL ; 
    return lst ; 
}

void inserir_aluno(LISTA* lst)
{
    char nome[10]; 
    float n1,n2,n3 ; 

    printf("NOME ALUNO : ") ; 
    scanf("%s" , nome) ;

    printf("n1 : ") ; 
    scanf("%f" , &n1) ;

    printf("n2 : ") ; 
    scanf("%f" , &n2) ; 

    printf("n3 : ") ; 
    scanf("%f" , &n3) ; 

    ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO)) ;
    strcpy(aluno->nome , nome) ; 
    aluno->n1 = n1 ; 
    aluno->n2 = n2 ; 
    aluno->n3 = n3 ; 

    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    novo->elemento = (ALUNO*) aluno ; 
  
    novo->proximo = *lst ; 
    *lst = novo ; 
    
 
}

void print(LISTA* lst)
{
    NO* aux = *lst ; 
    ALUNO* al = aux->elemento ; 
    while(aux)
    {
        printf("%s \n" , al->nome) ; 
        aux = aux->proximo ; 
        if(aux)
            al = aux->elemento ; 
    }
}

int main()
{
    LISTA* lst = criar_lista() ; //* * lst 
    inserir_aluno(lst) ; 
    inserir_aluno(lst) ; 
    inserir_aluno(lst) ; 
    print(lst) ; 

    return 0 ; 
} */