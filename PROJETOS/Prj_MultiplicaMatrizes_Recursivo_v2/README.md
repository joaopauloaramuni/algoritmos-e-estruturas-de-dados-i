# Projeto Prj_MultiplicaMatrizes_Recursivo_v2 (C) ✖️

> **Multiplicação de matrizes recursiva (v2)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Segunda versão do [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): em vez de três índices, a função recursiva recebe **uma única posição** (`pos`) e calcula `i`, `j` e `k` a partir dela com divisão e resto.

## 🎯 Conceitos trabalhados

- Linearização de índices (`pos` → `i`, `j`, `k`)
- Recursão de cauda simples (`pos + 1`)
- Matrizes dinâmicas

## 📚 Entendendo o conceito

Este projeto trabalha **Multiplicação de matrizes** e **Recursividade**.

### Multiplicação de matrizes

O produto de uma matriz A (m × n) por uma matriz B (n × p) só existe quando o **número de colunas de A é igual ao número de linhas de B**, e o resultado C tem dimensão m × p. Cada elemento é a soma dos produtos da linha de A pela coluna de B: `C[i][j] = Σ A[i][k] · B[k][j]`.

O algoritmo direto usa três laços aninhados (i, j, k) e custa **O(m·n·p)**, ou O(n³) para matrizes quadradas. Existem algoritmos assintoticamente melhores (Strassen, O(n^2,81)), mas, na prática, o ganho vem de aproveitar o *cache* e o paralelismo, como fazem as bibliotecas BLAS e as GPUs.

#### 🌍 Onde é usado na prática

- Aprendizado de máquina: redes neurais são, essencialmente, multiplicações de matrizes. É por isso que GPUs e TPUs aceleram o treino.
- Computação gráfica: rotacionar, escalar e projetar objetos 3D é multiplicar matrizes de transformação.
- Grafos: elevar a matriz de adjacência a uma potência conta caminhos de um certo comprimento.

#### 💼 Em processos seletivos

Aparece como exercício de laços aninhados e de matrizes dinâmicas, e em perguntas sobre complexidade (por que O(n³)?) e sobre desempenho (ordem dos laços e *cache*).

Perguntas que costumam aparecer:

- Quando o produto de duas matrizes é possível?
- Qual a complexidade do algoritmo direto?
- Por que trocar a ordem dos laços pode acelerar o código?

#### ⏱️ Complexidade

O(m·n·p) de tempo; O(m·p) de memória para o resultado.

#### 🐞 Erros comuns

- Não verificar a compatibilidade das dimensões.
- Não zerar C antes de acumular as somas.
- Esquecer de liberar cada linha de uma matriz alocada com `malloc`.

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

## 🧠 Como funciona o código

```c
// Função recursiva única para multiplicar matrizes
void multiplicarUnicaRec(int **A, int **B, int **C,
                         int pos, int linhasA, int colunasA, int colunasB) {
    int total = linhasA * colunasB * colunasA;
    if (pos >= total) return;

    int i = pos / (colunasB * colunasA);
    int j = (pos / colunasA) % colunasB;
    int k = pos % colunasA;

    C[i][j] += A[i][k] * B[k][j];

    multiplicarUnicaRec(A, B, C, pos + 1, linhasA, colunasA, colunasB);
}
```

São `linhasA × colunasB × colunasA` multiplicações no total, numeradas de `0` até `total - 1`. Para cada `pos`:

```text
i = pos / (colunasB * colunasA)
j = (pos / colunasA) % colunasB
k = pos % colunasA
```

É a mesma ideia de converter um número em "dígitos" de bases diferentes. A recursão fica mais simples, mas faz uma chamada por multiplicação, então a pilha cresce ainda mais que na primeira versão.

## 💻 Exemplo de execução

```text
Digite a quantidade de linhas e colunas da matriz A:
2 3
Digite a quantidade de linhas e colunas da matriz B:
3 2
1 2 3
4 5 6
7 8
9 10
11 12

Matriz A:
   1    2    3 
   4    5    6 

Matriz B:
   7    8 
   9   10 
  11   12 

Matriz C = A x B:
  58   64 
 139  154
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_MultiplicaMatrizes_Recursivo_v2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_MultiplicaMatrizes_Recursivo_v2`:

```bash
gcc src/Prj_MultiplicaMatrizes_Recursivo_v2.c -o Prj_MultiplicaMatrizes_Recursivo_v2
./Prj_MultiplicaMatrizes_Recursivo_v2
```

No Windows, rode `Prj_MultiplicaMatrizes_Recursivo_v2.exe` (ou `.\Prj_MultiplicaMatrizes_Recursivo_v2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_MultiplicaMatrizes_Recursivo_v2
│
├── 📁 src
│   └── Prj_MultiplicaMatrizes_Recursivo_v2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 867: Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [LeetCode 206: Reverse Linked List (versão recursiva)](https://leetcode.com/problems/reverse-linked-list/)
- [Beecrowd 1029: Fibonacci, Quantas Chamadas?](https://judge.beecrowd.com/pt/problems/view/1029)
- [Beecrowd 1153: Fatorial Simples](https://judge.beecrowd.com/pt/problems/view/1153)

## 🔗 Projetos relacionados

- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Matrix multiplication](https://en.wikipedia.org/wiki/Matrix_multiplication)
- [Wikipedia: Strassen algorithm](https://en.wikipedia.org/wiki/Strassen_algorithm)
- [Paulo Feofiloff (IME-USP): recursão e algoritmos recursivos](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
- [VisuAlgo: visualização de recursão](https://visualgo.net/en/recursion)
- [Wikipedia: recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Python Tutor: veja a pilha de chamadas em C](https://pythontutor.com/c.html)

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
