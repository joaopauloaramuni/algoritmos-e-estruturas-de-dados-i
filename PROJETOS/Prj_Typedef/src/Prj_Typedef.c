/*
 ============================================================================
 Name        : Prj_Typedef.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Criando um alias para o tipo 'int' no escopo global
typedef int MeuInteiro;

int main(void) {
    // Usando o novo tipo criado com typedef
    MeuInteiro numero = 13;

    printf("Número: %d\n", numero);

    return 0;
}

