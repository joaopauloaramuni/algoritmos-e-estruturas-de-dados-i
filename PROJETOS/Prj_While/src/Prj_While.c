/*
 ============================================================================
 Name        : Prj_While.c
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

    while (cont <= 3) {
        printf("Entre com os dois números para serem somados: ");
        scanf("%d %d", &x, &y);

        result = x + y;

        printf("O resultado da soma é: %d\n", result);

        cont = cont + 1;
    }

    return 0;
}

