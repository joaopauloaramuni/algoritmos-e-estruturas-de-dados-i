# Projeto Prj_Prova_AV2 (C) 📝

> **Prova AV2: arrays e recursão**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução das questões da **prova AV2**. Cada questão é um arquivo `.c` com o seu próprio `main`:

| Arquivo | Questão |
| --- | --- |
| `Q1.c` | Média dos elementos de um array (com função) |
| `Q2.c` | Maior elemento de um array |
| `Q3.c` | Soma dos elementos de um array |
| `Q4_Solucao_1.c` | Soma recursiva, avançando um índice do início para o fim |
| `Q4_Solucao_2.c` | Soma recursiva, diminuindo o tamanho do fim para o início |

## 🎯 Conceitos trabalhados

- Percurso de arrays
- Máximo de um array
- Recursão com caso base e passo recursivo
- Duas formas de dividir o mesmo problema recursivo

## 📚 Entendendo o conceito

Este projeto trabalha **Vetores (arrays)** e **Recursividade**.

### Vetores (arrays)

Um **vetor** guarda vários valores do mesmo tipo em posições **contíguas** de memória, acessadas por um índice que começa em **0**. Em `int v[5];` os índices válidos vão de `v[0]` a `v[4]`.

Acessar `v[i]` custa O(1) porque o endereço é calculado direto: início do vetor + `i` × tamanho do elemento. Em compensação, o tamanho é fixo, e C **não verifica os limites**: ler `v[5]` não dá erro de compilação, apenas lê o que estiver na memória ao lado. Quando um vetor é passado para uma função, ele vira um ponteiro para o primeiro elemento, e o tamanho precisa ir junto como parâmetro.

#### 🌍 Onde é usado na prática

- Qualquer lista de tamanho conhecido: notas de uma turma, leituras de um sensor, *pixels* de uma linha de imagem.
- A memória contígua aproveita o *cache* do processador; por isso percorrer um vetor é muito mais rápido que percorrer uma lista encadeada.
- É a base de estruturas mais sofisticadas: pilhas e filas em vetor, *heaps*, tabelas *hash*.

#### 💼 Em processos seletivos

Vetores são o tema mais frequente em entrevistas técnicas. Os padrões que mais caem são **dois ponteiros**, **janela deslizante**, **soma de prefixos** e o uso de *hash* para contar elementos.

Perguntas que costumam aparecer:

- Some, calcule a média e encontre o maior elemento.
- Inverta um vetor no próprio lugar.
- Dado um vetor e um alvo, encontre dois números que somam o alvo (Two Sum).
- Por que o índice começa em 0?

#### ⏱️ Complexidade

Acesso por índice O(1); busca de um valor O(n); inserir no meio O(n), porque é preciso deslocar os elementos.

#### 🐞 Erros comuns

- Ler ou escrever fora dos limites (`i <= n`).
- Usar `sizeof(v) / sizeof(v[0])` dentro de uma função que recebeu o vetor por parâmetro (ali `v` é ponteiro, e a conta dá errado).
- Esquecer de inicializar o vetor antes de somar os elementos.

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

`Q4_Solucao_1.c`

```c
// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int n, int indice) {
    // Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (indice == n)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[indice] + somaRecursiva(A, n, indice + 1);
}
```

`Q4_Solucao_2.c`

```c
// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int tamanho) {
    // Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (tamanho == 0)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[tamanho - 1] + somaRecursiva(A, tamanho - 1);
}
```

As duas soluções da Q4 chegam ao mesmo resultado por caminhos opostos: a Solução 1 soma `A[indice]` e avança para `indice + 1` até chegar em `n`; a Solução 2 soma `A[tamanho - 1]` e chama com `tamanho - 1` até chegar em `0`. No `Q4_Solucao_2.c`, os comentários mostram a pilha de chamadas sendo empilhada (lida de cima para baixo) e desempilhada (de baixo para cima).

## 💻 Exemplo de execução

`Q1.c`

```text
A média dos elementos do array é: 30.00
```

`Q2.c`

```text
O maior elemento do array é 8
```

`Q3.c`

```text
A soma dos elementos do array é 30
```

`Q4_Solucao_1.c`

```text
A soma dos elementos do array é 15
```

`Q4_Solucao_2.c`

```text
A soma dos elementos do array é 30
```

## ⚠️ Pontos de atenção

- Como os cinco arquivos têm `main`, o projeto **não compila inteiro** no Eclipse (erro `multiple definition of 'main'`). Compile e rode uma questão por vez pelo terminal, ou exclua os outros arquivos do build (**botão direito no arquivo → Resource Configurations → Exclude from Build**).

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Prova_AV2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

> ⚠️ Este projeto tem um `main` em cada arquivo. No Eclipse, deixe só um arquivo no build de cada vez (veja **Pontos de atenção**) ou use o terminal.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Prova_AV2`:

```bash
gcc src/Q1.c -o Q1 && ./Q1
gcc src/Q2.c -o Q2 && ./Q2
gcc src/Q3.c -o Q3 && ./Q3
gcc src/Q4_Solucao_1.c -o Q4_Solucao_1 && ./Q4_Solucao_1
gcc src/Q4_Solucao_2.c -o Q4_Solucao_2 && ./Q4_Solucao_2
```

No Windows, rode cada executável com `.exe` no final.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Prova_AV2
│
├── 📁 src
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4_Solucao_1.c
│   └── Q4_Solucao_2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1: Two Sum](https://leetcode.com/problems/two-sum/)
- [LeetCode 1480: Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Beecrowd 1172: Substituição em Vetor I](https://judge.beecrowd.com/pt/problems/view/1172)
- [Beecrowd 1173: Preenchimento de Vetor I](https://judge.beecrowd.com/pt/problems/view/1173)
- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva_Array](../Prj_Soma_Recursiva_Array): Soma recursiva de um array
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números
- [Prj_Array_Exer1](../Prj_Array_Exer1): Exercício: soma e média de um array

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays](https://en.cppreference.com/w/c/language/array)
- [cppreference: inicialização de arrays](https://en.cppreference.com/w/c/language/array_initialization)
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
