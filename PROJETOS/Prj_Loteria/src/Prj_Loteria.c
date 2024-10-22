/*
 ============================================================================
 Name        : Prj_Loteria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para auxiliar a função rand

int main(void) {

	// Inicializa a semente para a função rand() usando o tempo atual
	srand(time(NULL));

	// Gera um número aleatório entre 0 e 100
	int numSorteado = rand() % 101;

	printf("Loteria");
	printf("\n\nEscolha um número entre 0 e 100: ");
	int numEscolhido;
	scanf("%d", &numEscolhido);

	if(numEscolhido == numSorteado){
		printf("\nVocê ganhou!");
	}else{
		printf("\nVocê perdeu! O número sorteado foi: %d", numSorteado);
	}

	return EXIT_SUCCESS;
}
