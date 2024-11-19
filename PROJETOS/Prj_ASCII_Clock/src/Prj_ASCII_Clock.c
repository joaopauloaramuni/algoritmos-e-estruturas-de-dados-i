/*
 ============================================================================
 Name        : Prj_ASCII_Clock.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Para a função sleep

// Representação ASCII para os dígitos 0-9
const char *ascii_digits[10][3] = {
    {" _ ", "| |", "|_|"}, // 0
    {"   ", "  |", "  |"}, // 1
    {" _ ", " _|", "|_ "}, // 2
    {" _ ", " _|", " _|"}, // 3
    {"   ", "|_|", "  |"}, // 4
    {" _ ", "|_ ", " _|"}, // 5
    {" _ ", "|_ ", "|_|"}, // 6
    {" _ ", "  |", "  |"}, // 7
    {" _ ", "|_|", "|_|"}, // 8
    {" _ ", "|_|", " _|"}  // 9
};

// Função para imprimir a hora atual em ASCII
void print_time_ascii() {
    time_t agora = time(NULL);
    struct tm *hora_local = localtime(&agora);

    // Obtém hora, minutos e segundos
    int hora = hora_local->tm_hour;
    int minutos = hora_local->tm_min;
    int segundos = hora_local->tm_sec;

    // Converte os números para string para fácil manipulação
    char time_string[7];
    snprintf(time_string, sizeof(time_string), "%02d%02d%02d", hora, minutos, segundos);

    // Monta as 3 linhas da saída ASCII
    char linhas[3][100] = {"", "", ""};
    for (int i = 0; time_string[i] != '\0'; i++) {
        int digito = time_string[i] - '0'; // Converte char para índice numérico
        for (int j = 0; j < 3; j++) {
            strcat(linhas[j], ascii_digits[digito][j]);
            strcat(linhas[j], "  "); // Espaço entre os números
        }
    }

    // Exibe as linhas
    for (int i = 0; i < 3; i++) {
        printf("\033[1;32m%s\033[0m\n", linhas[i]); // Cor verde no texto
    }
}

int main() {
    while (1) {
        printf("\033[H\033[J"); // Limpa a tela
        print_time_ascii();
        sleep(1); // Atualiza a cada segundo
    }

    return 0;
}
