# Projeto Prj_Triangulo (C) 🎄

> **Exercício de revisão: árvore de Natal**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do **Exercício de Revisão – Árvore de Natal**: desenha padrões de asteriscos no console a partir do número de linhas informado. São três desenhos: o triângulo, o triângulo com as bordas trocadas por `#` e, como desafio extra, o losango.

📄 Enunciado: [Exercício de Revisão (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Exerc%C3%ADcio%20de%20Revis%C3%A3o.pdf)

## 🎯 Conceitos trabalhados

- Laços `for` aninhados
- Relação entre linha e quantidade de caracteres (`2 * i - 1`)
- Funções `void` com parâmetro

## 📚 Entendendo o conceito

### Laços de repetição (while, do-while e for)

Laços repetem um bloco enquanto uma condição for verdadeira. Os três de C são equivalentes em poder, e a escolha é de legibilidade:

| Laço | Quando a condição é testada | Uso típico |
| --- | --- | --- |
| `while` | Antes de cada volta | Repetir até um evento (sentinela, fim do arquivo) |
| `do-while` | Depois de cada volta (roda pelo menos 1 vez) | Menus e validação de entrada |
| `for` | Antes de cada volta, com início e passo na mesma linha | Número de repetições conhecido, percorrer vetores |

Um **valor sentinela** (como `0` ou `-1`) é um valor especial que avisa o fim da entrada. `break` sai do laço na hora e `continue` pula para a próxima volta.

#### 🌍 Onde é usado na prática

- Percorrer coleções: linhas de um arquivo, itens de um carrinho, pixels de uma imagem.
- Laços de eventos: servidores, jogos e interfaces gráficas rodam um laço "infinito" que espera e trata eventos.
- Tentativas com limite: reconectar a um servidor até 3 vezes.

#### 💼 Em processos seletivos

Quase toda questão de algoritmo usa laços. Os avaliadores olham os **limites** (`<` ou `<=`? começa em 0 ou 1?), o caso de entrada vazia e a complexidade: dois laços aninhados sobre `n` elementos custam O(n²).

Perguntas que costumam aparecer:

- Some os números de 1 a n (com laço e com fórmula).
- Encontre o maior e o menor valor de uma sequência sem guardar todos.
- Qual a complexidade de dois `for` aninhados que vão até `n`?

#### ⏱️ Complexidade

Um laço que percorre `n` itens custa O(n). Laços aninhados multiplicam: O(n²), O(n³).

#### 🐞 Erros comuns

- Erro de "um a mais ou a menos" (*off-by-one*): `i <= n` em um vetor de `n` posições lê fora do vetor.
- Esquecer de atualizar a variável de controle e criar um laço infinito.
- Colocar `;` logo depois do `for (...)`: o laço fica vazio.

## 🧠 Como funciona o código

```c
void exercicio1(int linhas) {
    // Exibe o padrão de asteriscos em forma de triângulo
    printf("Padrão de asteriscos:\n");
    for (int i = 1; i <= linhas; i++) {
        //linhas = 5
        // Loop para exibir os espaços em branco antes dos asteriscos
        for (int j = 1; j <= linhas - i; j++) {
            printf(" ");
        }
        // Loop para exibir os asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}
```

```c
void exercicio2(int linhas) {
    // Exibe o padrão de asteriscos em forma de triângulo
    printf("Padrão de asteriscos:\n");
    for (int i = 1; i <= linhas; i++) {
        // Loop para exibir os espaços em branco antes dos asteriscos
        for (int j = 1; j <= linhas - i; j++) {
            printf(" ");
        }
        // Loop para exibir os caracteres nas extremidades e os asteriscos internos
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("#");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}
```

Para a linha `i` de um triângulo com `linhas` linhas:

| O que imprimir | Quantidade |
| --- | --- |
| Espaços antes | `linhas - i` |
| Asteriscos | `2 * i - 1` |

No `exercicio2`, o primeiro (`k == 1`) e o último (`k == 2 * i - 1`) caractere de cada linha viram `#`. O `exercicio3` desenha a metade de cima e repete a mesma lógica de baixo para cima para formar o losango.

## 💻 Exemplo de execução

```text
Digite o número de linhas (maior que 0): 5
Padrão de asteriscos:
    *
   ***
  *****
 *******
*********
Padrão de asteriscos:
    #
   #*#
  #***#
 #*****#
#*******#
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Triangulo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Triangulo`:

```bash
gcc src/Prj_Triangulo.c -o Prj_Triangulo
./Prj_Triangulo
```

No Windows, rode `Prj_Triangulo.exe` (ou `.\Prj_Triangulo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Triangulo
│
├── 📁 src
│   └── Prj_Triangulo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1059: Números Pares](https://judge.beecrowd.com/pt/problems/view/1059)
- [Beecrowd 1060: Números Positivos](https://judge.beecrowd.com/pt/problems/view/1060)
- [Beecrowd 1078: Tabuada](https://judge.beecrowd.com/pt/problems/view/1078)
- [Beecrowd 1094: Experiências](https://judge.beecrowd.com/pt/problems/view/1094)

## 🔗 Projetos relacionados

- [Prj_For](../Prj_For): Laço for
- [Prj_Tarefa_2](../Prj_Tarefa_2): Tarefa 2: laços, funções e menu de pagamento

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)

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
