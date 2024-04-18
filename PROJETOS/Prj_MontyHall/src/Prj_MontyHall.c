/*
 ============================================================================
 Name        : Prj_MontyHall.c
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

	printf("Bem-vindo ao jogo Monty Hall!");
	printf("\n\nEscolha uma porta (1, 2 ou 3): ");
	int portaEscolhida;
	scanf("%d", &portaEscolhida);

	// Validar a entrada do usuário
	if (portaEscolhida < 1 || portaEscolhida > 3) {
		printf("\nEscolha inválida. O número da porta deve ser 1, 2 ou 3.");
	} else {
		// Definir a porta premiada

		// Inicializa a semente para a função rand() usando o tempo atual
		srand(time(NULL));

		// Gera um número aleatório entre 1 e 3
		int portaPremiada = rand() % 3 + 1;
		// printf("\nA porta premiada é: %d", portaPremiada); //comente essa linha para ficar divertido

		// Simulação da abertura de uma das outras portas vazias
		int portaVazia = -1;
		do {
			portaVazia = rand() % 3 + 1;
		} while (portaVazia == portaPremiada || portaVazia == portaEscolhida);
		printf("\nO apresentador abriu a porta %d, que está vazia.", portaVazia);

		// Oferecer a opção de trocar de porta ou não
		printf("\n\nVocê deseja trocar para a outra porta? (s/n): ");
		char opcao;
		scanf(" %c", &opcao);

		// Verifica se a opção é 's' para decidir se deve trocar a porta
		int trocarPorta = (opcao == 's' || opcao == 'S');

		// Determinar a nova porta escolhida (caso o jogador opte por trocar)
		int portaEscolhidaOriginal = portaEscolhida;
		if (trocarPorta) {
			do {
				portaEscolhida = rand() % 3 + 1;
			} while (portaEscolhida == portaVazia
					|| portaEscolhida == portaEscolhidaOriginal);
			printf("\nVocê trocou para a porta %d.", portaEscolhida);
			//portaEscolhida agora é a porta nova que foi trocada
			//portaEscolhidaOriginal é a porta escolhida no início do jogo, antes da troca
		}

		// Determinar o resultado final
		if (portaEscolhida == portaPremiada) {
			printf("\nVocê ganhou! Parabéns!");
		} else {
			printf("\nVocê perdeu. A porta premiada era a %d.", portaPremiada);
		}

		// Resultado final
		printf("\n\nPorta premiada: %d", portaPremiada);
		printf("\nPorta vazia: %d", portaVazia);
		printf("\nPorta escolhida: %d", portaEscolhida);
		printf("\nPorta escolhida Originalmente: %d", portaEscolhidaOriginal);
	}

	return EXIT_SUCCESS;
}
