# Projeto Prj_Fatorial_Recursivo (C) ❗

> **Fatorial recursivo**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula o fatorial de 5 (`5! = 120`) de **três** formas: recursiva tradicional, recursiva em uma linha com operador ternário e iterativa com `for`. O `main` usa a versão recursiva.

## 🎯 Conceitos trabalhados

- Caso base e passo recursivo
- Pilha de chamadas
- Recursão com operador ternário
- Comparação entre recursão e laço

## 📚 Entendendo o conceito

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
// Função recursiva padrão
int fatorialRecursivo(int n) {
    // Quarta chamada recursiva: 1 == 0 || 1 == 1 true
    // Terceira chamada recursiva: 2 == 0 || 2 == 1 falso
    // Segunda chamada recursiva: 3 == 0 || 3 == 1 falso
    // Primeira chamada recursiva: 4 == 0 || 4 == 1 falso
    // Chamada do main: 5 == 0 || 5 == 1 falso
    if (n == 0 || n == 1) {
        // Caso base
        return 1;
    } else {
        // Quarta chamada recursiva: 2 * fr(1) = 2 * 1 = 2
        // Terceira chamada recursiva: 3 * fr(2) = 3 * 2 = 6
        // Segunda chamada recursiva: 4 * fr(3) = 4 * 6 = 24
        // Primeira chamada recursiva: 5 * fr(4) = 5 * 24 = 120

        // 5 * (4 * 3 * 2 * 1) = 120
        // 5 * (4 * 3 * 2 * fr(1)) = ?
        // 5 * (4 * 3 * fr(2)) = ?
        // 5 * (4 * fr(3)) = ?
        // 5 * fr(4) = ?
        // fr(5) = ?
        // Leia de baixo pra cima

        return n * fatorialRecursivo(n - 1);
        // Chamada recursiva
    }
}
```

```c
// Função recursiva em uma linha utilizando o operador ternário
int fatorialRecursivoUmaLinha(int c) {
    return (c == 0 || c == 1) ? 1 : (c * fatorialRecursivoUmaLinha(c - 1));
}
```

As chamadas vão sendo empilhadas até o caso base e depois resolvidas de volta:

```text
fr(5) = 5 * fr(4)
        fr(4) = 4 * fr(3)
                fr(3) = 3 * fr(2)
                        fr(2) = 2 * fr(1)
                                fr(1) = 1   ← caso base
                        fr(2) = 2
                fr(3) = 6
        fr(4) = 24
fr(5) = 120
```

Os comentários no código fazem esse mesmo rastreamento, chamada por chamada ("Leia de baixo pra cima"). Com `int`, o maior fatorial que cabe é `12!`; a partir de `13!` o valor estoura.

## 💻 Exemplo de execução

```text
O fatorial de 5 é: 120
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Fatorial_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Fatorial_Recursivo`:

```bash
gcc src/Prj_Fatorial_Recursivo.c -o Prj_Fatorial_Recursivo
./Prj_Fatorial_Recursivo
```

No Windows, rode `Prj_Fatorial_Recursivo.exe` (ou `.\Prj_Fatorial_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Fatorial_Recursivo
│
├── 📁 src
│   └── Prj_Fatorial_Recursivo.c
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

## 🔗 Projetos relacionados

- [Prj_Fibonacci_Recursivo](../Prj_Fibonacci_Recursivo): Fibonacci recursivo
- [Prj_Potencia_Recursiva](../Prj_Potencia_Recursiva): Potência recursiva
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [fatorial](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/fatorial)
- [Fatorial_Normal](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/Fatorial_Normal)
- [Recursividade](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/Recursividade)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

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
