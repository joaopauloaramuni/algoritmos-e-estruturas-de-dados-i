/*
 ============================================================================
 Name        : Prj_Maior_Menor.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, number;
    int maior, menor;

    // Solicita ao usuário que insira 10 números
    printf("Digite 10 números:\n");

    // Lê o primeiro número
    scanf("%d", &number);

    // Inicializa o maior e o menor com o primeiro número
    maior = number;
    menor = number;

    // Loop para ler os próximos 9 números
    for (i = 1; i < 10; i++) { // i = 1, 2, .... , 9, 10 falso
        scanf("%d", &number);

        // Verifica se o número atual é maior que o maior atual
        if (number > maior) {
            maior = number;
        }

        // Verifica se o número atual é menor que o menor atual
        if (number < menor) {
            menor = number;
        }
    }

    // Exibe o maior e o menor número
    printf("O maior número é: %d\n", maior);
    printf("O menor número é: %d\n", menor);

    return 0;
}

