/*
 ============================================================================
 Name        : Prj_IMC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float peso, altura, imc;

	printf("Cálculo do IMC\n");
	printf("Digite o peso em kg: ");
	scanf("%f", &peso);
	printf("Digite a altura em metros: ");
	scanf("%f", &altura);

	//Calcular IMC
	imc = peso / (altura * altura);

	//Exibir resultado
	printf("\nSeu IMC é: %.2f", imc);

	if(imc < 18.5){
		printf("\nVocê está abaixo do peso.");
	}else if(imc >= 18.5 && imc <= 25.0){
		printf("\nSeu peso está normal.");
	}else if(imc > 25.0 && imc <= 30.0){
		printf("\nVocê está acima do peso.");
	}else if(imc > 30.0){
		printf("\nVocê está obeso.");
	}

	return EXIT_SUCCESS;
}
