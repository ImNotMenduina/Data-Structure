#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista {
   //char nome[81];
    float nota;
    //struct lista *prox;
};
typedef struct lista LISTA;

/* int aprovados (LISTA** l)
{
    int count = 0 ; 
    while(*l != NULL)
    {
        if((*l)->nota < 5.0)
            printf("%s | STATUS:REPROVADO | NOTA:%.1f \n" , (*l)->nome , (*l)->nota) ;
        else
            printf("%s | STATUS:APROVADO | NOTA:%.1f \n" , (*l)->nome , (*l)->nota) ;
 
    *l = (*l)->prox ; 
    } 
} 
*/
LISTA** criar_lista()
{
    LISTA** lst = malloc(sizeof(LISTA*)) ;
    *lst = malloc(sizeof(LISTA)) ; 
    (**lst).nota = 1.0 ; 
    printf("%f" , (**lst).nota) ; 
    float x ; 
    
    /* printf("%f" , (*(*lst)).nota ) ;  */
   /*  if(lst != NULL)
        *lst = NULL ; 
    return lst ; */ 
}
/* 
void inserir(LISTA** lst)
{
    char nome[81] ; 
    float nota ; 

    printf("Insira o nome : ") ; 
    scanf(" %[^\n]" , nome) ; 

    printf("Insira a nota : ") ; 
    scanf("%f" , &nota) ; 

    LISTA* novo = (LISTA*) malloc(sizeof(LISTA)) ; 
    strcpy(novo->nome , nome) ; 
    novo->nota = nota ; 
    novo->prox = *lst ; 
    *lst = novo ; 
}
 */
int main()
{
    /* LISTA** lst =  */
    
    criar_lista() ; 

   

   /*  inserir(lst) ; 
    inserir(lst) ;
    aprovados(lst) ;  */

    /* int x = 10 ; 
    int *y = &x ; 
    int **z = &y ; 
    printf("%p" , *z) ;
    printf("%p" , &x) ;  
    printf("\n") ;  */

    return 0 ; 
}