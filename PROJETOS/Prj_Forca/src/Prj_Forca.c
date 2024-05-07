#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PALAVRAS 10
#define TAM_PALAVRA 20

char palavras[MAX_PALAVRAS][TAM_PALAVRA] = {
    "elefante",
    "banana",
    "computador",
    "bicicleta",
    "laranja",
    "programacao",
    "girafa",
    "abacaxi",
    "teclado",
    "eletronico"
};

int main(void) {
    srand(time(NULL));

    char palavra[TAM_PALAVRA];
    char palavraOculta[TAM_PALAVRA];
    int tamanho;
    int tentativas = 6;
    int indicePalavra = rand() % MAX_PALAVRAS;

    strcpy(palavra, palavras[indicePalavra]);
    tamanho = strlen(palavra);

    // Inicializa a palavra oculta
    for (int i = 0; i < tamanho; i++) {
        palavraOculta[i] = '_';
    }
    palavraOculta[tamanho] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");

    while (tentativas > 0) {
        printf("Palavra: %s\n", palavraOculta);
        printf("Tentativas restantes: %d\n", tentativas);

        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int acertos = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                palavraOculta[i] = letra;
                acertos++;
            }
        }

        if (acertos == 0) {
            tentativas--;
            printf("Letra incorreta!\n");
        } else {
            printf("Letra correta!\n");
        }

        if (strcmp(palavra, palavraOculta) == 0) {
            printf("Parabéns, você ganhou! A palavra era: %s\n", palavra);
            break;
        }
    }

    if (tentativas == 0) {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
