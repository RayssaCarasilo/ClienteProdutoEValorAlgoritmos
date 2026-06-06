// Trabalho da matéria Introdução a Algoritmos feito pelas alunas Gabrielly Oliveira e
// Rayssa Carasilo - Sistemas de Informações FASE 1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRODUTOS 200
#define CLIENTES 50

int randomInt(int n) {
    return rand() % n;
}

int main() {
    int i;
    int npro, ncli;
    int compra[CLIENTES];
    float preco[PRODUTOS];
    float total = 0.0;

    srand(time(NULL));

    npro = 1 + randomInt(PRODUTOS);

    for (i = 0; i < npro; i++) {
        preco[i] = 5 + randomInt(96);
    }

    ncli = 1 + randomInt(CLIENTES);

    for (i = 0; i < ncli; i++) {
        compra[i] = randomInt(npro);
    }

    printf("=== PRODUTOS ===\n");
    for (i = 0; i < npro; i++) {
        printf("Produto %d -> R$ %.2f\n", i, preco[i]);
    }

    printf("\n=== COMPRAS DOS CLIENTES ===\n");
    for (i = 0; i < ncli; i++) {
        printf("Cliente %d comprou o produto %d por R$ %.2f\n",
               i, compra[i], preco[compra[i]]);
        total += preco[compra[i]];
    }

    printf("\nTotal vendido no dia: R$ %.2f\n", total);

    return 0;
}