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
	// Quarta chamada recursiva: 1 == 0 || 1 == 1 true
	// Terceira chamada recursiva: 2 == 0 || 2 == 1 falso
	// Segunda chamada recursiva: 3 == 0 || 3 == 1 falso
	// Primeira chamada recursiva: 4 == 0 || 4 == 1 falso
	// Chamada do main: 5 == 0 || 5 == 1 falso
	if (n == 0 || n == 1) {
		// Caso base
		return 1;
	} else {
		// Quarta chamada recursiva: 2 * fr(1) = 2 * 1 = 2
		// Terceira chamada recursiva: 3 * fr(2) = 3 * 2 = 6
		// Segunda chamada recursiva: 4 * fr(3) = 4 * 6 = 24
		// Primeira chamada recursiva: 5 * fr(4) = 5 * 24 = 120

		// 5 * (4 * 3 * 2 * 1) = 120
		// 5 * (4 * 3 * 2 * fr(1)) = ?
		// 5 * (4 * 3 * fr(2)) = ?
		// 5 * (4 * fr(3)) = ?
		// 5 * fr(4) = ?
		// fr(5) = ?
		// Leia de baixo pra cima

		return n * fatorialRecursivo(n - 1);
		// Chamada recursiva
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
