# Projeto Prj_Aramuni_Recursivo (C) 🧙

> **Aramuni Recursivo: 12 funções em uma linha**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Um menu com **12 funções recursivas escritas em uma única linha cada**, usando operador ternário e operador vírgula: palíndromo, tamanho, cópia, concatenação, inversão e limpeza de string, contagem de letra, fatorial, Fibonacci, MDC, potência e Torre de Hanói.

É a versão atualizada do [`Aramuni.c`](https://github.com/joaopauloaramuni/c/blob/main/PROJETOS/Aramuni.c), escrito em 2011 quando eu era aluno de Estruturas de Dados na FUMEC, com `fgets` no lugar do antigo `gets` (removido do padrão C11).

## 🎯 Conceitos trabalhados

- Recursão em uma linha com `?:`
- Operador vírgula para várias ações em uma expressão
- Macros `#define` como atalho (`A`, `B`, `C` da Torre de Hanói)
- Aritmética de ponteiros em strings
- Menu com `do-while` + `switch`

## 📚 Entendendo o conceito

Este projeto trabalha **Recursividade**, **Torre de Hanói** e **MDC e o algoritmo de Euclides**.

### Recursividade

Uma função **recursiva** resolve um problema chamando a si mesma para uma versão **menor** do mesmo problema. Toda recursão correta tem duas partes:

1. **Caso base**: a versão tão pequena que a resposta é direta (o fatorial de 0 é 1; uma lista vazia tem soma 0).
2. **Passo recursivo**: reduz o problema e combina o resultado da chamada menor (`n! = n × (n-1)!`).

Cada chamada ganha um espaço próprio na **pilha de chamadas** (*call stack*), com as suas variáveis locais. As chamadas vão sendo empilhadas até o caso base e depois são resolvidas na ordem inversa, "de baixo para cima". Se o caso base nunca é alcançado, a pilha enche e o programa quebra com *stack overflow*.

Todo algoritmo recursivo pode ser reescrito com laços (e uma pilha explícita, se preciso). A recursão vale a pena quando o problema **já é recursivo por natureza**: árvores, divisão e conquista, combinações, *backtracking*.

#### 🌍 Onde é usado na prática

- Percorrer estruturas recursivas: pastas dentro de pastas no sistema de arquivos, o DOM de uma página HTML, um JSON aninhado, árvores de decisão.
- Algoritmos de divisão e conquista: *Merge Sort*, *Quicksort* (veja o artigo de Hoare, de 1961), busca binária.
- *Backtracking*: Sudoku, labirintos, problema das 8 rainhas, gerar permutações.
- Compiladores e interpretadores analisam expressões com funções recursivas (*recursive descent parser*).

#### 💼 Em processos seletivos

Recursão é um dos temas **mais cobrados** em etapas técnicas, de estágio a vagas sênior. Ela aparece sozinha (fatorial, Fibonacci, potência, inverter uma string) e, principalmente, como ferramenta para problemas de árvores, grafos, *backtracking* e programação dinâmica. Os avaliadores costumam pedir para você **explicar a pilha de chamadas**, identificar o caso base e dizer a complexidade de tempo e de memória. Um passo seguinte comum é otimizar o Fibonacci recursivo com **memoização** (guardar resultados já calculados).

Perguntas que costumam aparecer:

- Qual o caso base e o passo recursivo desta função?
- Qual a complexidade do Fibonacci recursivo ingênuo? Como melhorar? (O(2ⁿ) → O(n) com memoização ou laço.)
- O que é *stack overflow* e quando acontece em recursão?
- Converta esta recursão em um laço.
- O que é recursão de cauda (*tail recursion*)?

#### ⏱️ Complexidade

Depende de quantas chamadas são feitas e do trabalho em cada uma. Fatorial e soma de um vetor fazem n chamadas: O(n) de tempo e O(n) de pilha. Fibonacci ingênuo faz duas chamadas por nível: O(2ⁿ). A memória usada pela pilha cresce com a **profundidade** da recursão.

#### 🐞 Erros comuns

- Esquecer o caso base, ou ter um caso base que nunca é atingido (por exemplo, fatorial de número negativo).
- Não reduzir o problema a cada chamada.
- Recalcular os mesmos subproblemas várias vezes (Fibonacci).
- Usar recursão profunda (milhares de níveis) onde um laço simples resolve.

### Torre de Hanói

A Torre de Hanói tem três pinos e `n` discos de tamanhos diferentes empilhados no primeiro pino, do maior (embaixo) ao menor. O objetivo é levar todos para outro pino movendo **um disco por vez** e **nunca colocando um disco maior sobre um menor**.

A solução recursiva é curta: para mover `n` discos de A para B usando C como auxiliar, (1) mova `n-1` discos de A para C, (2) mova o maior disco de A para B, (3) mova os `n-1` discos de C para B. O número mínimo de movimentos é **2ⁿ − 1**: 7 para 3 discos, 1.023 para 10, e mais de 18 quintilhões para 64 (a lenda diz que o mundo acaba quando os monges terminarem a torre de 64 discos).

#### 🌍 Onde é usado na prática

- É o exemplo clássico para ensinar recursão e para mostrar o que é crescimento **exponencial**.
- A mesma estratégia (resolver para n-1, depois juntar) aparece em algoritmos de divisão e conquista.
- Variações são usadas em testes de psicologia cognitiva para avaliar planejamento.

#### 💼 Em processos seletivos

Aparece em entrevistas e provas como exercício de recursão pura: escrever a função, contar os movimentos e justificar por que são 2ⁿ − 1 (a recorrência é T(n) = 2·T(n-1) + 1).

Perguntas que costumam aparecer:

- Escreva a função recursiva que imprime os movimentos.
- Quantos movimentos são necessários para n discos? Prove.
- Qual a complexidade de tempo?

#### ⏱️ Complexidade

O(2ⁿ) movimentos; a pilha de chamadas tem profundidade n.

### MDC e o algoritmo de Euclides

O **máximo divisor comum** de dois inteiros é o maior número que divide os dois. O **algoritmo de Euclides**, descrito por volta de 300 a.C., é um dos algoritmos mais antigos ainda em uso: `mdc(a, b) = mdc(b, a % b)`, até que o resto seja 0. Exemplo: mdc(18, 12) → mdc(12, 6) → mdc(6, 0) = 6.

Ele é rapidíssimo: o número de passos cresce com o logaritmo dos números, e não com o tamanho deles.

#### 🌍 Onde é usado na prática

- Simplificar frações e calcular o MMC (`mmc(a, b) = a / mdc(a, b) * b`).
- Criptografia: a versão estendida do algoritmo calcula o inverso modular usado no RSA.
- Problemas de ciclos e sincronização (quando dois eventos periódicos coincidem).

#### 💼 Em processos seletivos

Aparece em testes técnicos de nível inicial e em maratonas de programação, sozinho ou como parte de problemas com frações e periodicidade.

Perguntas que costumam aparecer:

- Implemente o MDC recursivo e iterativo.
- Como calcular o MMC a partir do MDC?
- Qual a complexidade do algoritmo de Euclides?

#### ⏱️ Complexidade

O(log(min(a, b))).

## 🧠 Como funciona o código

```c
int palindrome(char str[100], int tam) {
    return (tam <= 1) || (*str == str[tam - 1] && palindrome(str + 1, tam - 2));
}
```

```c
int strLen(char *orig, int cont) {
    return (*orig++) ? cont++, strLen(orig, cont) : cont;
}
```

```c
int mdc(int a, int b) {
    return (a == 0) ? b : ((b == 0) ? a : mdc(b, a % b));
}
```

```c
void hanoi(int disc, char orig, char dest, char aux) {
    (disc != 1) ? A, C, B : C;
}
```

| Opção | Função | Ideia recursiva |
| --- | --- | --- |
| 1 | `palindrome` | Pontas iguais e o miolo também é palíndromo |
| 2 | `strLen` | Conta 1 e anda o ponteiro até o `\0` |
| 3 | `strCpy` | Copia um caractere e chama para o próximo |
| 4 | `strCat` | Escreve a segunda string a partir da posição `p` |
| 5 | `strInverte` | Vai até o fim da string e copia voltando |
| 6 | `strLimpa` | Troca cada caractere por espaço |
| 7 | `contLetra` | Soma 1 a cada ocorrência da letra |
| 8 | `fatorial` | `n * fatorial(n - 1)` |
| 9 | `fibonacci` | `fib(n - 1) + fib(n - 2)` |
| 10 | `mdc` | Algoritmo de Euclides: `mdc(b, a % b)` |
| 11 | `powExpo` | `base * powExpo(base, expo - 1)` |
| 12 | `hanoi` | Move `n - 1` discos, o maior, e de novo `n - 1` |

Na Torre de Hanói, as macros deixam a função quase ilegível de propósito: `(disc != 1) ? A, C, B : C;` vira "move `n - 1` para o auxiliar, move o disco, move `n - 1` para o destino". O número de movimentos é `2^n - 1`.

## 💻 Exemplo de execução

```text
Menu
1-Palíndrome
2-Tamanho da Palavra
3-Copiar Palavra
4-Concatenar Palavras
5-Inverter Palavra
6-Limpar Palavra
7-Ocorrência de Letra no Texto
8-Fatorial
9-Fibonacci
10-MDC
11-Exponencial
12-Hanoi
0-Sair

Digite a opção: 8

Digite um número: 5
Fatorial de 5 = 120

(menu)

Digite a opção: 10

Digite um número: 12
Digite outro número: 18
MDC de 12 e 18 = 6

(menu)

Digite a opção: 12

Digite o número de discos: 3

Move disco 1 de A para B
Move disco 2 de A para C
Move disco 1 de B para C
Move disco 3 de A para B
Move disco 1 de C para A
Move disco 2 de C para B
Move disco 1 de A para B

Número de movimentos ótimos: 7

(menu)

Digite a opção: 0

Fim da Aplicação.
```

## ⚠️ Pontos de atenção

- O código usa `fflush(stdin)` para descartar o *Enter* que sobra depois do `scanf`. Isso funciona no Windows (MinGW, usado no laboratório), mas o padrão C não define `fflush` para entrada: no Linux e no macOS o `fgets` lê esse *Enter* sobrando e as opções de texto (1 a 7) recebem uma palavra vazia. Para rodar em qualquer sistema, troque cada `fflush(stdin);` depois de um `scanf` por `while (getchar() != '\n');`. As opções numéricas (8 a 12) funcionam em todos os sistemas.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Aramuni_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Aramuni_Recursivo`:

```bash
gcc src/Prj_Aramuni_Recursivo.c -o Prj_Aramuni_Recursivo
./Prj_Aramuni_Recursivo
```

No Windows, rode `Prj_Aramuni_Recursivo.exe` (ou `.\Prj_Aramuni_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**. O OnlineGDB roda em Linux: veja os **Pontos de atenção**.

## 📂 Estrutura do projeto

```text
📁 Prj_Aramuni_Recursivo
│
├── 📁 src
│   └── Prj_Aramuni_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [LeetCode 206: Reverse Linked List (versão recursiva)](https://leetcode.com/problems/reverse-linked-list/)
- [Beecrowd 1029: Fibonacci, Quantas Chamadas?](https://judge.beecrowd.com/pt/problems/view/1029)
- [Beecrowd 1153: Fatorial Simples](https://judge.beecrowd.com/pt/problems/view/1153)
- [LeetCode 1979: Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)

## 🔗 Projetos relacionados

- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_Ternario](../Prj_Ternario): Operador ternário

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [Aramuni.c](https://github.com/joaopauloaramuni/c/blob/main/PROJETOS/Aramuni.c)
- [FunRecUmReturn](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/FunRecUmReturn)
- [hanoi](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/hanoi)
- [Torre](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/Torre)
- [MDC](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/MDC)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): recursão e algoritmos recursivos](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
- [VisuAlgo: visualização de recursão](https://visualgo.net/en/recursion)
- [Wikipedia: recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Python Tutor: veja a pilha de chamadas em C](https://pythontutor.com/c.html)
- [Wikipedia: Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)
- [Wikipedia: Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

**Ferramentas e referências gerais**

- [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
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
