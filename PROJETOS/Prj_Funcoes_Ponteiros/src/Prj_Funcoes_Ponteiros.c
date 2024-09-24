/*
 ============================================================================
 Name        : Prj_Funcoes_Ponteiros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função que realiza a troca de valores usando ponteiros
void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int a, b;

    // Solicita ao usuário que insira dois números
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    // Mostra os valores antes da troca
    printf("Antes da troca: a = %d, b = %d\n", a, b);

    // Chama a função para realizar a troca de valores
    troca(&a, &b);

    // Mostra os valores após a troca
    printf("Depois da troca: a = %d, b = %d\n", a, b);

    return 0;
}
