/*
 ============================================================================
 Name        : Prj_Array_Exer3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int matriz[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
	int soma = 0;
	int contador = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				soma = soma + matriz[i][j][k];
				contador++;
			}
		}
	}

	double media = (double) soma / contador;

	printf("Média dos elementos da matriz tridimensional: %.2lf\n", media);

	return 0;
}
