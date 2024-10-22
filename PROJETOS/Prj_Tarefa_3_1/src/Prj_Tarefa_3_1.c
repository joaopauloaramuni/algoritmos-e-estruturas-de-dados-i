/*
 ============================================================================
 Name        : Prj_Tarefa_3_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função para obter o voto do eleitor
int obterVoto() {
	int voto;
	printf("Escolha uma opção:\n");
	printf("1 – Voto Candidato A\n");
	printf("2 – Voto Candidato B\n");
	printf("3 – Apurar Resultado\n");
	printf("4 - Sair\n");
	scanf("%d", &voto);

	return voto;
}

// Função principal
int main(void) {
	int votosCandidatoA = 0;
	int votosCandidatoB = 0;
	int opcao;

	do {
		opcao = obterVoto();

		switch (opcao) {
		case 1:
			votosCandidatoA++;
			printf("Voto para Candidato A registrado!\n");
			break;
		case 2:
			votosCandidatoB++;
			printf("Voto para Candidato B registrado!\n");
			break;
		case 3:
			printf("Resultado:\n");
			printf("Candidato A: %d votos\n", votosCandidatoA);
			printf("Candidato B: %d votos\n", votosCandidatoB);
			if (votosCandidatoA > votosCandidatoB) {
				printf("Candidato A venceu!\n");
			} else if (votosCandidatoB > votosCandidatoA) {
				printf("Candidato B venceu!\n");
			} else {
				printf("Empate!\n");
			}
			break;
		case 4:
			printf("Saindo do programa...\n");
			break;
		default:
			printf("Opção inválida! Tente novamente.\n");
		}

	} while (opcao != 4);

	return 0;
}
