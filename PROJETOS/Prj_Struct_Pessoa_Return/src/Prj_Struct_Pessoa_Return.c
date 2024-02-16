/*
 ============================================================================
 Name        : Prj_Struct_Pessoa_Return.c
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

Pessoa SetPessoa(int idade, float peso, float altura) {
	Pessoa P;
	P.Idade = idade;
	P.Peso = peso;
	P.Altura = altura;
	return P; // retorna a struct contendo os dados passados por parâmetro
}

void ImprimePessoa(Pessoa P) { // declara o parâmetro como uma struct
	printf("Idade: %d  Peso: %.2f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}

int main(void) {
	Pessoa Joao;
	Joao = SetPessoa(15, 60.5, 1.75); // atribui o retorno da função a uma variável struct
	ImprimePessoa(Joao);
	return 0;
}

