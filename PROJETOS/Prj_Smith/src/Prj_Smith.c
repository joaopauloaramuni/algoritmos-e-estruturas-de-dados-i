/*
 ============================================================================
 Name        : Prj_Smith.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Um número de Smith é um número composto cuja soma dos dígitos é igual à soma dos dígitos dos seus fatores primos.
//Para determinar se um número 𝑛 n é um número de Smith, você pode seguir os seguintes passos:
// 1) Calcular a soma dos dígitos de 𝑛 n.
// 2) Encontrar os fatores primos de 𝑛 n e calcular a soma dos dígitos desses fatores.
// 3) Comparar as duas somas.
// Exemplos de números de Smith: 4, 22, 27, 58, 85, 94

// Função para calcular a soma dos dígitos de um número
int soma_digitos(int num) {
    int soma = 0;
    while (num > 0) {
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

// Função para verificar se um número é primo
int eh_primo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Função para calcular a soma dos dígitos dos fatores primos de um número
int soma_digitos_fatores_primos(int num) {
    int soma = 0;
    int fator = 2;
    while (num > 1) {
        while (num % fator == 0) {
            soma += soma_digitos(fator);
            num /= fator;
        }
        fator++;
        while (!eh_primo(fator)) {
            fator++;
        }
    }
    return soma;
}

// Função principal para verificar se um número é um número de Smith
int eh_numero_smith(int num) {
    if (num <= 1 || eh_primo(num)) return 0;  // Números primos e 1 não são considerados
    int somaNum = soma_digitos(num);
    int somaFatores = soma_digitos_fatores_primos(num);
    return somaNum == somaFatores;
}

int main(void) {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    if (eh_numero_smith(num)) {
        printf("%d é um número de Smith.\n", num);
    } else {
        printf("%d não é um número de Smith.\n", num);
    }
    return 0;
}
