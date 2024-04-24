/*
 ============================================================================
 Name        : ed1_velha_JoaoPaulo.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Jogo da Velha, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Jogadores
char jogador1;
char jogador2;
//Tabuleiro
char tabuleiro[3][3];

//-------------------------------------------------------------------------
//Apresenta digitos validos no tabuleiro
void posicoesvalidas(void) {
	printf("\n---------------\n");
	printf("    POSICOES     ");
	printf("\n---------------\n");
	printf("0 0 | 0 1 | 0 2\n");
	printf("  --- --- ---\n");
	printf("1 0 | 1 1 | 1 2\n");
	printf("  --- --- ---\n");
	printf("2 0 | 2 1 | 2 2\n");
	printf("---------------\n");
}
//-------------------------------------------------------------------------
//Preenche o tabuleiro do jogo com espacos (tabuleiro[lin][col] = ' ')
void limpa(void) {
	int lin, col;
	for (lin = 0; lin < 3; lin++) {
		for (col = 0; col < 3; col++) {
			tabuleiro[lin][col] = ' ';
		}
	}
}
//-------------------------------------------------------------------------
//Imprime tabuleiro com jogadas
void imprimejogada(void) {
	int lin, col;

	printf("\n---------------\n");
	printf("    GAME     ");
	printf("\n---------------\n");
	for (lin = 0; lin < 3; lin++) {
		for (col = 0; col < 3; col++) {
			if (col == 2) {
				printf(" %c ", tabuleiro[lin][col]);
			} else {
				printf(" %c |", tabuleiro[lin][col]);
			}
		}
		if (lin != 2) {
			printf("\n--- --- ---\n");
		} else {
			printf("\n");
		}
	}
}
//-------------------------------------------------------------------------
//O jogador escolhe qual simbolo quer utilizar 'x' ou 'o'
void escolhejogador() {

	jogador1 = 1;

	while (jogador1 != 'x' && jogador1 != 'o') {

		printf("\n");
		printf("Simbolo x ou o: ");
		fflush(stdin);
		scanf("%c", &jogador1);

		if (jogador1 != 'x' && jogador1 != 'o') {

			printf("Simbolo incorreto, digite de novo...\n");
		}

	}
	if (jogador1 == 'x') {
		jogador2 = 'o';
	} else if (jogador1 == 'o') {
		jogador2 = 'x';
	}

}
//-------------------------------------------------------------------------
//Registra a jogada do jogador x e imprime ao final a nova situacao do tabuleiro
void registrajogada(int jogador) {

	int lin, col;

	posicoesvalidas();

	printf("Jogada: ");
	fflush(stdin);
	scanf("%d%d", &lin, &col);

	while (tabuleiro[lin][col] != ' ') {

		printf("Local ocupado! Tente outro...\n\n");
		printf("Jogada: ");
		fflush(stdin);
		scanf("%d%d", &lin, &col);
		printf("\n");

	}

	if (jogador == 1) {
		if (jogador1 == 'x') {
			tabuleiro[lin][col] = 'x';
		} else if (jogador1 == 'o') {
			tabuleiro[lin][col] = 'o';
		}
	} else if (jogador == 2) {
		if (jogador2 == 'x') {
			tabuleiro[lin][col] = 'x';
		} else if (jogador2 == 'o') {
			tabuleiro[lin][col] = 'o';
		}
	}

	imprimejogada();

}
//-------------------------------------------------------------------------
//Registra a jogada do Sistema e imprime ao final a nova situacao do tabuleiro
void registrajogada2(int *n) {

	posicoesvalidas();

	int lin, col, a;

	//Inteligencia EASY
	if (*n == 1) {

		lin = rand() % 3;
		col = rand() % 3;

		while (tabuleiro[lin][col] != ' ') {

			lin = rand() % 3;
			col = rand() % 3;

		}
		//Fim do Nivel Easy - Jogadas Randomicas

		printf("Jogada: %d %d", lin, col);

		if (jogador2 == 'x') {
			tabuleiro[lin][col] = 'x';
		} else if (jogador2 == 'o') {
			tabuleiro[lin][col] = 'o';
		}
	}
	//Inteligencia MEDIUM
	else if (*n == 2) {
		for (a = 0; a < 3; a++) {

			//Jogadas de Linha
			if (tabuleiro[a][0] == 'x' && tabuleiro[a][1] == 'x'
					&& tabuleiro[a][2] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[a][2] = 'x';
				} else
					tabuleiro[a][2] = 'o';

				printf("Jogada: %d %d", a, 2);
				a = 4;
			} else if (tabuleiro[a][0] == 'o' && tabuleiro[a][1] == 'o'
					&& tabuleiro[a][2] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[a][2] = 'o';
				} else
					tabuleiro[a][2] = 'x';

				printf("Jogada: %d %d", a, 2);
				a = 4;
			} else if (tabuleiro[a][1] == 'x' && tabuleiro[a][2] == 'x'
					&& tabuleiro[a][0] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[a][0] = 'x';
				} else
					tabuleiro[a][0] = 'o';

				printf("Jogada: %d %d", a, 0);
				a = 4;
			} else if (tabuleiro[a][1] == 'o' && tabuleiro[a][2] == 'o'
					&& tabuleiro[a][0] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[a][0] = 'o';
				} else
					tabuleiro[a][0] = 'x';

				printf("Jogada: %d %d", a, 0);
				a = 4;
			} else if (tabuleiro[a][0] == 'x' && tabuleiro[a][2] == 'x'
					&& tabuleiro[a][1] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[a][1] = 'x';
				} else
					tabuleiro[a][1] = 'o';

				printf("Jogada: %d %d", a, 0);
				a = 4;
			} else if (tabuleiro[a][0] == 'o' && tabuleiro[a][2] == 'o'
					&& tabuleiro[a][1] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[a][1] = 'o';
				} else
					tabuleiro[a][1] = 'x';

				printf("Jogada: %d %d", a, 0);
				a = 4;
			}

			//Jogadas de Coluna
			else if (tabuleiro[0][a] == 'x' && tabuleiro[1][a] == 'x'
					&& tabuleiro[2][a] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[2][a] = 'x';
				} else
					tabuleiro[2][a] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][a] == 'o' && tabuleiro[1][a] == 'o'
					&& tabuleiro[2][a] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[2][a] = 'o';
				} else
					tabuleiro[2][a] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][a] == 'x' && tabuleiro[2][a] == 'x'
					&& tabuleiro[0][a] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[0][a] = 'x';
				} else
					tabuleiro[0][a] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][a] == 'o' && tabuleiro[2][a] == 'o'
					&& tabuleiro[0][a] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[0][a] = 'o';
				} else
					tabuleiro[0][a] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][a] == 'x' && tabuleiro[2][a] == 'x'
					&& tabuleiro[1][a] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[1][a] = 'x';
				} else
					tabuleiro[1][a] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][a] == 'o' && tabuleiro[2][a] == 'o'
					&& tabuleiro[1][a] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[1][a] = 'o';
				} else
					tabuleiro[1][a] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			}

			//Jogadas de Diagonais
			else if (tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x'
					&& tabuleiro[2][2] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[2][2] = 'x';
				} else
					tabuleiro[2][2] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o'
					&& tabuleiro[2][2] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[2][2] = 'o';
				} else
					tabuleiro[2][2] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][1] == 'x' && tabuleiro[2][2] == 'x'
					&& tabuleiro[0][0] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[0][0] = 'x';
				} else
					tabuleiro[0][0] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][1] == 'o' && tabuleiro[2][2] == 'o'
					&& tabuleiro[2][2] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[0][0] = 'o';
				} else
					tabuleiro[0][0] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][0] == 'x' && tabuleiro[2][2] == 'x'
					&& tabuleiro[1][1] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[1][1] = 'x';
				} else
					tabuleiro[1][1] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][0] == 'o' && tabuleiro[2][2] == 'o'
					&& tabuleiro[1][1] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[1][1] = 'o';
				} else
					tabuleiro[1][1] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][2] == 'x' && tabuleiro[1][1] == 'x'
					&& tabuleiro[2][0] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[2][0] = 'x';
				} else
					tabuleiro[2][0] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][2] == 'o' && tabuleiro[1][1] == 'o'
					&& tabuleiro[2][0] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[2][0] = 'o';
				} else
					tabuleiro[2][0] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][1] == 'x' && tabuleiro[2][0] == 'x'
					&& tabuleiro[0][2] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[0][2] = 'x';
				} else
					tabuleiro[0][2] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[1][1] == 'o' && tabuleiro[2][0] == 'o'
					&& tabuleiro[0][2] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[0][2] = 'o';
				} else
					tabuleiro[0][2] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][2] == 'x' && tabuleiro[2][0] == 'x'
					&& tabuleiro[1][1] == ' ') {

				if (jogador2 == 'x') {
					tabuleiro[1][1] = 'x';
				} else
					tabuleiro[1][1] = 'o';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			} else if (tabuleiro[0][2] == 'o' && tabuleiro[2][0] == 'o'
					&& tabuleiro[1][1] == ' ') {

				if (jogador2 == 'o') {
					tabuleiro[1][1] = 'o';
				} else
					tabuleiro[1][1] = 'x';

				printf("Jogada: %d %d", 2, a);
				a = 4;
			}

			//Fim do Nivel Medium - Jogadas de Linhas, colunas e diagonais
		}
		if (a <= 3) {
			lin = rand() % 3;
			col = rand() % 3;

			while (tabuleiro[lin][col] != ' ') {

				lin = rand() % 3;
				col = rand() % 3;

			}
			if (jogador2 == 'x') {
				tabuleiro[lin][col] = 'x';
			} else
				tabuleiro[lin][col] = 'o';

			printf("Jogada: %d %d", lin, col);
		}

		imprimejogada();

	}
	//Inteligencia HARD
	else if (*n == 3) {

		a = 0;

		//Jogada Estrategica
		if (tabuleiro[0][0] == ' ') {

			if (jogador2 == 'x') {
				tabuleiro[0][0] = 'x';
			} else
				tabuleiro[0][0] = 'o';

			printf("Jogada: %d %d", 0, 0);
			a = 4;
		} else if (tabuleiro[0][0] == 'x' && tabuleiro[0][2] == ' ') {
			if (jogador2 == 'x') {
				tabuleiro[0][2] = 'x';
			} else
				tabuleiro[0][2] = 'o';

			printf("Jogada: %d %d", 2, a);
			a = 4;
		} else if (tabuleiro[0][0] == 'o' && tabuleiro[0][2] == ' ') {
			if (jogador2 == 'o') {
				tabuleiro[0][2] = 'o';
			} else
				tabuleiro[0][2] = 'x';

			printf("Jogada: %d %d", 0, 2);
			a = 4;
		} else if (tabuleiro[0][0] == 'x' && tabuleiro[0][2] == 'x'
				&& tabuleiro[2][0] == ' ') {
			if (jogador2 == 'x') {
				tabuleiro[2][0] = 'x';
			} else
				tabuleiro[2][0] = 'o';

			printf("Jogada: %d %d", 2, 0);
			a = 4;
		} else if (tabuleiro[0][0] == 'o' && tabuleiro[0][2] == 'o'
				&& tabuleiro[2][0] == ' ') {
			if (jogador2 == 'o') {
				tabuleiro[2][0] = 'o';
			} else
				tabuleiro[2][0] = 'x';

			printf("Jogada: %d %d", 2, 0);
			a = 4;
		} else if (tabuleiro[0][0] == 'x' && tabuleiro[0][2] == 'x'
				&& tabuleiro[2][0] == 'x' && tabuleiro[1][1] == ' ') {
			if (jogador2 == 'x') {
				tabuleiro[1][1] = 'x';
			} else
				tabuleiro[1][1] = 'o';

			printf("Jogada: %d %d", 1, 1);
			a = 4;
		} else if (tabuleiro[0][0] == 'o' && tabuleiro[0][2] == 'o'
				&& tabuleiro[2][0] == 'o' && tabuleiro[1][1] == ' ') {
			if (jogador2 == 'o') {
				tabuleiro[1][1] = 'o';
			} else
				tabuleiro[1][1] = 'x';

			printf("Jogada: %d %d", 1, 1);
			a = 4;
		} else if (tabuleiro[0][0] == 'x' && tabuleiro[0][2] == 'x'
				&& tabuleiro[2][0] == 'x' && tabuleiro[0][1] == ' ') {
			if (jogador2 == 'x') {
				tabuleiro[0][1] = 'x';
			} else
				tabuleiro[0][1] = 'o';

			printf("Jogada: %d %d", 0, 1);
			a = 4;
		} else if (tabuleiro[0][0] == 'o' && tabuleiro[0][2] == 'o'
				&& tabuleiro[2][0] == 'o' && tabuleiro[0][1] == ' ') {
			if (jogador2 == 'o') {
				tabuleiro[0][1] = 'o';
			} else
				tabuleiro[0][1] = 'x';
			printf("Jogada: %d %d", 0, 1);
			a = 4;
		}
		if (a != 4) {

			for (a = 0; a < 3; a++) {

				//Jogadas de Linha
				if (tabuleiro[a][0] == 'x' && tabuleiro[a][1] == 'x'
						&& tabuleiro[a][2] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[a][2] = 'x';
					} else
						tabuleiro[a][2] = 'o';

					printf("Jogada: %d %d", a, 2);
					a = 4;
				} else if (tabuleiro[a][0] == 'o' && tabuleiro[a][1] == 'o'
						&& tabuleiro[a][2] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[a][2] = 'o';
					} else
						tabuleiro[a][2] = 'x';

					printf("Jogada: %d %d", a, 2);
					a = 4;
				} else if (tabuleiro[a][1] == 'x' && tabuleiro[a][2] == 'x'
						&& tabuleiro[a][0] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[a][0] = 'x';
					} else
						tabuleiro[a][0] = 'o';

					printf("Jogada: %d %d", a, 0);
					a = 4;
				} else if (tabuleiro[a][1] == 'o' && tabuleiro[a][2] == 'o'
						&& tabuleiro[a][0] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[a][0] = 'o';
					} else
						tabuleiro[a][0] = 'x';

					printf("Jogada: %d %d", a, 0);
					a = 4;
				} else if (tabuleiro[a][0] == 'x' && tabuleiro[a][2] == 'x'
						&& tabuleiro[a][1] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[a][1] = 'x';
					} else
						tabuleiro[a][1] = 'o';

					printf("Jogada: %d %d", a, 0);
					a = 4;
				} else if (tabuleiro[a][0] == 'o' && tabuleiro[a][2] == 'o'
						&& tabuleiro[a][1] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[a][1] = 'o';
					} else
						tabuleiro[a][1] = 'x';

					printf("Jogada: %d %d", a, 0);
					a = 4;
				}

				//Jogadas de Coluna
				else if (tabuleiro[0][a] == 'x' && tabuleiro[1][a] == 'x'
						&& tabuleiro[2][a] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[2][a] = 'x';
					} else
						tabuleiro[2][a] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][a] == 'o' && tabuleiro[1][a] == 'o'
						&& tabuleiro[2][a] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[2][a] = 'o';
					} else
						tabuleiro[2][a] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][a] == 'x' && tabuleiro[2][a] == 'x'
						&& tabuleiro[0][a] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[0][a] = 'x';
					} else
						tabuleiro[0][a] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][a] == 'o' && tabuleiro[2][a] == 'o'
						&& tabuleiro[0][a] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[0][a] = 'o';
					} else
						tabuleiro[0][a] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][a] == 'x' && tabuleiro[2][a] == 'x'
						&& tabuleiro[1][a] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[1][a] = 'x';
					} else
						tabuleiro[1][a] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][a] == 'o' && tabuleiro[2][a] == 'o'
						&& tabuleiro[1][a] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[1][a] = 'o';
					} else
						tabuleiro[1][a] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				}

				//Jogadas de Diagonais
				else if (tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x'
						&& tabuleiro[2][2] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[2][2] = 'x';
					} else
						tabuleiro[2][2] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o'
						&& tabuleiro[2][2] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[2][2] = 'o';
					} else
						tabuleiro[2][2] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][1] == 'x' && tabuleiro[2][2] == 'x'
						&& tabuleiro[0][0] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[0][0] = 'x';
					} else
						tabuleiro[0][0] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][1] == 'o' && tabuleiro[2][2] == 'o'
						&& tabuleiro[2][2] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[0][0] = 'o';
					} else
						tabuleiro[0][0] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][0] == 'x' && tabuleiro[2][2] == 'x'
						&& tabuleiro[1][1] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[1][1] = 'x';
					} else
						tabuleiro[1][1] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][0] == 'o' && tabuleiro[2][2] == 'o'
						&& tabuleiro[1][1] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[1][1] = 'o';
					} else
						tabuleiro[1][1] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][2] == 'x' && tabuleiro[1][1] == 'x'
						&& tabuleiro[2][0] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[2][0] = 'x';
					} else
						tabuleiro[2][0] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][2] == 'o' && tabuleiro[1][1] == 'o'
						&& tabuleiro[2][0] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[2][0] = 'o';
					} else
						tabuleiro[2][0] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][1] == 'x' && tabuleiro[2][0] == 'x'
						&& tabuleiro[0][2] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[0][2] = 'x';
					} else
						tabuleiro[0][2] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[1][1] == 'o' && tabuleiro[2][0] == 'o'
						&& tabuleiro[0][2] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[0][2] = 'o';
					} else
						tabuleiro[0][2] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][2] == 'x' && tabuleiro[2][0] == 'x'
						&& tabuleiro[1][1] == ' ') {

					if (jogador2 == 'x') {
						tabuleiro[1][1] = 'x';
					} else
						tabuleiro[1][1] = 'o';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				} else if (tabuleiro[0][2] == 'o' && tabuleiro[2][0] == 'o'
						&& tabuleiro[1][1] == ' ') {

					if (jogador2 == 'o') {
						tabuleiro[1][1] = 'o';
					} else
						tabuleiro[1][1] = 'x';

					printf("Jogada: %d %d", 2, a);
					a = 4;
				}

				//Fim do Nivel Hard - Jogadas de Linhas, colunas, diagonais
				// e Jogada Estrategica
			}
		}

		if (a <= 3) {
			lin = rand() % 3;
			col = rand() % 3;

			while (tabuleiro[lin][col] != ' ') {

				lin = rand() % 3;
				col = rand() % 3;

			}
			if (jogador2 == 'x') {
				tabuleiro[lin][col] = 'x';
			} else
				tabuleiro[lin][col] = 'o';

			printf("Jogada: %d %d", lin, col);
		}
	}

	imprimejogada();

}
//-------------------------------------------------------------------------

//Verifica se deu empate
int verificaempate() {

	if (tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2]
			!= ' ' && tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' '
			&& tabuleiro[1][2] != ' ' && tabuleiro[2][0] != ' '
			&& tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

		printf("Deu Velha! Empate...");
		return 0;
	}

	return 1;
}
//-------------------------------------------------------------------------
//Verifica se jogador x eh o vencedor
int verificavencedor(int i) {

	char jog;

	if (i == 1) {

		jog = jogador1;
	} else if (i == 2) {

		jog = jogador2;
	}

	int a;

	if (jog == 'x') {
		for (a = 0; a < 3; a++) {

			if (tabuleiro[a][0] == 'x' && tabuleiro[a][1] == 'x'
					&& tabuleiro[a][2] == 'x') {

				printf("\n");
				printf("O Jogador que escolheu x VENCEU!");

				a = 3;
			} else if (tabuleiro[0][a] == 'x' && tabuleiro[1][a] == 'x'
					&& tabuleiro[2][a] == 'x') {

				printf("\n");
				printf("O Jogador que escolheu x VENCEU!");

				a = 3;
			} else if (tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x'
					&& tabuleiro[2][2] == 'x') {

				printf("\n");
				printf("O Jogador que escolheu x VENCEU!");

				a = 3;
			} else if (tabuleiro[0][2] == 'x' && tabuleiro[1][1] == 'x'
					&& tabuleiro[2][0] == 'x') {

				printf("\n");
				printf("O Jogador que escolheu x VENCEU!");

				a = 3;
			}

		}
	} else if (jog == 'o') {
		for (a = 0; a < 3; a++) {

			if (tabuleiro[a][0] == 'o' && tabuleiro[a][1] == 'o'
					&& tabuleiro[a][2] == 'o') {

				printf("\n");
				printf("O Jogador que escolheu o VENCEU!");

				a = 3;
			} else if (tabuleiro[0][a] == 'o' && tabuleiro[1][a] == 'o'
					&& tabuleiro[2][a] == 'o') {

				printf("\n");
				printf("O Jogador que escolheu o VENCEU!");

				a = 3;
			} else if (tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o'
					&& tabuleiro[2][2] == 'o') {

				printf("\n");
				printf("O Jogador que escolheu o VENCEU!");

				a = 3;
			} else if (tabuleiro[0][2] == 'o' && tabuleiro[1][1] == 'o'
					&& tabuleiro[2][0] == 'o') {

				printf("\n");
				printf("O Jogador que escolheu o VENCEU!");

				a = 3;
			}
		}
	}

	if (a == 3) {
		return 0;
	} else
		return 1;
}

//-------------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);

	int op = 1, inf = 1, n = 1;

	printf("**** JOGO DA VELHA ****\n\n");
	printf("MENU\n 1 - Single Player\n 2 - Multiplayer\n");
	printf("\n");

	//Single Player - Contra a Máquina
	//Multiplayer - Contra um amigo

	do {
		printf("Opcao: ");
		fflush(stdin);
		scanf("%d", &op);

		if (op != 1 && op != 2) {
			printf("\n");
			printf("Opcao incorreta, digite de novo...\n");
		}
	} while (op != 1 && op != 2);

	if (op == 1) {

		printf("\n");
		printf("NIVEL DE DIFICULDADE\n\n");
		printf(" 1 - EASY\n 2 - MEDIUM\n 3 - HARD\n\n");

		do {
			printf("Opcao: ");
			fflush(stdin);
			scanf("%d", &n);

			if (n != 1 && n != 2 && n != 3) {
				printf("\n");
				printf("Opcao incorreta, digite de novo...\n");
			}
		} while (n != 1 && n != 2 && n != 3);

		//Limpa tabuleiro
		limpa();
		//Imprime jogada
		imprimejogada();
		//Escolhe jogador
		escolhejogador();

		//Repete infinitamente ate que um dos dois jogadores seja vencedor ou seja empate
		while (inf) {

			//Registra jogada para jogador 1
			registrajogada(1);
			//Verifica se jogador 1 eh o vencedor
			if (verificavencedor(1) == 0) {
				//Verifica se deu empate
				inf = verificaempate();
			} else
				inf = 0;
			if (inf == 1) {
				//Registra jogada para o Sistema
				registrajogada2(&n);
				//Verifica se jogador do Sistema eh o vencedor
				if (verificavencedor(2) == 0) {
					//Verifica se deu empate entre o jogador e o Sistema
					inf = verificaempate();
				} else
					inf = 0;
			}
		}
	} else if (op == 2) {

		//Limpa tabuleiro
		limpa();
		//Imprime jogada
		imprimejogada();
		//Escolhe jogador
		escolhejogador();

		//Repete infinitamente ate que um dos dois jogadores seja vencedor ou seja empate
		while (inf) {

			//Registra jogada para jogador 1
			registrajogada(1);
			//Verifica se jogador 1 eh o vencedor
			if (verificavencedor(1) == 0) {
				//Verifica se deu empate
				inf = verificaempate();
			} else
				inf = 0;
			if (inf == 1) {
				//Registra jogada para jogador 2
				registrajogada(2);
				//Verifica se jogador 2 eh o vencedor
				if (verificavencedor(2) == 0) {
					//Verifica se deu empate
					inf = verificaempate();
				} else
					inf = 0;
			}
		}
	}
	return 0;
}
//-------------------------------------------------------------------------
