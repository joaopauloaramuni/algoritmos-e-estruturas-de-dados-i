#include <stdio.h>
#include <stdlib.h>

//Q2 - ENCONTRAR O MAIOR ELEMENTO DE UM ARRAY
int main(void) {
    // Suponha que o array e seu tamanho já estejam definidos
    int A[] = {3, 5, 7, 2, 8};
    int n = 5; // Número de elementos no array

    // Inicializa a variável do maior valor com o primeiro elemento do array
    int maior = A[0];

    // Percorre o array a partir do segundo elemento
    for (int i = 1; i < n; i++) {
        // Se o elemento atual é maior que a variável 'maior', atualiza 'maior'
        if (A[i] > maior) {
            maior = A[i];
        }
    }

    // Imprime o maior valor encontrado no array
    printf("O maior elemento do array é %d\n", maior);

    return 0;
}
