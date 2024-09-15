#include <stdio.h>
#include <stdlib.h>
#include "headers/definitions.h"

int main() {
    int m = 100; // 0 -> 99
    Node** map = create_map(m);

    while (1) {
        int* key, n, address;
        scanf("%d", &n);

        //folding method
        key = parse_int_to_vector(n);
        address = new_address(key);

        //insert on address
        map[address] = insert_node(n, map[address]);

        //print hashtable
        print_hash_table(map, m);

        printf("continue 0/1 > ");
        int c; scanf("%d", &c);
        if(!c) break;
    }
    return 0;
}