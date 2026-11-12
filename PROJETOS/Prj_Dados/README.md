# Projeto Prj_Dados (C) 🎲

> **Jogo de dados**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Dois jogadores rolam dois dados cada (pressionando *Enter*) e vence quem tiver a maior soma.

## 🎯 Conceitos trabalhados

- Função que sorteia de 1 a 6 (`rand() % 6 + 1`)
- `getchar` para esperar o *Enter*
- Vetores de 2 posições para os dados de cada jogador

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
// Função para lançar um dado
int rolarDado() {
    return rand() % 6 + 1; // Gera um número aleatório entre 1 e 6
}
```

`rand() % 6` dá de 0 a 5; somando 1, fica de 1 a 6, como um dado de verdade. Os resultados mudam a cada execução por causa do `srand(time(NULL))`.

## 💻 Exemplo de execução

```text
Jogador 1, pressione ENTER para rolar os dados.

Jogador 1: 2 + 5
Soma do Jogador 1: 7

Jogador 2, pressione ENTER para rolar os dados.

Jogador 2: 3 + 5
Soma do Jogador 2: 8

Jogador 2 vence!
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Dados` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Dados`:

```bash
gcc src/Prj_Dados.c -o Prj_Dados
./Prj_Dados
```

No Windows, rode `Prj_Dados.exe` (ou `.\Prj_Dados.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Dados
│
├── 📁 src
│   └── Prj_Dados.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 384: Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

## 🔗 Projetos relacionados

- [Prj_Rand](../Prj_Rand): Números aleatórios
- [Prj_Loteria](../Prj_Loteria): Loteria
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
