/*
 ============================================================================
 Name        : Prj_Enum_Struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Definição do enum para representar os dias da semana
enum DiaSemana {
	DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO
};

// Definição da struct com um campo do tipo enum
struct Compromisso {
	char descricao[100];
	enum DiaSemana dia;
	int hora;
};

int main(void) {
	// Criando uma instância da struct Compromisso com um valor do enum
	struct Compromisso compromisso1 = { "Reunião de equipe", SEGUNDA, 14 };
	struct Compromisso compromisso2 = { "Almoço com cliente", QUARTA, 12 };
	struct Compromisso compromisso3 = { "Treino na academia", SEXTA, 18 };

	// Exibindo informações dos compromissos
	printf("Compromisso 1: %s, Dia: %d, Hora: %d\n", compromisso1.descricao,
			compromisso1.dia, compromisso1.hora);
	printf("Compromisso 2: %s, Dia: %d, Hora: %d\n", compromisso2.descricao,
			compromisso2.dia, compromisso2.hora);
	printf("Compromisso 3: %s, Dia: %d, Hora: %d\n", compromisso3.descricao,
			compromisso3.dia, compromisso3.hora);

	return 0;
}
