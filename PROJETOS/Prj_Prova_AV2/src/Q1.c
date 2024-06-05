#include <stdio.h>
#include <stdlib.h>

//Q1 - Calcular a média dos elementos de um array
float calcularMedia(int A[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += A[i];
    }
    return soma / n;
}

int main(void) {
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);

    float media = calcularMedia(A, n);

    printf("A média dos elementos do array é: %.2f\n", media);

    return 0;
}
