/*
 ============================================================================
 Name        : Prj_Struct_Livro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
	char titulo[50];
	char autor[50];
	char assunto[100];
	int id_livro;
};

int main(void) {

	struct Livro Livro1; // Declaramos Livro1 do tipo Livro
	struct Livro Livro2; // Declaramos Livro2 do tipo Livro

	// especificações do livro 1
	strcpy(Livro1.titulo, "Título genérico");
	strcpy(Livro1.autor, "Autor");
	strcpy(Livro1.assunto, "Um livro genérico");
	Livro1.id_livro = 123;

	// especificações do livro 2
	strcpy(Livro2.titulo, "Outro título genérico");
	strcpy(Livro2.autor, "Autor 2");
	strcpy(Livro2.assunto, "Outro livro genérico");
	Livro2.id_livro = 456;

	// mostrando as informações do livro 1
	printf("Livro 1 titulo : %s\n", Livro1.titulo);
	printf("Livro 1 autor : %s\n", Livro1.autor);
	printf("Livro 1 assunto : %s\n", Livro1.assunto);
	printf("Livro 1 id_livro : %d\n", Livro1.id_livro);

	// mostrando as informações do livro 2
	printf("Livro 2 titulo : %s\n", Livro2.titulo);
	printf("Livro 2 autor : %s\n", Livro2.autor);
	printf("Livro 2 assunto : %s\n", Livro2.assunto);
	printf("Livro 2 id_livro : %d\n", Livro2.id_livro);

	return 0;
}
