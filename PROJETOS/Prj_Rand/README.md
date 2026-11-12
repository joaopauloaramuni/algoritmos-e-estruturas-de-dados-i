# Projeto Prj_Rand (C) 🎲

> **Números aleatórios**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Gera e mostra um número aleatório entre 0 e 100 usando `rand()`, com a semente iniciada pelo relógio (`srand(time(NULL))`).

## 🎯 Conceitos trabalhados

- `rand` e `srand` de `<stdlib.h>`
- `time(NULL)` de `<time.h>` como semente
- Operador de resto `%` para limitar o intervalo

## 📚 Entendendo o conceito

### Números aleatórios (rand e srand)

Computadores são determinísticos, então `rand()` não gera números realmente aleatórios: ela produz uma sequência **pseudoaleatória** calculada a partir de uma **semente**. Mesma semente, mesma sequência. Por isso os programas chamam `srand(time(NULL))` **uma vez** no início, usando o relógio como semente.

`rand()` devolve um inteiro de 0 a `RAND_MAX`; para um intervalo, usa-se o resto: `rand() % 6 + 1` simula um dado de 1 a 6. (Esse truque tem um pequeno viés quando `RAND_MAX + 1` não é múltiplo do intervalo, irrelevante em jogos simples.)

#### 🌍 Onde é usado na prática

- Jogos (dados, cartas embaralhadas, inimigos), simulações e testes com dados sorteados.
- Métodos de Monte Carlo: estimar probabilidades e áreas sorteando muitos pontos.
- Algoritmos aleatorizados, como o *Quicksort* com pivô sorteado.
- **Nunca** para senhas, *tokens* ou criptografia: para isso existem geradores criptograficamente seguros (`/dev/urandom`, `getrandom`).

#### 💼 Em processos seletivos

Aparece em perguntas como embaralhar um vetor de forma justa (algoritmo de Fisher-Yates), sortear com pesos e explicar por que `rand()` não serve para segurança.

Perguntas que costumam aparecer:

- Por que o programa sorteia sempre o mesmo número sem `srand`?
- Embaralhe um vetor de forma que todas as permutações sejam igualmente prováveis.
- Por que não usar `rand()` para gerar senhas?

#### 🐞 Erros comuns

- Chamar `srand(time(NULL))` dentro de um laço (no mesmo segundo, a semente se repete).
- Esquecer o `+ 1` e sortear de 0 a 5 em vez de 1 a 6.

## 🧠 Como funciona o código

```c
int main(void) {
    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Gera e imprime um número aleatório no intervalo de 0 a 100
    int numeroAleatorio = rand() % 101;
    printf("Número Aleatório: %d\n", numeroAleatorio);

    return 0;
}
```

`rand()` devolve um número entre `0` e `RAND_MAX`. O `% 101` pega o resto da divisão por 101, que fica sempre entre `0` e `100`. Sem o `srand(time(NULL))`, a sequência começaria sempre da mesma semente e o programa mostraria o mesmo número a cada execução.

## 💻 Exemplo de execução

```text
Número Aleatório: 21
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Rand` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Rand`:

```bash
gcc src/Prj_Rand.c -o Prj_Rand
./Prj_Rand
```

No Windows, rode `Prj_Rand.exe` (ou `.\Prj_Rand.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Rand
│
├── 📁 src
│   └── Prj_Rand.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 384: Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

## 🔗 Projetos relacionados

- [Prj_Loteria](../Prj_Loteria): Loteria
- [Prj_Dados](../Prj_Dados): Jogo de dados
- [Prj_MontyHall](../Prj_MontyHall): Problema de Monty Hall

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: rand](https://en.cppreference.com/w/c/numeric/random/rand)
- [cppreference: srand](https://en.cppreference.com/w/c/numeric/random/srand)
- [Wikipedia: Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

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
