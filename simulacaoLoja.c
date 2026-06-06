#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRODUTOS 200
#define CLIENTES 50

int randomInt(int n) {
    return rand() % n;
}

int main() {
    int i, npro, ncli;
    int compra[CLIENTES];
    float preco[PRODUTOS];

    srand(time(NULL));

    npro = 1 + randomInt(PRODUTOS);

    for (i = 0; i < npro; i++) {
        preco[i] = 5 + randomInt(96);
    }

    ncli = 1 + randomInt(CLIENTES);

    for (i = 0; i < ncli; i++) {
        compra[i] = randomInt(npro);
    }

    for (i = 0; i < ncli; i++) {
        printf("Cliente %d comprou o produto %d por R$ %.2f\n",
               i, compra[i], preco[compra[i]]);
    }

    return 0;
}