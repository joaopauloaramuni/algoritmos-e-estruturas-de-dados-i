/*
 ============================================================================
 Name        : Prj_VerificarArrayOrdenado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Função recursiva para verificar se um array está ordenado de forma crescente
int estaOrdenado(int array[], int tamanho) {
	if (tamanho <= 1)
		return 1;
	if (array[tamanho - 1] < array[tamanho - 2])
		return 0;
	return estaOrdenado(array, tamanho - 1);
}

int main(void) {
	int arr[] = {1, 2, 3, 5, 4};
	int tamanho = sizeof(arr) / sizeof(arr[0]);
	//printf("Tamanho: %d", tamanho);
	int resultado = estaOrdenado(arr, tamanho);
	if(resultado == 1){
		printf("Todos os elementos do array estão ordenados de forma crescente.");
	}else{
		printf("O array não está ordenado de forma crescente.");
	}
	return 0;
}
