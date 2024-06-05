#include <stdio.h>
#include <stdlib.h>

//Q3 - SOMAR OS ELEMENTOS DE UM ARRAY
int main(void) {
    // Suponha que o array e seu tamanho já estejam definidos
    int A[] = {2, 4, 6, 8, 10};
    int n = 5; // Número de elementos no array

    // Inicializa a variável de soma
    int soma = 0;

    // Percorre o array e calcula a soma
    for (int i = 0; i < n; i++) {
        soma += A[i];
    }

    // Imprime a soma dos elementos
    printf("A soma dos elementos do array é %d\n", soma);

    return 0;
}
