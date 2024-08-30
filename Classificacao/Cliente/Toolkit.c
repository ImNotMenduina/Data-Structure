#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Toolkit.h"
#include "Cliente.h"
#define REGISTROS 6
#define TRUE 1
#define FALSE 0
#define TOTAL_PARTICOES total_reg/(*map)->size

Node* criar_pilha() 
{	
	return NULL;
}

Node* inserir_pilha(Cliente* cliente, Node* lst) {
	Node* novo_node = (Node*)malloc(sizeof(Node));
	novo_node->cliente = (Cliente*)malloc(sizeof(Cliente));
	if (novo_node == NULL) exit(1);

	novo_node->congelado = FALSE;
	novo_node->cliente->cod_cliente = cliente->cod_cliente;
	strcpy(novo_node->cliente->nome, cliente->nome);
	strcpy(novo_node->cliente->data_nascimento, cliente->data_nascimento);
	novo_node->proximo = lst;

	//gambiarra tamanho: cada no carrega a quantidade total de registro
	novo_node->size = 6;

	return novo_node;
}

Node** init_map(FILE* arq) {
	rewind(arq);
	int reg_clientes = 0;
	Node** map = (Node**)malloc(sizeof(Node*) * REGISTROS);

	Cliente* cliente; 
	while (reg_clientes < REGISTROS && (cliente = ler_cliente(arq)) != NULL) {
		map[reg_clientes] = inserir_pilha(cliente, map[reg_clientes]);
		reg_clientes++;
	}
	(*map)->size = reg_clientes;
	return map;
}

void print_map(Node** map) {
	for(int i=0; i<(*map)->size; i++) {
		Node* aux;
		aux = map[i];
		while(aux != NULL) {
			printf("%10s%d","", aux->cliente->cod_cliente);
			printf("%10s%20s\n", aux->cliente->nome, aux->cliente->data_nascimento);
			printf("-------------------------------------------------------------\n");
			aux = aux->proximo;
		}
	}
}

void particionar(Node** map, FILE* arq) {
	char str_particao[100] = "Particao", str_num_particao[100], str_new_particao[100];
	int flag_congelados = 0, menor_index, particao = 0, flag_sem_entradas = 0;	
	FILE* f = NULL; 
	Cliente* c;

	int end_of_file = FALSE;
	while(particao < 3) {

		int count = 0;
		for(int i=0; i<(*map)->size; i++) {
			if (!map[i]->congelado){
				break;
			}
			count++;
		}

		if (count == (*map)->size)
		{
			flag_congelados = TRUE;	
		}

		if (f == NULL) {
			sprintf(str_num_particao, "%d", particao);
			memset(str_new_particao, 0, sizeof(str_new_particao));
			strcpy(str_new_particao, str_particao);
			strcat(str_new_particao, str_num_particao);
			strcat(str_new_particao, ".dat");

		if((f = fopen(str_new_particao, "w+b")) == NULL)
			exit(1);
		}

		//caso 1: acabaram as entradas - 
		//nao ha mais entradas no arquivo fonte
		//gravar o restante do buffer de forma ordenada em uma particao

		if(flag_sem_entradas) {
			int tam = map[0]->size;
			while (tam) {
				menor_index = menor_cod_cliente(map);
				if(menor_index != -1){
					salva_cliente(f,map[menor_index]->cliente);
					map[menor_index]->cliente = NULL;
				}	
				tam--;
			}

			for (int i=0; i<(*map)->size; i++) 
				map[i]->congelado = FALSE;

			fclose(f);
			f = NULL;
			particao++;
		}

		//todos congelados
		//descongelo os elementos congelados e fecho a particao
		else if(flag_congelados) {
				fclose(f);
				f = NULL;
				particao++;

				for (int i=0; i<(*map)->size; i++) {
					map[i]->congelado = FALSE;

				flag_congelados= FALSE;
			}

		//senao, pego cada registro do arquivo algo
		//gravo em ordem no arquivo destino
		} else {
				//pega o proximo registro do arquivo alvo
				if ((c = ler_cliente(arq)) != NULL)
				{
					Node* novo_cliente = (Node*)malloc(sizeof(Node));
					novo_cliente->cliente = c;		

					//busca o menor elemento (cod_cliente) do buffer
					menor_index = menor_cod_cliente(map);

					//salva o menor elemento no arquivo destino
					salva_cliente(f,map[menor_index]->cliente);

					//lógica para congelar
					//se "novo_cliente->cod_cliente" (arquivo alvo) for menor que o "map[menor_index]->cliente->cod_cliente" 
					//(menor codigo encontrado anteriormente no buffer), entao deve-se gravar o registro recém lido no buffer
					//e congelá-lo. Ele nao podera ser gravado na particao atual.
					if (map[menor_index]->cliente->cod_cliente > novo_cliente->cliente->cod_cliente) {
						map[menor_index]->cliente = novo_cliente->cliente;
						map[menor_index]->congelado = TRUE;
					} else {
						menor_index = menor_cod_cliente(map);
						map[menor_index]->cliente = novo_cliente->cliente;
					}
				} 
				else {
					//acabaram os registro do buffer
					flag_sem_entradas = TRUE;
				}
			}
		}
		
}

int menor_cod_cliente(Node** map) {
	int menor = (int)INFINITY;
	int menor_index = -1;
	Cliente* cliente;
	for(int i=0; i<(*map)->size; i++) {
		if (map[i]->cliente != NULL && !map[i]->congelado && map[i]->cliente->cod_cliente < menor) {
			menor_index = i;
			menor = map[i]->cliente->cod_cliente;
		}
	}
	return menor_index;
}