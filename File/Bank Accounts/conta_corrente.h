#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include<stdio.h>
#include<stdlib.h>

struct Conta {
	int codigo;
	int codigo_agencia;
	double saldo;
};
typedef struct Conta Conta;

Conta* new_conta(int codigo, int codigo_agencia, double saldo);

void salvar_conta(Conta* conta, FILE* arq);

Conta* ler_conta(FILE* arq);

void imprime_conta(Conta* conta);

Conta* consultar_conta(int num_conta, FILE* arq);

#endif