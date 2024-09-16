#include <stdio.h>
#include <stdlib.h>
//#include "headers/simple_linked_list.h"
#include "headers/doubly_linked_list.h"
int main() {
    List* list = create_list();

    //insert front
    insert_front(10, list);
    insert_front(11, list);
    insert_front(12, list);
    insert_front(13, list); 

    //insert end

    // ṕrint begin->end
    print_list(list, 0);

    //print end->begin
    print_list(list, 1);

    return 0;
}