/*
==================================
TRABALHO N2 - ALGORITMOS I
Simulação de vendas de uma loja

Alunas:
Gabrielly de Oliveira
Rayssa Carasilo

Professor: Alessandro Brassanini
==================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define PRODUTOS 200
#define CLIENTES 50

int aleatorio(int n)
{
    return rand() % n;
}

int main(int args, char *arg[])
{
    SetConsoleOutputCP(65001);
    int i, p, npro, ncli; // npro = número de produtos, ncli = número de clientes

    int comprar[CLIENTES];
    float preco[PRODUTOS];
    float total;
    char resposta;

    srand((unsigned)time(NULL)); // Semente para geração de números aleatórios

    // Animação de carregamento
    char *frames[] = {"|  ", "/  ", "-  ", "\\  "};
    printf("Carregando total de vendas...");
    for (i = 0; i < 16; i++)
    {
        printf(" %s", frames[i % 4]);
        fflush(stdout);
        Sleep(150);
        printf("\b\b\b\b");
    }
    printf(" Pronto!\n\n");

    npro = aleatorio(PRODUTOS) + 1; // Gera um número aleatório de produtos entre 1 e PRODUTOS

    for (i = 0; i < npro; i++)
    {
        p = 5 + aleatorio(96); // Gera um preço aleatório entre R$ 5,00 e R$ 100,00
        preco[i] = p;
    }

    printf("SIMULACAO DA LOJA:\n");
    printf("Quantidade de produtos: %d\n\n", npro);

    printf("----------------------------------------------\n");
    printf("PRODUTO\t\tVALOR\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < npro; i++)
    {
        printf("%d\t\tR$ %.2f\n", i + 1, preco[i]); // Exibe o número do produto e seu preço
    }

    ncli = aleatorio(CLIENTES) + 1; // Gera um número aleatório de clientes

    for (i = 0; i < ncli; i++)
    {
        comprar[i] = aleatorio(npro); // Gera um número aleatório para o produto comprado pelo cliente, garantindo que seja um índice válido
    }

    total = 0.0;

    printf("\nQuantidade de clientes: %d\n\n", ncli);
    printf("----------------------------------------------\n");
    printf("CLIENTE\t\tPRODUTO\t\tVALOR\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < ncli; i++)
    {
        printf("%d\t\t%d\t\tR$ %.2f\n", i + 1, comprar[i] + 1, preco[comprar[i]]); // Exibe o número do cliente, o produto comprado e seu preço
        total += preco[comprar[i]];
    }

    printf("----------------------------------------------\n");
    printf("Total vendido no dia: R$ %.2f\n", total);

    printf("\nObrigado por usar a simulação da loja!\n");
    printf("Deseja realizar outra simulação? (s/n): ");

    scanf(" %c", &resposta);
    if (resposta == 's' || resposta == 'S')
    {
        main(args, arg); // Reinicia a simulação
    }
    return 0;
}
