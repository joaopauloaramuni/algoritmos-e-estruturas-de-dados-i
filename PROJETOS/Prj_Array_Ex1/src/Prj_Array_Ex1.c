/*
 ============================================================================
 Name        : Prj_Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Exemplo de declaração e inicialização de um array de inteiros
	int numeros[5] = { 1, 2, 3, 4, 5 };
	// Exemplo de declaração e inicialização de um array de strings
	char clubes[][30] = { "Atlético Mineiro", "Atlético Paranaense",
			"Atlético de Madrid" };

	// Loop for para percorrer o array e imprimir seus elementos
	printf("Elementos do array de inteiros: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", numeros[i]);
	}

	// Loop for para percorrer o array de strings e imprimir os nomes dos clubes
	printf("\nNomes dos clubes: ");
	for (int i = 0; i < 3; i++) {
		printf("%s ", clubes[i]);
	}

	return 0;
}
