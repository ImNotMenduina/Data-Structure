#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEYSZ 6
#define FOLDING 2

struct node { 
    int key;
    struct node* next; 
}; 
typedef struct node Node;

int hashing(int v, int m);

Node** create_map(int m);

Node* insert_node(int v, Node* map);

void print_hash_table(Node** map, int m);

int* parse_int_to_vector (int n);

int new_address (int* key);

#endif