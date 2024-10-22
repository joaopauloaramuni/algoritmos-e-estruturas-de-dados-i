/*
 ============================================================================
 Name        : Prj_Funcoes_Ponteiros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Função que receba um ponteiro e modifique o valor da variável
//para zero (0)
//Na função main a variável deve ser inicializada com 1
//No final da função main o valor 0 deve ser impresso na tela
void modifica(int *x){
	*x = 0;
}

// Função que realiza a troca de valores usando ponteiros
void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
	int x = 1;
    int a, b;

    // Solicita ao usuário que insira dois números
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    // Mostra os valores antes da troca
    printf("Antes da troca: a = %d, b = %d\n", a, b);

    // Chama a função para realizar a troca de valores
    troca(&a, &b);

    // Mostra os valores após a troca
    printf("Depois da troca: a = %d, b = %d\n", a, b);

    modifica(&x);
    printf("%d", x);
    //printf("%d", &x);

    return 0;
}
