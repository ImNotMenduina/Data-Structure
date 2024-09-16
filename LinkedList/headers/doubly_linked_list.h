#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
struct node {
    int v;
    struct node* next;
    struct node*prev;
};
typedef struct node Node;

struct list {
    struct node* begin;
    struct node* end;
};
typedef struct list List;

List* create_list();

void insert_front(int v, List* list);

void print_list(List* list, int reverse);

#endif