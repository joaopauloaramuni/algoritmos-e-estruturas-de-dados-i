/*
 ============================================================================
 Name        : Prj_File_Struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
struct ExemploStruct {
	int numero;
	float decimal;
	char texto[50];
};

int main(void) {
	// Abre o arquivo para escrita binária
	FILE *arquivo = fopen("exemplo_struct.bin", "wb");

	// Verifica se o arquivo foi aberto com sucesso
	if (arquivo != NULL) {
		// Cria uma instância da estrutura
		struct ExemploStruct dadosParaGravar = { 13, 3.14,
				"Estrutura de exemplo" };

		// Escreve a estrutura no arquivo
		fwrite(&dadosParaGravar, sizeof(struct ExemploStruct), 1, arquivo);

		// Fecha o arquivo
		fclose(arquivo);
		printf("Estrutura gravada com sucesso.\n");
	} else {
		// Se houver erro na abertura do arquivo
		printf("Erro ao abrir o arquivo para escrita.\n");
	}

	// Abre o arquivo para leitura binária
	FILE *arquivoLeitura = fopen("exemplo_struct.bin", "rb");

	// Verifica se o arquivo foi aberto com sucesso
	if (arquivoLeitura != NULL) {
		// Cria uma instância da estrutura para armazenar os dados lidos
		struct ExemploStruct dadosLidos;

		// Lê a estrutura do arquivo
		fread(&dadosLidos, sizeof(struct ExemploStruct), 1, arquivoLeitura);

		// Fecha o arquivo de leitura
		fclose(arquivoLeitura);

		// Exibe os dados lidos
		printf("Dados lidos da estrutura: Numero: %d, Decimal: %.2f, Texto: %s\n",
				dadosLidos.numero, dadosLidos.decimal, dadosLidos.texto);
	} else {
		// Se houver erro na abertura do arquivo de leitura
		printf("Erro ao abrir o arquivo para leitura.\n");
	}

	return 0;
}
