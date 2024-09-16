#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista {
    char nome[81];
    float nota;
    struct lista *prox;
};
typedef struct lista LISTA;

LISTA* create_list()
{
    return NULL ;
}

LISTA* create_student(LISTA* lst)
{
    char nome[81] ; 
    float nota ; 
    printf("ALUNO : ") ; 
    scanf("%s" , nome) ; 

    printf("MEDIA : ") ; 
    scanf("%f" , &nota) ;

    LISTA* novo = (LISTA*) malloc(sizeof(LISTA)) ; 
    strcpy(novo->nome , nome) ; 
    novo->nota = nota ; 
    novo->prox = lst ; 
    return novo ; 
    
}

void printt(LISTA* lst)
{
    LISTA* aux = lst ; 
    while(aux != NULL)
    {
        if(aux->nota < 5.0)
            printf("</ ALUNO : %s | NOTA : %.1f | STATUS : REPROVADO/> \n" , aux->nome , aux->nota) ; 
        else
            printf("</ ALUNO : %s | NOTA : %.1f | STATUS : APROVADO/> \n" , aux->nome , aux->nota) ; 

        aux = aux->prox ; 
    }
}

int main()
{
    LISTA* lst = create_list() ; 

    int op ; 

    do
    {
        printf("1.(I) 2.(D) 3.(P) 4.(PR) 0.(E)\n//> ") ;
        scanf("%d" , &op) ; 

        switch (op)
        {
        case 1:
            lst = create_student(lst) ; 
            break;
        case 2:
            //remove_info(lst) ;
            break ;
        case 3:
            printt(lst) ; 
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
