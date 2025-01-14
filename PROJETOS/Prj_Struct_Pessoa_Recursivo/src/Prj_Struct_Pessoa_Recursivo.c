/*
 ============================================================================
 Name        : Prj_Struct_Pessoa_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Pessoa
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Função recursiva para encontrar a pessoa mais velha
Pessoa encontraMaisVelho(Pessoa Pessoas[], int n) {
    if (n == 1)
        return Pessoas[0];

    Pessoa maisVelhoRestante = encontraMaisVelho(Pessoas, n - 1);

    if (Pessoas[n - 1].idade > maisVelhoRestante.idade)
        return Pessoas[n - 1];
    else
        return maisVelhoRestante;
}

int main(void) {
    Pessoa Pessoas[] = {{"Ana", 30}, {"João", 25}, {"Maria", 35}};
    int n = sizeof(Pessoas) / sizeof(Pessoas[0]);

    Pessoa maisVelho = encontraMaisVelho(Pessoas, n);

    printf("Pessoa mais velha: %s, %d anos\n", maisVelho.nome, maisVelho.idade);

    return 0;
}
