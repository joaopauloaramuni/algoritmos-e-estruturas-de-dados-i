/*
 ============================================================================
 Name        : Prj_Tarefa_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média das idades
float calcularMediaIdades(int idades[]) {
	float soma = 0;
	for (int i = 0; i < 10; i++) {
		printf("Digite a idade do aluno %d: ", i + 1);
		scanf("%d", &idades[i]);
		soma += idades[i];
	}
	return soma / 10;
}

// Função para encontrar a maior e menor altura
void encontrarMaiorMenorAltura(float alturas[]) {
	float maior;
	float menor;

	printf("Digite a altura do aluno 1: ");
	scanf("%f", &alturas[0]);

	maior = alturas[0];
	menor = alturas[0];

	for (int i = 1; i < 10; i++) {
		printf("Digite a altura do aluno %d: ", i + 1);
		scanf("%f", &alturas[i]);

		if (alturas[i] > maior) {
			maior = alturas[i];
		}
		if (alturas[i] < menor) {
			menor = alturas[i];
		}
	}

	printf("Maior altura: %.2f\n", maior);
	printf("Menor altura: %.2f\n", menor);
}

// Função para multiplicar uma matriz por um valor escalar
void multiplicarMatrizPorEscalar(int matriz[][3], int escalar) {
	printf("Digite os elementos da matriz 3x3:\n");
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &matriz[i][j]);

	printf("Digite o valor escalar: ");
	scanf("%d", &escalar);

	printf("Matriz resultante após multiplicação:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matriz[i][j] * escalar);
		}
		printf("\n");
	}
}

// Função para somar duas matrizes 2x2
void somarMatrizes(int matriz1[][2], int matriz2[][2]) {
	printf("Digite os elementos da primeira matriz 2x2:\n");
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &matriz1[i][j]);

	printf("Digite os elementos da segunda matriz 2x2:\n");
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &matriz2[i][j]);

	printf("Matriz resultante após soma:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", matriz1[i][j] + matriz2[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int idades[10];
	float media;

	printf("### Função 1 ###\n");
	media = calcularMediaIdades(idades);
	printf("Média das idades: %.2f\n", media);

	printf("\n### Função 2 ###\n");
	float alturas[10];
	encontrarMaiorMenorAltura(alturas);

	printf("\n### Função 3 ###\n");
	int matrizEscalar[3][3];
	int escalar;
	multiplicarMatrizPorEscalar(matrizEscalar, escalar);

	printf("\n### Função 4 ###\n");
	int matriz1[2][2], matriz2[2][2];
	somarMatrizes(matriz1, matriz2);

	return 0;
}

