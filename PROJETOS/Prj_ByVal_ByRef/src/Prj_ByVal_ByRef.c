/*
 ============================================================================
 Name        : Prj_ByVal_ByRef.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void incrementarPorValor(int x) {
    x++;
    // O escopo desta variável vale somente dentro da função.
    // Você pode inclusive chamar esta variável de y ou de z.
}

void incrementarPorReferencia(int *x) {
    (*x)++;
}

int main(void) {
    int numero = 5;
    incrementarPorValor(numero);
    printf("Valor original: %d\n", numero); // Saída: Valor original: 5

    incrementarPorReferencia(&numero);
    printf("Valor modificado: %d\n", numero); // Saída: Valor modificado: 6

    return 0;
}
