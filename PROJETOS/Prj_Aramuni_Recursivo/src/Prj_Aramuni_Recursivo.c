/*
 ============================================================================
 Name        : Prj_Aramuni_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A hanoi(disc - 1, orig, aux, dest)
#define B hanoi(disc - 1, aux, dest, orig)
#define C printf("Move disco %d de %c para %c\n", disc, orig, dest)

// Remove a quebra de linha do final da string, se houver
void removeNewline(char str[]) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int palindrome(char str[100], int tam) {
	return (tam <= 1) || (*str == str[tam - 1] && palindrome(str + 1, tam - 2));
}

int strLen(char *orig, int cont) {
	return (*orig++) ? cont++, strLen(orig, cont) : cont;
}

void strCpy(char *str1, char *str2) {
	(*str1) ? *str2 = *str1, str1++, str2++, strCpy(str1, str2) : 0;
}

void strCat(char *str1, char *str2, int p) {
	(*str2) ? str1[p] = *str2, p++, str2++, strCat(str1, str2, p) : 0;
}

void strInverte(char *str1, char *str2, int p, int i, int j) {
	(p != 0) ? (str1++, p--, strInverte(str1, str2, p, i, j)) : (i++, (j++ != i) ? (i--, *str2 = *str1, str1--, str2++, strInverte(str1, str2, p, i, j)) : 0);
}

void strLimpa(char *str1) {
	(*str1) ? *str1 = ' ', str1++, strLimpa(str1) : 0;
}

int contLetra(char palavra[100], int cont, char letra, int i) {
	return (palavra[i] == letra) ? contLetra(palavra, ++cont, letra, ++i) : (palavra[i] ? contLetra(palavra, cont, letra, ++i) : cont);
}

int fatorial(int c) {
	return (c == 0 || c == 1) ? 1 : (c * fatorial(c - 1));
}

int fibonacci(int n) {
	return (n == 0) ? 0 : ((n == 1) ? 1 : (fibonacci(n - 1) + fibonacci(n - 2)));
}

int mdc(int a, int b) {
	return (a == 0) ? b : ((b == 0) ? a : mdc(b, a % b));
}

int powExpo(int base, int expo) {
	return (expo == 0) ? 1 : (expo == 1 ? base : (base * powExpo(base, expo - 1)));
}

void hanoi(int disc, char orig, char dest, char aux) {
	(disc != 1) ? A, C, B : C;
}

int main(void) {
	setbuf(stdout, NULL);
	char str[100], str2[100] = "", str3[100], str4[100] = "", letra;
	int num, num2, p, i;
	int opcao = 0;
	do {
		printf("Menu\n");
		printf("1-Palíndrome\n");
		printf("2-Tamanho da Palavra\n");
		printf("3-Copiar Palavra\n");
		printf("4-Concatenar Palavras\n");
		printf("5-Inverter Palavra\n");
		printf("6-Limpar Palavra\n");
		printf("7-Ocorrência de Letra no Texto\n");
		printf("8-Fatorial\n");
		printf("9-Fibonacci\n");
		printf("10-MDC\n");
		printf("11-Exponencial\n");
		printf("12-Hanoi\n");
		printf("0-Sair\n\n");

		printf("Digite a opção: ");
		fflush(stdin);
		scanf("%d", &opcao);
		switch (opcao) {

		case 1:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			palindrome(str, strLen(str, 0)) ?
					printf("A palavra %s é palíndrome!\n\n", str) :
					printf("A palavra %s não é palíndrome!\n\n", str);
			break;

		case 2:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);
			printf("Tamanho de %s -> %d\n\n", str, strLen(str, 0));
			break;

		case 3:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			strCpy(str, str2);
			printf("Palavra Copiada -> %s\n\n", str2);
			break;

		case 4:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			printf("Digite outra palavra: ");
			fflush(stdin);
			//gets(str3);
			fgets(str3, sizeof(str3), stdin);
			removeNewline(str3);

			p = strLen(str, 0);
			i = strLen(str3, 0);
			strCat(str, str3, p);
			str[i + p] = '\0';
			printf("Palavras Concatenadas -> %s\n\n", str);
			break;

		case 5:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			p = strLen(str, 0);
			i = strLen(str4, 0);
			i = --p;
			strInverte(str, str4, p, i, 0);
			printf("Palavra Invertida -> %s\n\n", str4);
			break;

		case 6:
			printf("\nDigite a palavra: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			strLimpa(str);
			printf("Palavra Limpa -> '%s'\n\n", str);
			break;

		case 7:
			printf("\nDigite o texto: ");
			fflush(stdin);
			//gets(str);
			fgets(str, sizeof(str), stdin);
			removeNewline(str);

			printf("Digite a letra: ");
			fflush(stdin);
			scanf("%c", &letra);
			printf("Ocorrência da letra %c no texto: %d\n\n", letra,
					contLetra(str, 0, letra, 0));
			break;

		case 8:
			printf("\nDigite um número: ");
			fflush(stdin);
			scanf("%d", &num);
			printf("Fatorial de %d = %d\n\n", num, fatorial(num));
			break;

		case 9:
			printf("\nDigite um número: ");
			fflush(stdin);
			scanf("%d", &num);
			printf("Fibonacci de %d = %d\n\n", num, fibonacci(num));
			break;

		case 10:
			printf("\nDigite um número: ");
			fflush(stdin);
			scanf("%d", &num);
			printf("Digite outro número: ");
			fflush(stdin);
			scanf("%d", &num2);
			printf("MDC de %d e %d = %d\n\n", num, num2, mdc(num, num2));
			break;

		case 11:
			printf("\nDigite um número: ");
			fflush(stdin);
			scanf("%d", &num);
			printf("Digite outro número: ");
			fflush(stdin);
			scanf("%d", &num2);
			printf("Exponencial de %d elevado a %d = %d\n\n", num, num2,
					powExpo(num, num2));
			break;

		case 12:
			printf("\nDigite o número de discos: ");
			fflush(stdin);
			scanf("%d", &num);
			printf("\n");
			hanoi(num, 'A', 'B', 'C');
			printf("\nNúmero de movimentos ótimos: %d\n\n",
					powExpo(2, num) - 1);
			break;

		case 0:
			break;
		default:
			printf("\nOpção Inválida.\n\n");
			break;
		}
	} while (opcao != 0);
	printf("\nFim da Aplicação.");

	return 0;
}
