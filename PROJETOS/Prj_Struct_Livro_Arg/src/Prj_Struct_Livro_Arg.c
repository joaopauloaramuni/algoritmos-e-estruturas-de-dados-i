/*
 ============================================================================
 Name        : Prj_Struct_Livro_Arg.c
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

// Protótipo da função (assinatura)
void printLivro(struct Livro livro);

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
	printLivro(Livro1);

	// mostrando as informações do livro 1
	printLivro(Livro2);

	return 0;
}

void printLivro(struct Livro livro) {
	printf("Livro titulo : %s\n", livro.titulo);
	printf("Livro autor : %s\n", livro.autor);
	printf("Livro assunto : %s\n", livro.assunto);
	printf("Livro id_livro : %d\n", livro.id_livro);
}
