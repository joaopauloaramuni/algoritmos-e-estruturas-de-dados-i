/*
 ============================================================================
 Name        : Prj_Soma_Recursiva_Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva para somar os elementos de um array
int somaArray(int arr[], int n) {
    // Caso base: se o tamanho do array é 0, retorna 0
    if (n <= 0)
        return 0;
    // Caso recursivo: soma o último elemento ao resultado da soma dos elementos restantes
    return arr[n-1] + somaArray(arr, n-1);
}
int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int resultado = somaArray(arr, tamanho);
    printf("A soma dos elementos do array é %d\n", resultado);
    return 0;
}

