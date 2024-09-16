#include "../headers/simple_linked_list.h"

Node* create_list() {
    return NULL;
}

Node* insert_front(int v, Node* list) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->v = v;
    new_node->next = list;
    return new_node;
}   

Node* insert_end(int v, Node* list) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->v = v;
    new_node->next = NULL;

    //empty list;
    if(list == NULL) {
        return new_node;
    } else {
        //reach the last node
        Node* aux = list;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
        return list;
    }
}

int find_key(int v, Node* list) {
    Node* aux = list;
    while (aux != NULL) {
        if (aux->v == v) {
            return 1;
        }
    }
    return 0;
}

void print_list(Node* list) {
    Node* aux = list;
    while (aux != NULL) {
        printf("%d ", aux->v);
        aux = aux->next;
    }
    printf("\n");
}
