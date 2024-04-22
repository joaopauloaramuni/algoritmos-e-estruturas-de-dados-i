/*
 ============================================================================
 Name        : Prj_Pali+File.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char str[], int left, int right) {
	return (left >= right) ?
			1 :
			(str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}
int main(void) {
	// Abre o arquivo para escrita
	FILE *arquivo = fopen("exemplo.txt", "w");
	// Verifica se o arquivo foi aberto com sucesso para escrita
	if (arquivo != NULL) {
		int opcao = 1;
		do {
			char palavra[100];
			char resultado[100];
			printf("Digite uma palavra: ");
			fflush(stdout);
			scanf("%s", palavra);
			int tamanho = strlen(palavra);
			if (isPalindrome(palavra, 0, tamanho - 1)) { // Verificar se é um palíndromo
				sprintf(resultado, "A palavra %s é um palíndromo.\n", palavra);
				fprintf(arquivo, resultado);
			} else {
				sprintf(resultado, "A palavra %s não é um palíndromo.\n",
						palavra);
				fprintf(arquivo, resultado);
			}
			printf("Deseja continuar? sim=1, sair=0: ");
			fflush(stdout);
			scanf("%d", &opcao);
		} while (opcao != 0);

		// Fecha o arquivo de escrita
		fclose(arquivo);
		printf("Texto gravado com sucesso.\n");
	} else {
		// Se houver erro na abertura do arquivo para escrita
		printf("Erro ao abrir o arquivo para escrita.\n");
		return 1; // Retorna um código de erro
	}

	// Abre o arquivo para leitura
	arquivo = fopen("exemplo.txt", "r");

	// Verifica se o arquivo foi aberto com sucesso para leitura
	if (arquivo != NULL) {
		char linha[100]; // Define um buffer para armazenar a linha lida

		// Lê e imprime cada linha do arquivo
		while (fgets(linha, sizeof(linha), arquivo) != NULL) {
			printf("%s", linha);
		}

		// Fecha o arquivo de leitura
		fclose(arquivo);
	} else {
		// Se houver erro na abertura do arquivo para leitura
		printf("Erro ao abrir o arquivo para leitura.\n");
		return 1; // Retorna um código de erro
	}

	return 0;
}

