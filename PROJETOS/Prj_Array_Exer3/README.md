# Projeto Prj_Array_Exer3 (C) 🧊

> **Exercício: média de uma matriz 3D**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula a média dos 8 elementos de uma **matriz tridimensional** 2×2×2 usando três laços aninhados e um contador.

## 🎯 Conceitos trabalhados

- Matriz com três dimensões
- Três `for` aninhados
- Contador e conversão `(double)`

## 📚 Entendendo o conceito

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
int main(void) {
    int matriz[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
    int soma = 0;
    int contador = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                soma = soma + matriz[i][j][k];
                contador++;
            }
        }
    }

    double media = (double) soma / contador;

    printf("Média dos elementos da matriz tridimensional: %.2lf\n", media);

    return 0;
}
```

Dá para pensar na matriz `[2][2][2]` como duas matrizes 2×2 empilhadas. O contador chega a `8` e a média é `36 / 8 = 4.50`.

## 💻 Exemplo de execução

```text
Média dos elementos da matriz tridimensional: 4.50
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Exer3` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Exer3`:

```bash
gcc src/Prj_Array_Exer3.c -o Prj_Array_Exer3
./Prj_Array_Exer3
```

No Windows, rode `Prj_Array_Exer3.exe` (ou `.\Prj_Array_Exer3.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Exer3
│
├── 📁 src
│   └── Prj_Array_Exer3.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 867: Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [LeetCode 1572: Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)
- [LeetCode 48: Rotate Image](https://leetcode.com/problems/rotate-image/)
- [LeetCode 54: Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [Beecrowd 1181: Linha na Matriz](https://judge.beecrowd.com/pt/problems/view/1181)

## 🔗 Projetos relacionados

- [Prj_Array_Exer2](../Prj_Array_Exer2): Exercício: soma de uma matriz 3x3
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays multidimensionais](https://en.cppreference.com/w/c/language/array)
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
