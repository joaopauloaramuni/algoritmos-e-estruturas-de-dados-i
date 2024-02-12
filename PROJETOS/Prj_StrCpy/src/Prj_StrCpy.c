/*
 ============================================================================
 Name        : Prj_StrCpy.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Necessário para funções relacionadas a strings

int main(void) {
    char string1[] = "Hello"; // Atribuição para um array de char (string)
    char string2[10];         // Declaração de outro array de char (string)
    strcpy(string2, "World"); // Atribuição usando strcpy

    printf("String1: %s\n", string1);
    printf("String2: %s\n", string2);

    return 0;
}
