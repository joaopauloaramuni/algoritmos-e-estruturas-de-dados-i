#include <stdio.h>
#include <stdlib.h>

//Q3 - SOMAR OS ELEMENTOS DE UM ARRAY
#include <stdio.h>
#include <stdlib.h>

//Q4 - SOMAR OS ELEMENTOS DE UM ARRAY RECURSIVAMENTE

// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int tamanho) {
	// Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (tamanho == 0)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[tamanho - 1] + somaRecursiva(A, tamanho - 1);
}

// Empilhando as chamadas recursivas na memória
// Ler esse bloco de cima pra baixo
// somaRecursiva(A, 5)
// 5 = A[5 - 1] + somaRecursiva(A, 5 - 1)
// 4 = A[4 - 1] + somaRecursiva(A, 4 - 1)
// 3 = A[3 - 1] + somaRecursiva(A, 3 - 1)
// 2 = A[2 - 1] + somaRecursiva(A, 2 - 1)
// 1 = A[1 - 1] + somaRecursiva(A, 1 - 1)
// 0 = 0

// Desempilhando as chamadas recursas da memória
// somaRecursiva(A, 5)
// Ler esse bloco de baixo pra cima
// 5 = 10 + 20 = 30
// 4 = 8 + 12
// 3 = 6 + 6
// 2 = 4 + 2
// 1 = 2 + 0
// 0 = 0

//Colinha
// 2 + 4 + 6 + 8 + 10 = 30

int main(void) {
    // Definição do array e seu tamanho
    int A[] = {2, 4, 6, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);

    // Chama a função recursiva e armazena o resultado
    int resultado = somaRecursiva(A, n);

    // Imprime o resultado
    printf("A soma dos elementos do array é %d\n", resultado);

    return 0;
}
