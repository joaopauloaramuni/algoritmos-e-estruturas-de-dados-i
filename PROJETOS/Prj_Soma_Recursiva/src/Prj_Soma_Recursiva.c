/*
 ============================================================================
 Name        : Prj_Soma_Recursiva.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva para calcular a soma dos dígitos de um número
int somaDosDigitos(int n) {
	//Caso base
    if (n == 0)
        return 0;
    //Passo recursivo
    else
    	// n % 10 = último dígito
    	// n / 10 = número menos o último dígito
        return (n % 10) + somaDosDigitos(n / 10);
		// Quinta chamada recursiva: 1 + somaDosDigitos(0) = 1 + 0 = 1
    	// Quarta chamada recursiva: 2 + somaDosDigitos(1) = 2 + 1 = 3
    	// Terceira chamada recursiva: 3 + somaDosDigitos(12) = 3 + 3 = 6
		// Segunda chamada recursiva: 4 + somaDosDigitos(123) = 4 + 6 = 10
    	// Primeira chamada recursiva: 5 + somaDosDigitos(1234)= 5 + 10 = 15
}

int main(void) {
    int numero = 12345;
    int resultado = somaDosDigitos(numero);
    printf("A soma dos dígitos de %d é %d\n", numero, resultado);
    return 0;
}
