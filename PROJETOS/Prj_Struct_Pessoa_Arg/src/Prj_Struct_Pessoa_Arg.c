/*
 ============================================================================
 Name        : Prj_Struct_Pessoa_Arg.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct { // Cria uma struct para armazenar os dados de uma pessoa
	float Peso;   // define o campo Peso
	int Idade;    // define o campo Idade
	float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado

void ImprimePessoa(Pessoa P){ // declara o parâmetro como uma struct
	printf("Idade: %d  Peso: %.2f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}

int main(void) {
	Pessoa Joao, P2;
	Pessoa Povo[10];

	Joao.Idade = 15;
	Joao.Peso = 60.5;
	Joao.Altura = 1.75;

	Povo[4].Idade = 23;
	Povo[4].Peso = 75.3;
	Povo[4].Altura = 1.89;

	/*Outra vantagem de utilizar struct é a possibilidade de atribuir os dados de uma
	struct para outra, com apenas um comando de atribuição, como neste exemplo: */
	P2 = Povo[4];
	P2.Idade++;

	// chama a função que recebe a struct como parâmetro
	ImprimePessoa(Joao);
	ImprimePessoa(Povo[4]);
	ImprimePessoa(P2);
	return 0;
}

