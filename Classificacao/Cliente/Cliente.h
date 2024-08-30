#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
	int cod_cliente;
	char nome[50];
	char data_nascimento[11];
};
typedef struct Cliente Cliente;

Cliente* novo_cliente(FILE* arq, int cod_cliente, char* nome, char* data_nascimento);

void salva_cliente(FILE* arq, Cliente* cliente);

Cliente* ler_cliente(FILE* arq);

void imprime_cliente(Cliente* cliente);

extern int total_reg;

#endif