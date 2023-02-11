#include<stdio.h>
#include<stdlib.h>
char c = 'A' ; 

struct no
{
    int valor ; 
    struct no* proximo ; 
   //struct no* anterior ; 
} ; 
typedef struct no NO ; 

struct fila
{
    NO* inicio ; 
    NO* fim ; 
} ; 
typedef struct fila FILA ; 

FILA* criar_fila()
{
    FILA* f = (FILA*) malloc(sizeof(FILA)) ; 
    f->inicio = NULL ; 
    f->fim = NULL ; 
    return f ; 
}

void push_to_queue(FILA* queue)
{
    int k ; 

    printf("%c = ", c) ;
    c+=1 ; 

    scanf("%d" , &k) ; 

    NO* novo = (NO*) malloc(sizeof(NO)) ; 
    novo->valor = k ; 
    if(queue->fim == NULL)
    {
        queue->inicio = novo ; 
    }
    else
    {
        queue->fim->proximo = novo ; 
    }

    queue->fim = novo ; 
    
}

void pop_from_queue(FILA* queue)
{
    NO* temp , *q ; 
    int sum = 0 ; 

    temp = queue->inicio ; 
    while(temp!=NULL)
    {
        sum += temp->valor ; 
        q = temp->proximo ; 
        free(temp) ; 
        temp = q ;         
    }
    printf("a soma foi de : %d\n\n" , sum) ; 
}

int main()
{   
    printf("\n\n--- somatorio com fila encadeada ---\n\n") ; 
    FILA* f = criar_fila() ; 

    push_to_queue(f) ; 

    push_to_queue(f) ; 

    push_to_queue(f) ; 

    push_to_queue(f) ; 

    pop_from_queue(f) ; 

    return 0 ; 
}