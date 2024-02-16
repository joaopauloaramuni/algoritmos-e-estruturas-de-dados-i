/*
 ============================================================================
 Name        : Prj_Struct_Pessoa_Ponteiro.c
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

void ImprimePessoa(Pessoa P) {
	printf("Idade: %d  Peso: %.2f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}

// Nesta função o parâmetro P é um ponteiro para uma struct
void SetPessoa(Pessoa *P, int idade, float peso, float altura) {
	(*P).Idade = idade;  // o campo pode ser acessado desta forma
	P->Peso = peso;      // ou desta
	P->Altura = altura;
}

int main(void) {
	Pessoa Joao;
	SetPessoa(&Joao, 15, 70.5, 1.75);
	ImprimePessoa(Joao);
	return 0;
}

