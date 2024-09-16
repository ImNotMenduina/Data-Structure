#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node* next;
}; 
typedef struct node Node;

Node* create_list();

Node* insert_front(int v, Node* list);

Node* insert_end(int v, Node* list);

int find_key(int v, Node* list);

void print_list(Node* list);

#endif