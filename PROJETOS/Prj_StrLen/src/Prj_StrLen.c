/*
 ============================================================================
 Name        : Prj_StrLen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char minhaString[] = "Exemplo";

    // Calcula o comprimento da string
    size_t comprimento = strlen(minhaString);

    // Imprime a string e seu comprimento
    printf("String: %s\n", minhaString);
    printf("Comprimento: %zu\n", comprimento);

    return 0;
}
