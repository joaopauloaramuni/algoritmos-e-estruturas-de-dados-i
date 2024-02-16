/*
 ============================================================================
 Name        : Prj_Union_Struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Definição da union
union DadosAdicionais {
	int valorInteiro;
	float valorFlutuante;
	char texto[20];
};

// Definição da struct com uma union
struct Pessoa {
	char nome[50];
	int idade;
	union DadosAdicionais dadosExtras;
};

int main(void) {
	// Criando uma instância da struct Pessoa
	struct Pessoa pessoa1 = { "João", 25, { .valorInteiro = 123} };
	struct Pessoa pessoa2 = { "Maria", 30, { .valorFlutuante = 42.0f } };
	struct Pessoa pessoa3 = { "Carlos", 22, { .texto = "Texto Extra" } };

	// Exibindo informações das pessoas
	printf("Nome: %s, Idade: %d, Dados Extras: %d\n", pessoa1.nome,
			pessoa1.idade, pessoa1.dadosExtras.valorInteiro);
	printf("Nome: %s, Idade: %d, Dados Extras: %.2f\n", pessoa2.nome,
			pessoa2.idade, pessoa2.dadosExtras.valorFlutuante);
	printf("Nome: %s, Idade: %d, Dados Extras: %s\n", pessoa3.nome,
			pessoa3.idade, pessoa3.dadosExtras.texto);

	return 0;
}
