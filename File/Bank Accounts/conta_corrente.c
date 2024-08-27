#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "conta_corrente.h"
#include "agencia.h"

Conta* new_conta(int codigo, int codigo_agencia, double saldo) {
	Conta* conta;
	conta = (Conta*)malloc(sizeof(Conta));

	if (conta == NULL) {
		printf("Erro ao instanciar Conta");
		exit(1);
	}

	memset(conta, 0, sizeof(Conta));

	conta->codigo = codigo;
	conta->codigo_agencia = codigo_agencia;
	conta->saldo = saldo;

	return conta;
}

void salvar_conta(Conta* conta, FILE* arq){
	fseek(arq, 0, SEEK_END);
	fwrite(&conta->codigo, sizeof(int), 1, arq);
	fwrite(&conta->codigo_agencia, sizeof(int), 1, arq);
	fwrite(&conta->saldo, sizeof(double), 1, arq);
}

Conta* ler_conta(FILE* arq) {
	Conta* conta;
	conta = (Conta*)malloc(sizeof(Conta));

	if (fread(&conta->codigo, sizeof(int), 1, arq) <= 0) {
		free(conta);
		return NULL;
	}

	fread(&conta->codigo_agencia, sizeof(int), 1, arq);
	fread(&conta->saldo, sizeof(double), 1, arq);
	return conta;
}

void imprime_conta(Conta* conta) {
	printf("******************************\n");
	printf("Codigo: %d\n", conta->codigo);
	printf("Codigo Agencia: %d\n", conta->codigo_agencia);
	printf("Saldo: %.2f\n", conta->saldo);
}

Conta* consultar_conta(int num_conta, FILE* arq) {
	Conta* acc;
	rewind(arq);
	while((acc = ler_conta(arq)) != NULL) {
		if(acc->codigo == num_conta) {
			return acc;
		}
	}
	return NULL;
}













