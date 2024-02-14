/*
 ============================================================================
 Name        : Prj_Array_Exercicio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int numeros[5];
	int soma = 0;

	printf("Digite 5 números inteiros:\n");

	for (int i = 0; i < 5; i++) {
		printf("Número %d: ", i + 1);
		scanf("%d", &numeros[i]);
		soma = soma + numeros[i];
	}

	double media = (double) soma / 5;

	printf("Soma: %d\n", soma);
	printf("Média: %.2lf\n", media);

	return 0;
}
