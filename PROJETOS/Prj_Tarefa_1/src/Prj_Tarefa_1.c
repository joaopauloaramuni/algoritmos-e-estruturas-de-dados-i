/*
 ============================================================================
 Name        : Prj_Tarefa_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a soma de quatro números inteiros
int calcularSoma(int num1, int num2, int num3, int num4) {
	return num1 + num2 + num3 + num4;
}

// Função para calcular a média aritmética de três notas
float calcularMedia(float nota1, float nota2, float nota3) {
	return (nota1 + nota2 + nota3) / 3;
}

// Função para calcular o novo salário com aumento de 25%
float calcularNovoSalario(float salario) {
	return salario * 1.25;
}

// Função para calcular o valor do aumento e o novo salário com percentual informado
float calcularAumentoSalario(float salario, float percentual_aumento) {
	float aumento = salario * (percentual_aumento / 100);
	return salario + aumento;
}

// Função para calcular o salário a receber com gratificação e desconto de imposto
float calcularSalarioReceber(float salario_base) {
	float gratificacao = salario_base * 0.05;
	float imposto = salario_base * 0.07;
	return salario_base + gratificacao - imposto;
}

int main(void) {
	// Teste das funções
	int resultadoSoma = calcularSoma(2, 3, 5, 7);
	printf("1) A soma dos números é: %d\n", resultadoSoma);

	float resultadoMedia = calcularMedia(7.5, 8.0, 9.5);
	printf("2) A média aritmética é: %.2f\n", resultadoMedia);

	float salarioInicial = 1000.0;
	float novoSalario = calcularNovoSalario(salarioInicial);
	printf("3) O novo salário é: %.2f\n", novoSalario);

	float percentualAumento = 15.0;
	float novoSalarioComAumento = calcularAumentoSalario(salarioInicial, percentualAumento);
	printf("4) O valor do aumento é: %.2f\n", novoSalarioComAumento - salarioInicial);
	printf("   O novo salário com aumento é: %.2f\n", novoSalarioComAumento);

	float salarioBase = 1200.0;
	float salarioReceber = calcularSalarioReceber(salarioBase);
	printf("5) O salário a receber é: %.2f\n", salarioReceber);

	return 0;
}
