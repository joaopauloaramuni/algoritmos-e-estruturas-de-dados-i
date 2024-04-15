/*
 ============================================================================
 Name        : Prj_Triangulo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void exercicio1(int linhas) {
	// Exibe o padrão de asteriscos em forma de triângulo
	printf("Padrão de asteriscos:\n");
	for (int i = 1; i <= linhas; i++) {
		// Loop para exibir os espaços em branco antes dos asteriscos
		for (int j = 1; j <= linhas - i; j++) {
			printf(" ");
		}
		// Loop para exibir os asteriscos
		for (int k = 1; k <= 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}

void exercicio2(int linhas) {
	// Exibe o padrão de asteriscos em forma de triângulo
	printf("Padrão de asteriscos:\n");
	for (int i = 1; i <= linhas; i++) {
		// Loop para exibir os espaços em branco antes dos asteriscos
		for (int j = 1; j <= linhas - i; j++) {
			printf(" ");
		}
		// Loop para exibir os caracteres nas extremidades e os asteriscos internos
		for (int k = 1; k <= 2 * i - 1; k++) {
			if (k == 1 || k == 2 * i - 1) {
				printf("#");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
}

int main(void) {
    int linhas;

    // Solicita ao usuário para inserir um número inteiro positivo
    printf("Digite o número de linhas (maior que 0): ");
    scanf("%d", &linhas);

    // Exibe o padrão de asteriscos em forma de triângulo
	exercicio1(linhas);

	// Exibe o padrão de asteriscos em forma de triângulo
	// onde todos os asteriscos das extremidades serão substituídos pelo caractere #
	exercicio2(linhas);

	return 0;
}
