/*
 ============================================================================
 Name        : Prj_DoWhile_Exer2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int Num, contnum = 0;

	do {
		printf("Entre com um número; para encerrar, digite -1: ");
		scanf("%d", &Num);

		if (Num != -1) {
			contnum = contnum + 1; // ou contnum++
		}
	} while (Num != -1);

	printf("A quantidade de números digitados é: %d\n", contnum);

	return 0;
}

