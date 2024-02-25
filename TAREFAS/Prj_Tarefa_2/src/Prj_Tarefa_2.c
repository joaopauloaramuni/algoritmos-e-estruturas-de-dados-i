/*
 ============================================================================
 Name        : Prj_Tarefa_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

// Função para mostrar os números pares múltiplos de 3 até 1000
void mostrarNumerosParesMultiplosDeTres() {
	printf("Números pares múltiplos de 3 até 1000:\n");
	for (int i = 2; i <= 1000; i += 2) {
		if (i % 3 == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Função para ler 10 números inteiros, calcular a soma e a média
void calcularSomaEMedia() {
	int numeros[10];
	int soma = 0;

	printf("Digite 10 números inteiros:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &numeros[i]);
		soma += numeros[i];
	}

	double media = (double) soma / 10;

	printf("Soma: %d\n", soma);
	printf("Média: %.2lf\n", media);
}

// Função para calcular a área de 4 cômodos de uma casa
void calcularAreaDosComodos() {
	double largura, comprimento, area;

	for (int i = 1; i <= 4; i++) {
		printf("Digite a largura do cômodo %d: ", i);
		scanf("%lf", &largura);

		printf("Digite o comprimento do cômodo %d: ", i);
		scanf("%lf", &comprimento);

		area = largura * comprimento;

		printf("Área do cômodo %d: %.2lf metros quadrados\n", i, area);
	}
}

// Função para calcular o perímetro e a área de um círculo
void calcularPerimetroEAreaDoCirculo() {
	double raio, perimetro, area;

	// Solicitar ao usuário para inserir o valor do raio
	printf("Digite o valor do raio do círculo: ");
	scanf("%lf", &raio);

	// Calcular o perímetro e a área
	perimetro = 2 * PI * raio;
	area = PI * raio * raio;

	// Mostrar os resultados calculados
	printf("Perímetro do círculo: %.2lf\n", perimetro);
	printf("Área do círculo: %.2lf\n", area);
}

// Função para calcular o valor total das prestações ou à vista
void calcularPagamento(double totalGasto) {
    int opcaoPagamento;
    double valorFinal;

    while (1) {
        // Mostrar opções de pagamento
        printf("\nOpções de pagamento:\n");
        printf("1 - À Vista (com 10%% de desconto)\n");
        printf("2 - Parcelado 2x (preço da etiqueta)\n");
        printf("3 - Parcelado de 3x até 10x (3%% de juros ao mês, compras acima de R$300.00)\n");
        printf("Digite a opção desejada (ou -999 para encerrar): ");
        scanf("%d", &opcaoPagamento);

        if (opcaoPagamento == -999) {
            printf("Programa encerrado.\n");
            break;
        }

        // Calcular o valor final com base na opção de pagamento
        switch (opcaoPagamento) {
            case 1:
                valorFinal = totalGasto * 0.9; // À vista com 10% de desconto
                printf("Valor à vista com desconto: R$%.2lf\n", valorFinal);
                break;
            case 2:
                valorFinal = totalGasto; // Parcelado 2x (preço da etiqueta)
                printf("Valor parcelado em 2x: 2x R$%.2lf\n", valorFinal / 2);
                break;
            case 3:
                // Parcelado de 3x até 10x com 3% de juros ao mês (para compras acima de R$300.00)
                if (totalGasto > 300.00) {
                    int numParcelas;
                    printf("Digite o número de parcelas (3 a 10): ");
                    scanf("%d", &numParcelas);

                    if (numParcelas >= 3 && numParcelas <= 10) {
                        valorFinal = totalGasto * (1 + 0.03 * numParcelas);
                        printf("Valor parcelado em %dx: %dx R$%.2lf\n", numParcelas, numParcelas, valorFinal / numParcelas);
                        break;
                    } else {
                        printf("Escolha nova forma de pagamento. ");
                        continue;
                    }
                } else {
                    printf("Escolha nova forma de pagamento. ");
                    continue;
                }
            default:
                printf("Opção inválida. ");
        }
    }
}

int main(void) {
	mostrarNumerosParesMultiplosDeTres();

	calcularSomaEMedia();

	calcularAreaDosComodos();

	calcularPerimetroEAreaDoCirculo();

    double totalGasto;

    while (1) {
        // Solicitar o total gasto pelo cliente
        printf("Digite o total gasto (ou -999 para encerrar): ");
        scanf("%lf", &totalGasto);

        if (totalGasto == -999) {
            printf("Programa encerrado.\n");
            break;
        }

        // Chamar a função para calcular o pagamento
        calcularPagamento(totalGasto);
    }

	return 0;
}
