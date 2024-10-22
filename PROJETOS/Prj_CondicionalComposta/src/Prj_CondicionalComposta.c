/*
 ============================================================================
 Name        : Prj_CondicionalComposta.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float Nota1, Nota2, Nota3, NotaF;

    printf("Entre com as notas do aluno: ");
    scanf("%f %f %f", &Nota1, &Nota2, &Nota3);

    NotaF = Nota1 + Nota2 + Nota3;

    if (NotaF >= 60) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
