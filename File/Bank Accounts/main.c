#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agencia.h"
#include "conta_corrente.h"
#include "input_listener.h"

#define TRUE 1 
#define FALSE 0

void agencia_factory(FILE* arq) {
	Agencia* agencia_a = new_agencia(111, "Agencia_A", "Jerry");
	salva_agencia(agencia_a, arq);
	Agencia* agencia_b = new_agencia(222, "Agencia_B", "Steve");
	salva_agencia(agencia_b, arq);
	Agencia* agencia_c = new_agencia(333, "Agencia_C", "Michael");
	salva_agencia(agencia_c, arq);
	Agencia* agencia_d = new_agencia(444, "Agencia_D", "Stanlee");
	salva_agencia(agencia_d, arq);
	Agencia* agencia_e = new_agencia(555, "Agencia_E", "Peter");
	salva_agencia(agencia_e, arq);
}

void conta_factory(FILE* arq) {
	Conta* conta_a = new_conta(111123, 111, 100.00);
	salvar_conta(conta_a, arq);
	Conta* conta_b = new_conta(222234, 222, 200.00);
	salvar_conta(conta_b, arq);
	Conta* conta_c = new_conta(333345, 333, 300.00);
	salvar_conta(conta_c, arq);
	Conta* conta_d = new_conta(444456, 444, 400.00);
	salvar_conta(conta_d, arq);
	Conta* conta_e = new_conta(555789, 555, 500.00);
	salvar_conta(conta_e, arq);
}

void ler_agencias(FILE* arq) {
	Agencia* ag;
	rewind(arq);
	while((ag = ler_agencia(arq)) != NULL) {
		imprime_agencia(ag);
		free(ag);
	}
}

void ler_contas(FILE* arq) {
	Conta* conta;
	rewind(arq);
	while((conta = ler_conta(arq)) != NULL) {
		imprime_conta(conta);
		free(conta);
	}
}

int main() {
	FILE* agencia_db;
	FILE* conta_db;

	if((agencia_db = fopen("agencyDb.dat", "w+b")) == NULL) 
	{
		printf("Erro ao inicializar o arquivo AgenciaDb.dat.\n");
		exit(1);
	}

	if ((conta_db = fopen("contaDb.dat", "w+b")) == NULL)
	{
		printf("Erro ao inicializar o arquivo ContaDb.dat\n");
		exit(1);
	}

	agencia_factory(agencia_db);

	conta_factory(conta_db);

	int num_agencia, num_conta;
	Agencia* agencia;
	int finish = TRUE;
	do
	{
		printf("\n********* BANCO CENTRAL *********\n");
		printf("1. Consultar Conta\n");
		printf("2. Consultar Agencia\n");
		printf("3. Cadastrar Conta\n");
		printf("4. Cadastrar Agencia\n");
		printf("5. Ler contas\n");
		printf("6. Ler agencias\n");
		printf("7. Sair\n");
		printf(".> ");
		int op;
		scanf("%d", &op);

		switch(op) {
		case 1:
			memset(&num_conta, 0, sizeof(int));

			printf("Conta: ");
			scanf("%d", &num_conta);

			Conta* acc;
			if ((acc = consultar_conta(num_conta, conta_db)) == NULL) {
				printf("Conta nao cadastrada.\n");
			} else {
				system("clear");
				imprime_conta(acc);
			}
			break;

		case 2:
			memset(&num_agencia, 0, sizeof(int));

			printf("Agencia: ");
			scanf("%d", &num_agencia);

			if((agencia = consultar_agencia(num_agencia, agencia_db)) == NULL) {
				printf("Agencia nao cadastrada.\n");
			} else {
				system("clear");
				imprime_agencia(agencia);
			}
			break;

		case 3: 
			insert_acc(conta_db, agencia_db);
			system("clear");
			break;

		case 4:
			insert_ag(conta_db, agencia_db);
			system("clear");
			break; 

		case 5: 
			ler_contas(conta_db);
			break;

		case 6:
			ler_agencias(agencia_db);
			break;

		case 7: 
			finish = FALSE;
			break;
		}

	}while(finish);

	fclose(agencia_db);

	fclose(conta_db);

	return 0;
}