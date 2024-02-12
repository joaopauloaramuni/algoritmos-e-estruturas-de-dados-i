/*
 ============================================================================
 Name        : Prj_LeituraDados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Declaração da variável para armazenar o valor lido
    int numero;

    // Utilização da scanf para ler um inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Exibição do valor lido
    printf("Você digitou: %d\n", numero);

    return 0;
}
