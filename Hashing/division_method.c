#include <stdio.h>
#include <stdlib.h>
#include "headers/definitions.h"

int main(int argc, char* argv[]) {
    int m; scanf("%d", &m);
    Node** map = create_map(m);

    while (1) {
        system("clear");
        int n; scanf("%d", &n);
        int reg = hashing(n, m);
        map[reg] = insert_node(n, map[reg]);

        print_hash_table(map, m);

        printf("continue 0/1/> ") ;
        int c; scanf("%d", &c);
        if (!c) break;
    }
    return 0;
}