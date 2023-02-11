#include<stdio.h>
#include<string.h>
#define TAM 100

struct contato {
    char nome[81];
    float telefone;
};
typedef struct contato Contato;

void insert(Contato* AGENDA , Contato CONTATO , int* elements) ; 
void delete(Contato* AGENDA , int indice , int* elements) ; 
Contato* shiftRightoInsert(Contato* AGENDA , int* elements , int i) ; 
int busca_binaria(Contato* AGENDA , char* nome , int init , int fim) ; 
void imprimir(Contato* AGENDA , int* elements) ; 
void toLower(char* p) ; 


int main()
{
    Contato AGENDA[TAM] ;
    int opt ; 
    int elements = 0 , fim ;     
    do
    {
        printf("1 - Inserir Contato\n2 - Imprimir Agenda\n3 - Buscar Contato\n4 - Apagar Contato\n5 - Sair\n") ; 
        printf("// : ") ;
        scanf("%d" , &opt) ; 

        char nome[81] , k , inicio = 0 ;
        switch(opt)
        {
            case 1: 
                Contato CONTATO ; 
                scanf(" %[^\n]" , CONTATO.nome) ; 
                scanf("%f" , &CONTATO.telefone) ; 
                fim = elements ; 
                toLower(CONTATO.nome) ;  
                insert(AGENDA , CONTATO , &elements) ;
                
            break ; 

            case 2:
                imprimir(AGENDA , &elements) ; 
            break ; 

            case 3: 
        
                printf("Insira o nome para busca : ") ;
                scanf(" %[^\n]" , nome) ; 
                toLower(nome) ; 

                k = busca_binaria(AGENDA , nome , inicio , elements) ; 
                if(k >= 0)
                {   
                    printf("CONTATO : \n") ; 
                    printf("====================================\n\n")  ; 
                    printf("Nome : %s\n" , AGENDA[k].nome) ; 
                    printf("Telefone : %f\n\n" , AGENDA[k].telefone) ; 
                    printf("====================================\n\n")  ; 
                }
                else
                {
                    printf("====================================\n\n")  ; 
                    printf("----------CONTATO NOT FOUND---------\n\n") ; 
                    printf("====================================\n\n")  ; 
                }
                break ; 

                case 4:
                    
                    printf("Insira o nome para busca : ") ;
                    scanf(" %[^\n]" , nome) ; 
                    toLower(nome) ; 

                   
                    k = busca_binaria(AGENDA , nome , inicio , elements) ; 

                    if(k >= 0)
                    {
                        delete(AGENDA , k , &elements) ;
                        printf("CONTATO APAGADO COM SUCESSO !") ;  
                        imprimir(AGENDA , &elements) ; 
                        
                    } 
                    else
                    {
                        printf("CONTATO NOT FOUND\n\n") ; 
                    }

                break ; 
                
                case 5:
                break ;

                default:
                    printf("Insira uma opcao valida\n") ;  
                break ; 
        }
    } while (opt != 5); 
 

    return 0 ; 
}

void toLower(char* p)
{
    if(p[0] >= 'a' && p[0] <= 'z')
    {
       p[0] = ('A' - 'a') + p[0] ; 
    }   
}
void delete(Contato* AGENDA , int indice , int* elements)
{
     
    for(int i = indice ; i < *elements ; i++)
    {
        AGENDA[i] = AGENDA[i+1] ; 
    }
    *elements -= 1 ;
    
}

void insert(Contato* AGENDA , Contato CONTATO , int* elements)
{
    if(*elements > 0 && *elements != 100)
    {
        int i = 0 ; 
        while(strcmp(AGENDA[i].nome , CONTATO.nome) < 0 && i < *elements)
        {
            i++ ; 
        }
        AGENDA = shiftRightoInsert(AGENDA , elements , i) ; 
        AGENDA[i] = CONTATO ; 
        *elements += 1 ; 
    }
    else 
    {
        AGENDA[0] = CONTATO ; 
        *elements += 1 ; 
    }
    
}

Contato* shiftRightoInsert(Contato* AGENDA , int* elements , int i)
{
    for(int k = *elements ; k > i ; k--)
        {
            AGENDA[k] = AGENDA[k-1] ; 
        } 
    return AGENDA ;
    
}

void imprimir(Contato* AGENDA , int* elements)
{   

    printf("\nAGENDA TELEFONICA") ; 
    
    printf("\n====================================\n\n")  ;

    if(*elements > 0)
    {
        for(int i=0 ; i< *elements ; i++)
        printf("%d | %-20s - %f\n" ,i , AGENDA[i].nome , AGENDA[i].telefone ) ; 
    }
    else 
    {
        printf("-----------LISTA VAZIA-----------\n") ; 
    }

   printf("\n====================================\n\n")  ;
}

int busca_binaria(Contato* AGENDA , char* nome , int init , int fim)
{
    if(fim >= 0 && init <= fim)
    {    int meio = (init + fim) / 2 ; 
        if(strcmp(AGENDA[meio].nome , nome) == 0)
            return meio; 
        else if(strcmp(AGENDA[meio].nome , nome) > 0)
            return busca_binaria(AGENDA , nome , init , meio-1) ; 
        else
            return busca_binaria(AGENDA, nome , meio+1 , fim) ; 
    }
    return -1 ; 
}