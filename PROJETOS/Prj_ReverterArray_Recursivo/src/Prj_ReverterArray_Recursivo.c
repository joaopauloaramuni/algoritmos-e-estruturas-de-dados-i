/*
 ============================================================================
 Name        : Prj_ReverterArray_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva para reverter os elementos do array
void reverteArray(int A[], int inicio, int fim) {
    if (inicio >= fim)
        return;

    // Troca os elementos nas posições inicio e fim
    int temp = A[inicio];
    A[inicio] = A[fim];
    A[fim] = temp;

    // Chama a função recursivamente para os próximos elementos
    reverteArray(A, inicio + 1, fim - 1);
}

int main(void) {
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    reverteArray(A, 0, n - 1);

    printf("Array revertido: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
