#include<stdio.h>
#include<stdlib.h>
#include "Cliente.h"
#include "Toolkit.h"

void client_factory();
void listar_clientes(FILE* arq);
void ordenacao(FILE* arq);

int main() {
	FILE* cliente_db;
	if((cliente_db = fopen("client.dat", "w+b")) == NULL) exit(2);

	client_factory(cliente_db);

	listar_clientes(cliente_db);	

	//ordenacao(cliente_db);

	Node** map;
	Cliente clientes;
	map = init_map(cliente_db);


	particionar(map, cliente_db);

	FILE* f1 = fopen("Particao0.dat", "a+b");
	listar_clientes(f1);

	FILE* f2 = fopen("Particao1.dat", "a+b");
	listar_clientes(f2);

	FILE* f3 = fopen("Particao2.dat", "a+b");
	listar_clientes(f3);

	fclose(cliente_db);

	return 0;
}

void client_factory(FILE* arq) {
	Cliente* c1 = novo_cliente(arq, 29, "Lucas", "09-11-1999");
	salva_cliente(arq, c1);
	Cliente* c2 = novo_cliente(arq, 14, "Erick", "00-00-0000");
	salva_cliente(arq, c2);
	Cliente* c3 = novo_cliente(arq, 76, "Augusto", "13-10-2004");
	salva_cliente(arq, c3);
	Cliente* c4 = novo_cliente(arq, 75, "Mateus", "29-01-2000");
	salva_cliente(arq, c4);
	Cliente* c5 = novo_cliente(arq, 59, "Daniel", "12-11-2020");
	salva_cliente(arq, c5);
	Cliente* c6 = novo_cliente(arq, 6, "Valmir", "13-10-2004");
	salva_cliente(arq, c6);
	Cliente* c7 = novo_cliente(arq, 7, "Rafaela", "09-11-1999");
	salva_cliente(arq, c7);
	Cliente* c8 = novo_cliente(arq, 74, "Carlos", "00-00-0000");
	salva_cliente(arq, c8);
	Cliente* c9 = novo_cliente(arq, 48, "Pedro", "13-10-2004");
	salva_cliente(arq, c9);
	Cliente* c10 = novo_cliente(arq, 46, "Joice", "11-11-2014");
	salva_cliente(arq, c10);
	Cliente* c11 = novo_cliente(arq, 10, "Anna", "13-10-2004");
	salva_cliente(arq, c11);
	Cliente* c12 = novo_cliente(arq, 18, "Bia", "11-11-2014");
	salva_cliente(arq, c12);
	Cliente* c13 = novo_cliente(arq, 56, "Roberto", "09-11-1999");
	salva_cliente(arq, c13);
	Cliente* c14 = novo_cliente(arq, 20, "Claudio", "00-00-0000");
	salva_cliente(arq, c14);
	Cliente* c15 = novo_cliente(arq, 26, "Clara", "13-10-2004");
	salva_cliente(arq, c15);
	Cliente* c16 = novo_cliente(arq, 4, "Maria", "29-01-2000");
	salva_cliente(arq, c16);
	Cliente* c17 = novo_cliente(arq, 21, "Guto", "12-11-2020");
	salva_cliente(arq, c17);
	Cliente* c18 = novo_cliente(arq, 65, "Amelia", "13-10-2004");
	salva_cliente(arq, c18);
	Cliente* c19 = novo_cliente(arq, 22, "Rafael", "09-11-1999");
	salva_cliente(arq, c19);
	Cliente* c20 = novo_cliente(arq, 49, "Rodrigo", "00-00-0000");
	salva_cliente(arq, c20);
	Cliente* c21 = novo_cliente(arq, 11, "Cristiane", "13-10-2004");
	salva_cliente(arq, c21);
	Cliente* c22 = novo_cliente(arq, 16, "Anninha", "11-11-2014");
	salva_cliente(arq, c22);
	Cliente* c23 = novo_cliente(arq, 8, "Juliana", "13-10-2004");
	salva_cliente(arq, c23);
	Cliente* c24 = novo_cliente(arq, 15, "Fernanda", "11-11-2014");
	salva_cliente(arq, c24);
}

void listar_clientes(FILE* arq) {
	rewind(arq);
	Cliente* cliente;
	printf("------------------------------------------\n");
	printf("codigo%8snome%10snascimento\n", "", "");
	printf("------------------------------------------\n");
	while((cliente = ler_cliente(arq)) != NULL) {
		imprime_cliente(cliente);
		free(cliente);
	}
}
