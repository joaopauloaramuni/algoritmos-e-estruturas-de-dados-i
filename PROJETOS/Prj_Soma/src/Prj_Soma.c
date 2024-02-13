/*
 ============================================================================
 Name        : Prj_Soma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
	int c = a + b;
	return c;
}

int main(void) {
	int x = 2;
	int y = 3;
	int z = soma(x,y);
	printf("Soma = %d\n", z);

	return 0;
}
