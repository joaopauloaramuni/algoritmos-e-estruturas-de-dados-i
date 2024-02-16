/*
 ============================================================================
 Name        : Prj_Enum.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Definição do enum para dias da semana
enum DiaSemana {
	DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO
};

int main(void) {
	// Declaração de uma variável do tipo enum DiaSemana
	enum DiaSemana hoje = TERCA;

	// Uso do enum em uma estrutura de controle (switch)
	switch (hoje) {
	case DOMINGO:
		printf("Hoje é domingo.\n");
		break;
	case SEGUNDA:
		printf("Hoje é segunda-feira.\n");
		break;
	case TERCA:
		printf("Hoje é terça-feira.\n");
		break;
	case QUARTA:
		printf("Hoje é quarta-feira.\n");
		break;
	case QUINTA:
		printf("Hoje é quinta-feira.\n");
		break;
	case SEXTA:
		printf("Hoje é sexta-feira.\n");
		break;
	case SABADO:
		printf("Hoje é sábado.\n");
		break;
	default:
		printf("Dia desconhecido.\n");
		break;
	}

	return 0;
}
