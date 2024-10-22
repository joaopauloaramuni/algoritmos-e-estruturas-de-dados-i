/*
 ============================================================================
 Name        : Prj_Array_Exer2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int matriz[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int soma = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			soma = soma + matriz[i][j];
		}
	}

	printf("Soma dos elementos da matriz: %d\n", soma);

	return 0;
}
