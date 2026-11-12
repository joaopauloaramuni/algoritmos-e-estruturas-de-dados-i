# Projeto Prj_DoWhile (C) 🔂

> **Laço do-while**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê e soma dois números três vezes usando `do-while`, que executa o bloco **pelo menos uma vez** antes de testar a condição.

## 🎯 Conceitos trabalhados

- Laço `do { ... } while (condição);`
- Teste da condição no final
- Contador

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
int main(void) {
    int x, y, result, cont;

    cont = 1;
    do {
        printf("Entre com os dois números para serem somados\n");
        scanf("%d %d", &x, &y);

        result = x + y;
        printf("O valor da soma é %d \n", result);
        cont++;

    } while (cont <= 3);

}
```

No `while` a condição é testada antes de entrar; no `do-while`, depois. Repare no ponto e vírgula depois do `while (cont <= 3);`: ele é obrigatório.

## 💻 Exemplo de execução

```text
Entre com os dois números para serem somados
1 2
O valor da soma é 3 
Entre com os dois números para serem somados
3 4
O valor da soma é 7 
Entre com os dois números para serem somados
5 6
O valor da soma é 11
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_DoWhile` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_DoWhile`:

```bash
gcc src/Prj_DoWhile.c -o Prj_DoWhile
./Prj_DoWhile
```

No Windows, rode `Prj_DoWhile.exe` (ou `.\Prj_DoWhile.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_DoWhile
│
├── 📁 src
│   └── Prj_DoWhile.c
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

- [Prj_While](../Prj_While): Laço while
- [Prj_For](../Prj_For): Laço for
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [do_while](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/do_while)

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
