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

//retorna o numero em vetor
int* parse_int_to_vector (int n) {
    int* key = (int*)malloc(sizeof(int) * KEYSZ);
    memset(key, 0x00, sizeof(int) * KEYSZ); 

    int i = KEYSZ - 1;
    while (1) {
        int q, mod;
        mod = n % 10;
        n = n / 10;
        key[i--] = mod;
        
        if (n < 10) 
        {
            key[i] = n;
            break;
        }
    }
    return key;
}

int new_address (int* key) {
        int j=0, k=1, address, tam = KEYSZ;

        while (tam > FOLDING) {
            // 8 4 3 1 5 9
            int a, b;
            a = key[j];
            b = key[k];            
            key[j + FOLDING + 1] += a;
            key[k + FOLDING - 1] += b;

            if (key[j + FOLDING + 1] > 10) {
                int q = key[j + FOLDING + 1] % 10;
                key[j + FOLDING + 1] = q;
            }

            if (key[k + FOLDING - 1] > 10) {
                int q = key[k + FOLDING - 1] % 10;
                key[k + FOLDING - 1] = q;
            }
            j += FOLDING ;
            k += FOLDING ;
            tam -= 2;
        }
        address = key[KEYSZ - 1] + key[KEYSZ - 2] * 10;
    return address;
}