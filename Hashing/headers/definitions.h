#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <stdio.h>
#include <stdlib.h>

struct node { 
    int key;
    struct node* next; 
}; 
typedef struct node Node;

int hashing(int v, int m);

Node** create_map(int m);

Node* insert_node(int v, Node* map);

void print_hash_table(Node** map, int m);

#endif