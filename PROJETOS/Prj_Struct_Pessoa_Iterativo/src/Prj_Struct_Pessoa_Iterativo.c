/*
 ============================================================================
 Name        : Prj_Struct_Pessoa_Iterativo.c
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

// Função iterativa para encontrar a pessoa mais velha
Pessoa encontraMaisVelho(Pessoa Pessoas[], int n) {
    Pessoa maisVelho = Pessoas[0];

    for (int i = 1; i < n; i++) {
        if (Pessoas[i].idade > maisVelho.idade) {
            maisVelho = Pessoas[i];
        }
    }

    return maisVelho;
}

int main(void) {
    Pessoa Pessoas[] = {{"Ana", 30}, {"João", 25}, {"Maria", 35}};
    int n = sizeof(Pessoas) / sizeof(Pessoas[0]);

    Pessoa maisVelho = encontraMaisVelho(Pessoas, n);

    printf("Pessoa mais velha: %s, %d anos\n", maisVelho.nome, maisVelho.idade);

    return 0;
}
