#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
    int info ; 
    struct no* prox ;  
}NO ; 

void listar(NO* lista) ;
NO* sortANDinsert(NO* lst , int info) ; 


int main()
{   
    NO *lista = NULL ; 
    int opt ; 
    do
    {
      printf("\nMENU-----\n1-Inserir\n2-Listar\n3-Remover\n5-Sair\n") ;
      scanf("%d" , &opt) ; 

      switch(opt)
      {
        case 1:
            int k ; 
            printf("inserir : ")  ;
            scanf("%d" , &k) ; 
            lista = sortANDinsert(lista , k) ; 
        break ; 
        
        case 2:
            listar(lista) ; 
        break ; 
        
        case 3: 

        break ; 

        case 5: 

        break ; 

        default : 
            printf("Insira uma opt valida") ; 
      }
    } while (opt != 5);
    

    return 0 ; 
}

NO* sortANDinsert(NO* lst , int info)
{           
            NO* novo ; 
            NO* p = lst ; 
            NO* before = NULL ; 

            while(p != NULL && p->info <= info )
            {
                before = p ; 
                p = p->prox ; 
            }
           
            novo = (NO*)malloc(sizeof(NO)) ; 

            (*novo).info = info ;

            if(before == NULL)
            {   
                (*novo).prox = lst ; 
                lst = novo ; 
            }
            else
            {
                (*novo).prox = (*before).prox ; 
                (*before).prox = novo ; 
            }
        
            return lst ; 
   
}

void listar(NO* lista)
{
    printf("\n") ;
    for(NO* k = lista ; k != NULL ; k = k->prox)
    {
        printf("%d ---> " , k->info) ; 
    } 
    printf("NULL\n") ; 
}

