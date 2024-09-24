/*
 ============================================================================
 Name        : Prj_Calculadora_Ponteiros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// Função que calcula a soma de dois números usando ponteiros
void soma(int *x, int *y, int *resultado) {
    *resultado = *x + *y;
}

// Função que calcula a diferença entre dois números usando ponteiros
void diferenca(int *x, int *y, int *resultado) {
    *resultado = *x - *y;
}

// Função que calcula o produto de dois números usando ponteiros
void produto(int *x, int *y, int *resultado) {
    *resultado = *x * *y;
}

// Função que calcula o quociente de dois números usando ponteiros
void quociente(int *x, int *y, float *resultado) {
    if (*y != 0) {
        *resultado = (float)*x / *y;
    } else {
        printf("Divisão por zero não é permitida!\n");
        *resultado = 0.0;
    }
}

int main(void) {
    int a, b, resultado;
    float resultadoDiv;

    // Solicita ao usuário que insira dois números
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    // Chama a função para calcular a soma
    soma(&a, &b, &resultado);
    printf("Soma: %d\n", resultado);

    // Chama a função para calcular a diferença
    diferenca(&a, &b, &resultado);
    printf("Diferença: %d\n", resultado);

    // Chama a função para calcular o produto
    produto(&a, &b, &resultado);
    printf("Produto: %d\n", resultado);

    // Chama a função para calcular o quociente
    quociente(&a, &b, &resultadoDiv);
    if (b != 0) {
        printf("Quociente: %.2f\n", resultadoDiv);
    }

    return 0;
}
