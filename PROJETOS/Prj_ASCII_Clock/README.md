# Projeto Prj_ASCII_Clock (C) ⏰

> **Relógio em ASCII**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Um relógio digital no terminal: mostra a hora atual (HHMMSS) com dígitos desenhados em ASCII, em verde, e atualiza a cada segundo.

## 🎯 Conceitos trabalhados

- Matriz de strings com o desenho de cada dígito
- `time` e `localtime` de `<time.h>`
- `snprintf` e `strcat`
- Códigos de escape ANSI para cor e limpar a tela
- `sleep` de `<unistd.h>`

## 📚 Entendendo o conceito

Este projeto trabalha **Terminal: caracteres especiais, códigos ANSI e espera** e **Strings em C**.

### Terminal: caracteres especiais, códigos ANSI e espera

O terminal entende alguns caracteres de controle: `\n` (nova linha), `\t` (tabulação) e `\a` (*alert*, o bipe). Terminais modernos também interpretam **sequências de escape ANSI**, que começam com `\033[`: `\033[2J` limpa a tela, `\033[H` volta o cursor ao topo e `\033[1;32m` liga o verde.

Para esperar um tempo, o correto é pedir ao sistema operacional para suspender o programa (`sleep` no Linux, `Sleep` no Windows). Um laço vazio que conta até um número grande (**espera ocupada**, *busy waiting*) gasta 100% de um núcleo do processador, depende da velocidade da máquina e pode ser removido inteiro pelo otimizador do compilador.

#### 🌍 Onde é usado na prática

- Ferramentas de linha de comando coloridas (Git, compiladores, *test runners*) e barras de progresso.
- Interfaces de texto completas (`htop`, `vim`) usam as mesmas sequências, normalmente por meio da biblioteca ncurses.

#### 💼 Em processos seletivos

Pouco cobrado diretamente; *busy waiting* aparece em perguntas de sistemas operacionais e concorrência.

Perguntas que costumam aparecer:

- Qual a diferença entre `sleep` e um laço de espera?
- O que é espera ocupada e quando ela é aceitável?

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
```

Cada dígito é desenhado em 3 linhas (`ascii_digits[d][0..2]`). A função transforma a hora em uma string de 6 caracteres, por exemplo `"143507"`, e monta as 3 linhas da tela juntando os pedaços de cada dígito. `\033[H\033[J` volta o cursor ao topo e limpa a tela; `\033[1;32m` liga o verde e `\033[0m` volta à cor normal.

## 💻 Exemplo de execução

```text
           _    _    _    _
  |  |_|   _|  |_   | |    |
  |    |   _|   _|  |_|    |

(14:35:07, em verde, redesenhado a cada segundo)
```

## ⚠️ Pontos de atenção

- `<unistd.h>` e `sleep` são do padrão POSIX (Linux e macOS). No Windows com MinGW, troque por `#include <windows.h>` e `Sleep(1000)` (com S maiúsculo, em milissegundos). Os códigos de cor funcionam no Terminal do Windows 10 ou mais novo, mas podem aparecer como texto no console do Eclipse.
- O programa não termina sozinho: use **Ctrl + C**.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ASCII_Clock` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ASCII_Clock`:

```bash
gcc src/Prj_ASCII_Clock.c -o Prj_ASCII_Clock
./Prj_ASCII_Clock
```

No Windows, rode `Prj_ASCII_Clock.exe` (ou `.\Prj_ASCII_Clock.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ASCII_Clock
│
├── 📁 src
│   └── Prj_ASCII_Clock.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)

## 🔗 Projetos relacionados

- [Prj_WhileInfinito](../Prj_WhileInfinito): Laço infinito
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [barulhim](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/barulhim)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [Wikipedia: Busy waiting](https://en.wikipedia.org/wiki/Busy_waiting)
- [cppreference: sequências de escape](https://en.cppreference.com/w/c/language/escape)
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
