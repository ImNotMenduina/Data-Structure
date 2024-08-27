#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "input_listener.h"
#include "conta_corrente.h"
#include "agencia.h"

void insert_acc(FILE* conta_db, FILE* agencia_db) {
    Agencia* agencia;
    Conta* conta;
    int num_conta, num_agencia;
    double saldo;

    printf("\n******** CADASTRO CONTA ********\n");
    printf("Conta (Num): ");
    scanf("%d", &num_conta);
    printf("Agencia (Num): ");
    scanf("%d", &num_agencia);
    printf("Saldo: ");
    scanf("%lf", &saldo);

    conta = (Conta*)malloc(sizeof(Conta));
    agencia = (Agencia*)malloc(sizeof(Agencia));

    if(agencia == NULL || conta == NULL)
        exit(1);
    
    if ((agencia = consultar_agencia(num_agencia, agencia_db)) == NULL) {
        printf("\n**** Erro ao cadastrar conta: agencia inexistente ****\n");
    } else {
        conta = new_conta(num_conta, num_agencia, saldo);
        salvar_conta(conta, conta_db);
        printf("Conta cadastrada com sucesso.\n");
    }
}

void insert_ag(FILE* conta_db, FILE* agencia_db) {
    char nome_ag[50], nome_gerente[50]; 
    int num_agencia;
    Agencia* agencia;

    printf("\n******** CADASTRO AGENCIA ********\n");
    printf("CodigoAg (Num): ");
    scanf("%d", &num_agencia);
    printf("Nome (Ag): ");
    scanf("%s", nome_ag);
    printf("Nome (Gerente): ");
    scanf("%s", nome_gerente);

    agencia = (Agencia*)malloc(sizeof(Agencia));
    
    if (agencia == NULL)
        exit(1);

    if ((agencia = consultar_agencia(num_agencia, agencia_db)) == NULL) {
        agencia = new_agencia(num_agencia, nome_ag, nome_gerente);
        salva_agencia(agencia, agencia_db);
        printf("\n**** Agencia cadastrada com sucesso. ****\n");
    } else {
        printf("\n**** Erro ao cadastrar agencia: agencia ja cadastrada ****\n");
    }
}