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

	//Declarando as variáveis
	float peso, altura, imc;

	//Lendo as variáveis do usuário
	printf("Cálculo do IMC\n");
	printf("Digite o peso em kg: ");
	scanf("%f", &peso);
	printf("Digite a altura em metros: ");
	scanf("%f", &altura);

	//Calculando o IMC (Regra de negócio)
	imc = peso / (altura * altura);

	//Exibindo o resultado
	printf("\nSeu IMC é: %.2f", imc);

	//Testando o IMC calculado
	if(imc < 18.5){
		printf("\nVocê está abaixo do peso.");
	}else if(imc >= 18.5 && imc <= 25.0){ //&& AND (e) ------ || OR (ou)
		printf("\nSeu peso está normal.");
	}else if(imc > 25.0 && imc <= 30.0){
		printf("\nVocê está acima do peso.");
	}else if(imc > 30.0){
		printf("\nVocê está obeso.");
	}

	//Saindo do programa
	return EXIT_SUCCESS;
}
