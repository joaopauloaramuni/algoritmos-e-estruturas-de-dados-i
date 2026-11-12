# Projeto Prj_Forca (C) 🪢

> **Jogo da forca**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Jogo da forca no console: o programa sorteia uma de 10 palavras, mostra os espaços com `_` e o jogador tem **6 tentativas** de errar.

## 🎯 Conceitos trabalhados

- Matriz de strings com as palavras
- Sorteio com `rand() % MAX_PALAVRAS`
- Revelar letras em uma cópia da palavra
- `strcmp` para detectar a vitória

## 📚 Entendendo o conceito

Este projeto trabalha **Jogos de tabuleiro em console: estado, regras e IA simples** e **Strings em C**.

### Jogos de tabuleiro em console: estado, regras e IA simples

Um jogo como o jogo da velha ou a forca é um bom exercício de **modelagem**: o **estado** do jogo (o tabuleiro, as letras descobertas, as tentativas) fica em variáveis e matrizes, e o programa repete um ciclo **ler jogada → validar → atualizar o estado → verificar fim de jogo → trocar o turno**.

Uma "inteligência artificial" simples para o computador pode seguir regras em ordem de prioridade: ganhar se puder, bloquear se o adversário for ganhar, ocupar uma casa estratégica (centro, cantos) e, por fim, jogar ao acaso. A versão ótima do jogo da velha usa o algoritmo **minimax**, que explora recursivamente todas as jogadas possíveis; com ele o computador nunca perde.

#### 🌍 Onde é usado na prática

- A mesma estrutura de ciclo de jogo e de máquina de estados está em jogos comerciais, em simuladores e em sistemas com fluxo de telas.
- O minimax, com podas alfa-beta, foi a base dos programas de xadrez por décadas.

#### 💼 Em processos seletivos

Projetar um jogo da velha (ou um jogo de cartas) é uma pergunta comum de **design orientado a objetos** e de *live coding*, e verificar o vencedor em uma matriz é um exercício frequente. O minimax aparece em vagas de jogos e em maratonas.

Perguntas que costumam aparecer:

- Verifique se há vencedor em um tabuleiro de jogo da velha.
- Como verificar o vencedor em O(1) a cada jogada?
- Como o computador escolheria a jogada ótima? (minimax)

#### 🐞 Erros comuns

- Não validar se a posição está dentro do tabuleiro e livre.
- Verificar só linhas e colunas e esquecer as diagonais.

### Strings em C

C não tem um tipo `string`: uma string é um **vetor de `char` terminado pelo caractere nulo `'\0'`**. A palavra `"FUMEC"` ocupa 6 bytes, 5 letras mais o `'\0'`. Todas as funções de `<string.h>` dependem desse terminador para saber onde o texto acaba.

| Função | O que faz |
| --- | --- |
| `strlen(s)` | Conta os caracteres até o `'\0'` (sem contá-lo) |
| `strcpy(dest, orig)` | Copia `orig` para `dest`, incluindo o `'\0'` |
| `strcat(dest, orig)` | Acrescenta `orig` no fim de `dest` |
| `strcmp(a, b)` | Compara: 0 se iguais, negativo ou positivo conforme a ordem |

Nenhuma delas confere o tamanho do destino. Por isso estouros de *buffer* em strings estão entre as falhas de segurança mais antigas e mais exploradas.

#### 🌍 Onde é usado na prática

- Processamento de texto: validar CPF ou e-mail, contar palavras, montar mensagens.
- Protocolos de rede baseados em texto (HTTP, SMTP) e formatos como CSV e JSON.
- Falhas históricas de segurança (como o *worm* de Morris, de 1988, que explorou a função `gets`) vieram de strings sem limite de tamanho.

#### 💼 Em processos seletivos

Manipulação de strings é um dos temas mais cobrados: palíndromos, anagramas, inverter palavras, contar caracteres, compressão simples, encontrar uma substring. Em C, também é comum pedirem para **reimplementar** `strlen`, `strcpy` ou `strcmp` sem a biblioteca.

Perguntas que costumam aparecer:

- Implemente `strlen` e `strcpy` com ponteiros.
- Verifique se duas palavras são anagramas.
- Inverta as palavras de uma frase.
- Por que `gets` foi removida da linguagem?

#### ⏱️ Complexidade

`strlen` é O(n), porque precisa percorrer a string até achar o `'\0'`; chamar `strlen` na condição de um `for` deixa o laço O(n²).

#### 🐞 Erros comuns

- Esquecer espaço para o `'\0'`.
- Comparar strings com `==` (compara endereços, não o texto). Use `strcmp`.
- Atribuir com `=` depois da declaração (`nome = "Ana";` não compila). Use `strcpy`.
- Ler com `gets` ou com `scanf("%s")` sem limite. Use `fgets(s, sizeof s, stdin)` ou `scanf("%99s", s)`.

## 🧠 Como funciona o código

```c
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
```

`palavraOculta` começa só com `_` e recebe cada letra certa na posição correspondente. Quando ela fica igual à palavra sorteada (`strcmp(...) == 0`), o jogador vence. O espaço em `scanf(" %c", &letra)` descarta o *Enter* da jogada anterior.

## 💻 Exemplo de execução

```text
Bem-vindo ao jogo da forca!
Palavra: __________
Tentativas restantes: 6
Digite uma letra: a
Letra incorreta!
Palavra: __________
Tentativas restantes: 5
Digite uma letra: e
Letra correta!
Palavra: e_e_______
Tentativas restantes: 5
Digite uma letra: i
Letra correta!
Palavra: e_e____i__
Tentativas restantes: 5
Digite uma letra: o
Letra correta!
Palavra: e_e__o_i_o
Tentativas restantes: 5
Digite uma letra: u
Letra incorreta!
Palavra: e_e__o_i_o
Tentativas restantes: 4
Digite uma letra: r
...
```

## ⚠️ Pontos de atenção

- Repetir uma letra já acertada conta como acerto e não gasta tentativa, e letras maiúsculas contam como erro, já que as palavras estão em minúsculas. Dois bons exercícios: guardar as letras já tentadas e usar `tolower` de `<ctype.h>`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Forca` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Forca`:

```bash
gcc src/Prj_Forca.c -o Prj_Forca
./Prj_Forca
```

No Windows, rode `Prj_Forca.exe` (ou `.\Prj_Forca.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Forca
│
├── 📁 src
│   └── Prj_Forca.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1275: Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)
- [LeetCode 794: Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/)
- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)

## 🔗 Projetos relacionados

- [Prj_Jogo_da_Velha](../Prj_Jogo_da_Velha): Jogo da velha
- [Prj_Rand](../Prj_Rand): Números aleatórios

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe)
- [Wikipedia: Minimax](https://en.wikipedia.org/wiki/Minimax)
- [cppreference: biblioteca de strings (<string.h>)](https://en.cppreference.com/w/c/string/byte)
- [cppreference: strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [cppreference: strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [cppreference: strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)

**Ferramentas e referências gerais**

- [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
- [Python Tutor: execute C passo a passo e veja a memória](https://pythontutor.com/c.html)
- [VisuAlgo: estruturas de dados e algoritmos animados](https://visualgo.net/)
- [OnlineGDB: compile e rode C no navegador](https://www.onlinegdb.com/)
- [Eclipse CDT (IDE usada na disciplina)](https://eclipse.dev/cdt/)
- [GCC: documentação oficial](https://gcc.gnu.org/onlinedocs/)

**Livros**

- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Elsevier.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Campus/Elsevier.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. Elsevier.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
