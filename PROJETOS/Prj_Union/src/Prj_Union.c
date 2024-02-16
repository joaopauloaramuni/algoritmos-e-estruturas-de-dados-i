/*
 ============================================================================
 Name        : Prj_Union.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union {
	int i;
	float f;
	char str[20];
} dado;

int main(void) {
	dado.i = 10; /* union sera do tipo inteiro */
	printf("Sou inteiro : %d\n", dado.i);
	dado.f = 34.5; /* union sera do tipo float */
	printf("Sou real : %f\n", dado.f);
	strcpy(dado.str, "Sou String"); /* union sera do tipo String */
	printf("Sou string : %s\n", dado.str);

	return 0;
}
