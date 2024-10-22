/*
 ============================================================================
 Name        : Prj_DoWhile.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x, y, result, cont;

	cont = 1;
	do {
		printf("Entre com os dois números para serem somados\n");
		scanf("%d %d", &x, &y);

		result = x + y;
		printf("O valor da soma é %d \n", result);
		cont++;

	} while (cont <= 3);

}
