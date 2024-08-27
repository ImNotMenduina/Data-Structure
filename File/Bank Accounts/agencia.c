#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agencia.h"

Agencia* new_agencia(int codigo, char* nome, char* gerente) {
	//Instancia uma agencia na heap
	Agencia* agencia;	
	agencia = (Agencia*)malloc(sizeof(Agencia));

	//Verifica se retornou NULL
	//Configura as celulas de memoria para 
	if(agencia) memset(agencia, 0, sizeof(Agencia));

	agencia->codigo = codigo;
	strcpy(agencia->nome, nome);
	strcpy(agencia->gerente, gerente);
	return agencia;
}

void salva_agencia(Agencia* agencia, FILE* arq) {
	fseek(arq, 0, SEEK_END);
	fwrite(&agencia->codigo, sizeof(int), 1, arq);
	fwrite(agencia->nome, sizeof(char), sizeof(agencia->nome), arq);
	fwrite(agencia->gerente, sizeof(char), sizeof(agencia->gerente), arq);
}

Agencia* ler_agencia(FILE* arq) {
	Agencia* agencia = (Agencia*)malloc(sizeof(Agencia));
	if (fread(&agencia->codigo, sizeof(int), 1, arq) <= 0) {
		free(agencia);
		return NULL;
	}
	fread(agencia->nome, sizeof(char), sizeof(agencia->nome), arq);
	fread(agencia->gerente, sizeof(char), sizeof(agencia->gerente), arq);
	return agencia;
}

void imprime_agencia(Agencia* agencia) {
	printf("****************************************\n");
	printf("Codigo: %d\n", agencia->codigo);
	printf("Nome: %s\n", agencia->nome);
	printf("gerente: %s\n", agencia->gerente);
}

Agencia* consultar_agencia(int numero_agencia, FILE* arq) {
	Agencia* agencia;
	rewind(arq);
	while((agencia = ler_agencia(arq)) != NULL) {
		if (agencia->codigo == numero_agencia) {
			return agencia;
		}
	}
	return NULL;
}