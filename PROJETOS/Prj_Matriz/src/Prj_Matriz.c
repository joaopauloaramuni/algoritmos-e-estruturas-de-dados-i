/*
 ============================================================================
 Name        : Prj_Matriz.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

int main(void) {
	// Declaração da matriz bidimensional
	int matriz[LINHAS][COLUNAS];

	// Preenchimento da matriz
	printf("Digite os elementos da matriz (%d x %d):\n", LINHAS, COLUNAS);
	for (int i = 0; i < LINHAS; i++) {
		for (int j = 0; j < COLUNAS; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}

	// Exibição da matriz
	printf("\nMatriz digitada:\n");
	for (int i = 0; i < LINHAS; i++) {
		for (int j = 0; j < COLUNAS; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
