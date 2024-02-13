/*
 ============================================================================
 Name        : Prj_Fatorial_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva em uma linha utilizando o operador ternário
int fatorialRecursivoUmaLinha(int c) {
	return (c == 0 || c == 1) ? 1 : (c * fatorialRecursivoUmaLinha(c - 1));
}

// Função recursiva padrão
int fatorialRecursivo(int n) {
	// Caso base
	if (n == 0 || n == 1) {
		return 1;
	} else {
		// Chamada recursiva
		return n * fatorialRecursivo(n - 1);
	}
}

int fatorialComLoop(int n) {
	int resultado = 1;
	// Utilizando um loop for para multiplicar os números de 1 a n
	for (int i = 1; i <= n; i++) {
		resultado *= i;
	}
	return resultado;
}

int main(void) {
	int numero = 5;
	printf("O fatorial de %d é: %d\n", numero, fatorialRecursivo(numero));
	return 0;
}
