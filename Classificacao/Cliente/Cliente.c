#include "Cliente.h"

int total_reg = 0;

Cliente* novo_cliente(FILE* arq, int cod_cliente, char* nome, char* data_nascimento) {
	Cliente* cliente;
	cliente = (Cliente*)malloc(sizeof(Cliente));

	if (cliente == NULL) exit(1);

	cliente->cod_cliente = cod_cliente;
	strcpy(cliente->nome, nome);
	strcpy(cliente->data_nascimento, data_nascimento);
	return cliente;
}

void salva_cliente(FILE* arq, Cliente* cliente) {
	fseek(arq, 0, SEEK_END);
	fwrite(&cliente->cod_cliente, sizeof(int), 1, arq);
	fwrite(cliente->nome, sizeof(char), sizeof(cliente->nome), arq);
	fwrite(cliente->data_nascimento, sizeof(char), sizeof(cliente->data_nascimento), arq);
	total_reg++;
}

Cliente* ler_cliente(FILE* arq) {
	Cliente* cliente;
	cliente = (Cliente*)malloc(sizeof(Cliente));

	if(fread(&cliente->cod_cliente, sizeof(int), 1, arq) <= 0) {
		free(cliente);
		return NULL;
	}
	fread(cliente->nome, sizeof(char), sizeof(cliente->nome), arq);
	fread(cliente->data_nascimento, sizeof(char), sizeof(cliente->data_nascimento), arq);
	return cliente;
}

void imprime_cliente(Cliente* cliente) {
	printf("%d", cliente->cod_cliente);
	printf("%20s%20s", cliente->nome, cliente->data_nascimento);
	printf("\n");
}