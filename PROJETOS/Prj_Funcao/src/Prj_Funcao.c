/*
 ============================================================================
 Name        : Prj_Funcao.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Protótipo da função (assinatura)
 *
 * Esta função recebe um número como argumento e retorna o quadrado desse número.
 *
 * @param numero (int) - O número para o qual queremos calcular o quadrado.
 * @return int - O quadrado do número de entrada.
 */
int calcularQuadrado(int numero);

int main(void) {
    // Exemplo de uso da função
    int numeroEntrada = 5;

    // Chamando a função e armazenando o resultado
    int resultado = calcularQuadrado(numeroEntrada);

    // Exibindo o resultado
    printf("O quadrado de %d é: %d\n", numeroEntrada, resultado);

    return 0;
}

/**
 * Definição da função calcularQuadrado
 *
 * Esta função recebe um número como argumento e retorna o quadrado desse número.
 *
 * @param numero (int) - O número para o qual queremos calcular o quadrado.
 * @return int - O quadrado do número de entrada.
 */
int calcularQuadrado(int numero) {
    // Calculando o quadrado do número
    int quadrado = numero * numero;

    // Retornando o resultado
    return quadrado;
}
