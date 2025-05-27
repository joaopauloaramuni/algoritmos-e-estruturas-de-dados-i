#include <stdio.h>
#include <stdlib.h>

// Função recursiva única para multiplicar matrizes
void multiplicarUnicaRec(int **A, int **B, int **C,
                         int pos, int linhasA, int colunasA, int colunasB) {
    int total = linhasA * colunasB * colunasA;
    if (pos >= total) return;

    int i = pos / (colunasB * colunasA);
    int j = (pos / colunasA) % colunasB;
    int k = pos % colunasA;

    C[i][j] += A[i][k] * B[k][j];

    multiplicarUnicaRec(A, B, C, pos + 1, linhasA, colunasA, colunasB);
}

// Função para multiplicar matrizes (chama a recursiva e retorna resultado)
int **multiplicaMatrizes(int **matA, int **matB, int linhasA, int linhasB, int colunasA, int colunasB) {
    if (colunasA != linhasB) {
        printf("Multiplicacao impossivel: colunas de A != linhas de B\n");
        return NULL;
    }

    // Aloca matriz C com zeros
    int **matC = malloc(linhasA * sizeof(int *));
    for (int i = 0; i < linhasA; i++) {
        matC[i] = calloc(colunasB, sizeof(int));
    }

    // Chama recursão única
    multiplicarUnicaRec(matA, matB, matC, 0, linhasA, colunasA, colunasB);

    return matC;
}

// Função para imprimir matriz
void imprimirMatriz(int **mat, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int **matA, **matB, **matC;
    int linhasA, linhasB, colunasA, colunasB;

    printf("Digite a quantidade de linhas e colunas da matriz A:\n");
    scanf("%d %d", &linhasA, &colunasA);
    printf("Digite a quantidade de linhas e colunas da matriz B:\n");
    scanf("%d %d", &linhasB, &colunasB);

    matA = malloc(linhasA * sizeof(int*));
    for (int i = 0; i < linhasA; i++) {
        matA[i] = malloc(colunasA * sizeof(int));
        for (int j = 0; j < colunasA; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    matB = malloc(linhasB * sizeof(int*));
    for (int i = 0; i < linhasB; i++) {
        matB[i] = malloc(colunasB * sizeof(int));
        for (int j = 0; j < colunasB; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    matC = multiplicaMatrizes(matA, matB, linhasA, linhasB, colunasA, colunasB);

    if (matC != NULL) {
        printf("\nMatriz A:\n");
        imprimirMatriz(matA, linhasA, colunasA);
        printf("\nMatriz B:\n");
        imprimirMatriz(matB, linhasB, colunasB);
        printf("\nMatriz C = A x B:\n");
        imprimirMatriz(matC, linhasA, colunasB);

        // Libera matriz C
        for (int i = 0; i < linhasA; i++) free(matC[i]);
        free(matC);
    }

    // Libera matrizes A e B
    for (int i = 0; i < linhasA; i++) free(matA[i]);
    free(matA);
    for (int i = 0; i < linhasB; i++) free(matB[i]);
    free(matB);

    return 0;
}
