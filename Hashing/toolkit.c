#include "headers/definitions.h"

int hashing(int v, int m) {
    return v % m;
}

Node** create_map(int m) {
    Node** new_map;
    new_map = (Node**)malloc(sizeof(Node*) * m);
    if (new_map == NULL) exit(1);
    return new_map;
}

Node* insert_node(int v, Node* map) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->key = v;

    Node* aux = map;
    
    if (aux == NULL) {
        new_node->next = aux;
        return new_node;
    } else {
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
        new_node->next = NULL;
        return map;
    }
}

void print_hash_table(Node** map, int m) {
    for (int i=0; i<m; i++) {
        Node* aux = map[i];
        printf("%d: ", i);
        while(aux != NULL) {
            printf("%d ", aux->key);
            aux = aux->next;
        }
        printf("\n");
    }
}