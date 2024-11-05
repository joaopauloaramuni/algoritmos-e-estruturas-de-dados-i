/*
 ============================================================================
 Name        : Prj_Fibonacci_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva em uma linha utilizando o operador ternário
int fiboRecursivoUmaLinha(int n) {
	return (n == 0) ? 0 : ((n == 1) ? 1 : (fiboRecursivoUmaLinha(n - 1) + fiboRecursivoUmaLinha(n - 2)));
}

// Função recursiva padrão
int fiboRecursivo(int n) {
	if (n == 0 || n == 1) {
		return n;
	} else
		return fiboRecursivo(n - 1) + fiboRecursivo(n - 2);
	// fib(5) = [[fib(3) + fib(2)] + [fib(2) + fib(1)]]
	// fib(5) = [[[fib(2) + fib(1)] + [fib(1) + fib(0)]] + [[fib(1) + fib(0)] + fib(1)]]
	// fib(5) = [[[[fib(1) + fib(0)] + fib(1)] + [fib(1) + fib(0)]] + [[fib(1) + fib(0)] + fib(1)]]
	// fib(5) = [[[1 + 0] + 1] + [1 + 0]] + [1 + 0] + 1
	// fib(5) = [[1 + 1] + 1] + 1 + 1
	// fib(5) = [2 + 1] + 1
	// fib(5) = 3 + 2
	// fib(5) = 5
	// 0 1 1 2 3 5 8 13...
}

//Utiliza um loop para calcular os termos da sequência de Fibonacci
int fiboComLoop(int n) {
	if (n == 0 || n == 1) {
		return n;
	} else {
		int a = 0, b = 1, resultado;

		for (int i = 2; i <= n; ++i) {
			resultado = a + b;
			a = b;
			b = resultado;
		}
		return resultado;
	}
}

int main(void) {
	int termo = 2; // Altere o valor conforme necessário
	printf("O %dº termo da sequência de Fibonacci é: %d\n", termo,
			fiboRecursivo(termo));

	return 0;
}
