/*
 ============================================================================
 Name        : Prj_CondicionalSimples.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ValA, ValB, ValC;

    printf("Entre com os números para serem somados: ");
    scanf("%d", &ValA);
    scanf("%d", &ValB);

    ValC = ValA + ValB;

    if (ValC > 60) {
        printf("O valor da soma é: %d\n", ValC);
    }

    return 0;
}


