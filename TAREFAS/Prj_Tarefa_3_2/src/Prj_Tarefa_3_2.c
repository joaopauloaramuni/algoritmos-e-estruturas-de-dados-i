/*
 ============================================================================
 Name        : Prj_Tarefa_3_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a quantidade de cigarros ao longo da vida
int calcularCigarrosAoLongoDaVida(int anosFumando, int cigarrosPorDia) {
    return anosFumando * 365 * cigarrosPorDia;
}

// Função para calcular o total gasto
float calcularTotalGasto(int cigarrosAoLongoDaVida, float precoMaco) {
    return (cigarrosAoLongoDaVida / 20.0) * precoMaco;
}

// Função para calcular o tempo de vida perdido
float calcularTempoVidaPerdido(int cigarrosAoLongoDaVida) {
    // Estimativa de que cada cigarro reduz 11 minutos de vida
    return cigarrosAoLongoDaVida * 11 / 60.0;
}

int main(void) {
    int anosFumando, cigarrosPorDia;
    float precoMaco;

    // Solicitar informações ao usuário
    printf("Digite o número de anos que você fuma: ");
    scanf("%d", &anosFumando);

    printf("Digite o número de cigarros fumados por dia: ");
    scanf("%d", &cigarrosPorDia);

    printf("Digite o preço médio de um maço de cigarros: ");
    scanf("%f", &precoMaco);

    // Calcular a quantidade de cigarros ao longo da vida
    int cigarrosAoLongoDaVida = calcularCigarrosAoLongoDaVida(anosFumando, cigarrosPorDia);

    // Calcular o total gasto
    float totalGasto = calcularTotalGasto(cigarrosAoLongoDaVida, precoMaco);

    // Calcular o tempo de vida perdido
    float tempoVidaPerdido = calcularTempoVidaPerdido(cigarrosAoLongoDaVida);

    // Mostrar os resultados
    printf("\nNúmero de cigarros fumados ao longo da vida: %d\n", cigarrosAoLongoDaVida);
    printf("Total gasto: R$%.2f\n", totalGasto);
    printf("Tempo de vida perdido devido com o hábito de fumar: %.2f horas\n", tempoVidaPerdido);

    return 0;
}
