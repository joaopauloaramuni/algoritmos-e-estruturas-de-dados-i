/*
 ============================================================================
 Name        : Prj_ContarDigitos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função que conta o número de dígitos de um número inteiro
void contarDigitos(int *numero, int *quantidade) {
    int n = *numero;
    *quantidade = 0;

    // Se o número for zero, conta como um dígito
    if (n == 0) {
        *quantidade = 1;
        return;
    }

    // Conta os dígitos
    while (n != 0) {
        n /= 10; // Remove o último dígito
        (*quantidade)++; // Incrementa o contador
    }
}

int main(void) {
    int numero = 12345;
    int quantidadeDeDigitos;

    // Chama a função para contar os dígitos
    contarDigitos(&numero, &quantidadeDeDigitos);

    // Exibe o resultado
    printf("Número: %d\n", numero);
    printf("Quantidade de dígitos: %d\n", quantidadeDeDigitos);

    return 0;
}

