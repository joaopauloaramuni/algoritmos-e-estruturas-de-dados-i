#include <stdio.h>
#include <stdlib.h>

//Q4 - SOMAR OS ELEMENTOS DE UM ARRAY RECURSIVAMENTE

// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int n, int indice) {
    // Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (indice == n)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[indice] + somaRecursiva(A, n, indice + 1);
}

int main(void) {
    // Definição do array e seu tamanho
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    // Chama a função recursiva e armazena o resultado
    int resultado = somaRecursiva(A, n, 0);

    // Imprime o resultado
    printf("A soma dos elementos do array é %d\n", resultado);

    return 0;
}
