#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

struct Node {
	int congelado;
	int size;
	Cliente* cliente;
	struct Node* proximo;
};
typedef struct Node Node;

//cria uma pilha
Node* criar_pilha() ;

//inserir na pilha
Node* inserir_pilha(Cliente* cliente, Node* lst);

//remover uma pilha
void remover_pilha(Node* lst);

//init map de pilhas
Node** init_map(FILE* arq);

//printar meu map de pilhas
void print_map(Node** map);

Node* vetorizar(Node** map, FILE* arq);

void particionar(Node** map, FILE* arq);

int menor_cod_cliente(Node** map) ;

int congelados(Node* vet) ;


#endif