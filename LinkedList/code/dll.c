#include "../headers/doubly_linked_list.h"

List* create_list() {
    List* new_list = (List*)malloc(sizeof(List));
    if (new_list == NULL )exit(1);
    new_list->begin = NULL;
    new_list->end = NULL;
}

void insert_front(int v, List* list) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) exit(1);

    new_node->v = v;
    new_node->next = list->begin;
    new_node->prev = NULL;

    if (list->begin == NULL)
    {
        list->begin = new_node;
        list->end = new_node;
    } else { 
        Node* aux = list->begin;
        aux->prev = new_node;
        list->begin = new_node;
    }
}

void print_list(List* list, int reverse) {
    if (!reverse) {
        Node* aux = list->begin;
        while(aux != NULL) {
            printf("%d ", aux->v);
            aux = aux->next;
        }
    } else {
        Node* aux = list->end;
        while(aux != NULL) {
            printf("%d ", aux->v);
            aux = aux->prev;
        }
    }
    printf("\n");
}
