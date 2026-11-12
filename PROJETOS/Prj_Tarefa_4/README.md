# Projeto Prj_Tarefa_4 (C) 📊

> **Tarefa 4: vetores e matrizes**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução da **Tarefa 4**, uma função por exercício:

1. Vetor com 10 idades e a média delas.
2. Vetor com 10 alturas e a maior e a menor altura.
3. Matriz 3×3 multiplicada por um escalar.
4. Soma de duas matrizes 2×2.

📄 Enunciado: [Tarefa 4 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%204.pdf)

## 🎯 Conceitos trabalhados

- Vetores e matrizes como parâmetros de função
- Matriz como parâmetro (`int matriz[][3]`)
- Máximo e mínimo
- Operações com matrizes

## 📚 Entendendo o conceito

Este projeto trabalha **Vetores (arrays)** e **Matrizes (vetores bidimensionais)**.

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

### Matrizes (vetores bidimensionais)

Uma **matriz** `int m[3][4];` é um vetor de linhas: 3 linhas, cada uma com 4 colunas. Na memória, as linhas ficam uma depois da outra (ordem por linhas, *row-major*), então `m[i][j]` está na posição `i * 4 + j` a partir do início.

Percorrer uma matriz pede dois laços aninhados: o de fora nas linhas, o de dentro nas colunas. Ao passar uma matriz para uma função, a primeira dimensão pode ficar vazia, mas as outras são obrigatórias (`int m[][4]`), porque o compilador precisa delas para calcular o endereço de `m[i][j]`.

#### 🌍 Onde é usado na prática

- Imagens (cada *pixel* em `[linha][coluna]`), planilhas, tabuleiros de jogos, mapas de jogos 2D.
- Álgebra linear: transformações em computação gráfica, redes neurais (multiplicação de matrizes é a operação central do aprendizado de máquina).
- Grafos representados por matriz de adjacência.

#### 💼 Em processos seletivos

Problemas de matriz aparecem bastante: girar uma imagem 90°, percorrer em espiral, zerar linhas e colunas, buscar em matriz ordenada e problemas de grade (ilhas, caminhos) que usam busca em largura ou em profundidade.

Perguntas que costumam aparecer:

- Transponha uma matriz.
- Gire uma matriz quadrada 90° no próprio lugar.
- Some a diagonal principal e a secundária.
- Percorra a matriz em espiral.

#### ⏱️ Complexidade

Percorrer uma matriz n × m custa O(n·m).

#### 🐞 Erros comuns

- Trocar a ordem dos índices (`m[j][i]`).
- Percorrer por colunas no laço de fora: o resultado é o mesmo, mas fica mais lento por causa do *cache*.

## 🧠 Como funciona o código

```c
// Função para encontrar a maior e menor altura
void encontrarMaiorMenorAltura(float alturas[]) {
    float maior;
    float menor;

    printf("Digite a altura do aluno 1: ");
    scanf("%f", &alturas[0]);

    maior = alturas[0];
    menor = alturas[0];

    for (int i = 1; i < 10; i++) {
        printf("Digite a altura do aluno %d: ", i + 1);
        scanf("%f", &alturas[i]);

        if (alturas[i] > maior) {
            maior = alturas[i];
        }
        if (alturas[i] < menor) {
            menor = alturas[i];
        }
    }

    printf("Maior altura: %.2f\n", maior);
    printf("Menor altura: %.2f\n", menor);
}
```

```c
// Função para multiplicar uma matriz por um valor escalar
void multiplicarMatrizPorEscalar(int matriz[][3], int escalar) {
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz[i][j]);

    printf("Digite o valor escalar: ");
    scanf("%d", &escalar);

    printf("Matriz resultante após multiplicação:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j] * escalar);
        }
        printf("\n");
    }
}
```

Ao passar uma matriz para uma função, a primeira dimensão pode ficar vazia, mas as outras são obrigatórias (`int matriz[][3]`): o compilador precisa saber o tamanho de cada linha para calcular onde está `matriz[i][j]`.

## 💻 Exemplo de execução

```text
### Função 1 ###
Digite a idade do aluno 1: 18
Digite a idade do aluno 2: 19
Digite a idade do aluno 3: 20
Digite a idade do aluno 4: 21
Digite a idade do aluno 5: 22
Digite a idade do aluno 6: 18
Digite a idade do aluno 7: 19
Digite a idade do aluno 8: 20
Digite a idade do aluno 9: 21
Digite a idade do aluno 10: 22
Média das idades: 20.00

### Função 2 ###
Digite a altura do aluno 1: 1.60
Digite a altura do aluno 2: 1.75
Digite a altura do aluno 3: 1.82
Digite a altura do aluno 4: 1.68
Digite a altura do aluno 5: 1.90
Digite a altura do aluno 6: 1.55
Digite a altura do aluno 7: 1.70
Digite a altura do aluno 8: 1.80
Digite a altura do aluno 9: 1.65
Digite a altura do aluno 10: 1.72
Maior altura: 1.90
Menor altura: 1.55

### Função 3 ###
Digite os elementos da matriz 3x3:
1 2 3
4 5 6
7 8 9
Digite o valor escalar: 2
Matriz resultante após multiplicação:
2 4 6 
8 10 12 
14 16 18 

### Função 4 ###
Digite os elementos da primeira matriz 2x2:
1 2
3 4
Digite os elementos da segunda matriz 2x2:
5 6
7 8
Matriz resultante após soma:
6 8 
10 12
```

## ⚠️ Pontos de atenção

- Em `main`, a variável `escalar` é passada para `multiplicarMatrizPorEscalar` sem valor, mas como a função lê o escalar com `scanf` antes de usá-lo, o resultado sai certo. Uma versão mais clara não teria esse parâmetro e declararia `escalar` dentro da função.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_4` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_4`:

```bash
gcc src/Prj_Tarefa_4.c -o Prj_Tarefa_4
./Prj_Tarefa_4
```

No Windows, rode `Prj_Tarefa_4.exe` (ou `.\Prj_Tarefa_4.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_4
│
├── 📁 src
│   └── Prj_Tarefa_4.c
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
- [LeetCode 867: Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [LeetCode 1572: Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)
- [LeetCode 48: Rotate Image](https://leetcode.com/problems/rotate-image/)

## 🔗 Projetos relacionados

- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números
- [Prj_Array_Exer1](../Prj_Array_Exer1): Exercício: soma e média de um array

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays](https://en.cppreference.com/w/c/language/array)
- [cppreference: inicialização de arrays](https://en.cppreference.com/w/c/language/array_initialization)
- [Wikipedia: ordem por linhas e por colunas](https://en.wikipedia.org/wiki/Row-_and_column-major_order)

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
