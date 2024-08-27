#ifndef AGENCIA_H
#define AGENCIA_H

#include<stdio.h>
#include<stdlib.h>

struct Agencia {
	int codigo;
	char nome[50];
	char gerente[50];
};
typedef struct Agencia Agencia;

//int count_agencias = 0;

Agencia* new_agencia(int codigo, char* nome, char* gerente);

void salva_agencia(Agencia* agencia, FILE* arq);

Agencia* ler_agencia(FILE* arq);

void imprime_agencia(Agencia* agencia);

Agencia* consultar_agencia(int numero_agencia, FILE* arq);

#endif