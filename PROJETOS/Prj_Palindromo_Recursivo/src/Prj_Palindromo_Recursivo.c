/*
 ============================================================================
 Name        : Prj_Palindromo_Recursivo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char str[], int left, int right) {
    return (left >= right) ? 1 : (str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}

int isPalindrome2(char str[], int left, int right) {
	// Quarta chamada recursiva: 3 >= 2 true
	// Terceira chamada recursiva: 2 >= 3 falso
	// Segunda chamada recursiva: 1 >= 4 falso
	// Primeira chamada recursiva: 0 >= 5 falso
	if (left >= right)
        return 1;

	// Quarta chamada recursiva: retornou 1 acima
	// Terceira chamada recursiva: A != A ? falso
	// Segunda chamada recursiva: R != R ? falso
	// Primeira chamada recursiva: A != A ? falso
    if (str[left] != str[right])
        // Verifica se os caracteres nos extremos são iguais
        return 0;

    // Chama recursivamente para o próximo par de caracteres
    return isPalindrome2(str, left + 1, right - 1);
    // Quarta chamada recursiva: ARARA -> R != A (Não chega a fazer esse teste) [left == 3 e right == 2]
    // Terceira chamada recursiva: ARXRA -> A != A [left == 2 e right == 3]
    // Segunda chamada recursiva: AXAXA -> R != R [left == 1 e right == 4]
    // Primeira chamada recursiva: XRARX -> A != A [left == 0 e right == 5]
    // >> ARARA <<
}

int main(void) {
    char palavra[100];
    printf("Digite uma palavra: ");
    fflush(stdout);
    scanf("%s", palavra);

    int tamanho = strlen(palavra);
    printf("Tamanho: %d \n", tamanho);
    // Verificar se é um palíndromo
    if (isPalindrome(palavra, 0, tamanho - 1)) {
        printf("A palavra é um palíndromo.\n");
    } else {
        printf("A palavra não é um palíndromo.\n");
    }

    return 0;
}
