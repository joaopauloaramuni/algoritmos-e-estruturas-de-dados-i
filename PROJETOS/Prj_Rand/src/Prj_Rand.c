/*
 ============================================================================
 Name        : Prj_Rand.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Gera e imprime um número aleatório no intervalo de 0 a 100
    int numeroAleatorio = rand() % 101;
    printf("Número Aleatório: %d\n", numeroAleatorio);

    return 0;
}
