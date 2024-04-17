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
		//linhas = 5
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

void exercicio3(int linhas){
	int espacos, asteriscos;

	// Desenho do losango - parte superior
	for (int i = 1; i <= linhas; i++) {
		// Espaços em branco antes dos asteriscos
		for (espacos = 1; espacos <= linhas - i; espacos++) {
			printf(" ");
		}
		// Asteriscos
		for (asteriscos = 1; asteriscos <= 2 * i - 1; asteriscos++) {
			printf("*");
		}
		printf("\n");
	}

	// Desenho do losango - parte inferior
	for (int i = linhas - 1; i >= 1; i--) {
		// Espaços em branco antes dos asteriscos
		for (espacos = 1; espacos <= linhas - i; espacos++) {
			printf(" ");
		}
		// Asteriscos
		for (asteriscos = 1; asteriscos <= 2 * i - 1; asteriscos++) {
			printf("*");
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

    // Exibe o padrão de asteriscos em forma de losango
    exercicio3(linhas);

    return 0;
}
