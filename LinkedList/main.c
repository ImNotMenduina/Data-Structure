#include <stdio.h>
#include <stdlib.h>
#include "headers/simple_linked_list.h"

int main() {
    Node* list = create_list();

    //insert front
    list = insert_front(10, list);
    list = insert_front(11, list);
    list = insert_front(12, list);
    list = insert_front(13, list); 

    //insert end
    list = insert_end(10, list);
    list = insert_end(11, list);
    list = insert_end(12, list);
    list = insert_end(13, list);

    print_list(list);

    return 0;
}