/*
 ============================================================================
 Name        : Prj_IntercalarVetor.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int* vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

int* intercalar(int* vetor1, int* vetor2, int tam1, int tam2) {
    int tamTotal = tam1 + tam2;
    int* vetor3 = (int*) malloc(tamTotal * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Intercala os dois vetores
    while (i < tam1 && j < tam2) {
        vetor3[k++] = vetor1[i++];
        vetor3[k++] = vetor2[j++];
    }

    // Copia os elementos restantes de vetor1 (se houver)
    while (i < tam1) {
        vetor3[k++] = vetor1[i++];
    }

    // Copia os elementos restantes de vetor2 (se houver)
    while (j < tam2) {
        vetor3[k++] = vetor2[j++];
    }

    return vetor3;
}

int main(void) {
    int vetor1[3] = {1, 3, 5};
    int vetor2[3] = {2, 4, 6};

    printf("Vetor 1: ");
    imprimirVetor(vetor1, 3);

    printf("Vetor 2: ");
    imprimirVetor(vetor2, 3);

    int* vetorIntercalado = intercalar(vetor1, vetor2, 3, 3);

    printf("Vetor Intercalado: ");
    imprimirVetor(vetorIntercalado, 6);

    free(vetorIntercalado); // Libera a memória alocada

    return 0;
}
