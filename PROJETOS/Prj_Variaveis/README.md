# Projeto Prj_Variaveis (C) 📦

> **Variáveis e constantes**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra as três formas de guardar um valor que aparecem logo no início da disciplina: uma **variável comum** (`int idade`), uma **variável constante** (`const int MAX_NUM`) e uma **constante de pré-processador** (`#define PI`).

## 🎯 Conceitos trabalhados

- Declaração e inicialização de variáveis
- Modificador `const`
- Macro `#define`
- Especificadores `%d` e `%f` do `printf`

## 📚 Entendendo o conceito

### Variáveis, tipos e constantes

Uma **variável** é um nome para uma região da memória, e o **tipo** diz quantos bytes ela ocupa e como interpretar esses bytes: `int` (inteiro, normalmente 4 bytes), `float` e `double` (ponto flutuante), `char` (1 byte, um caractere ou um número pequeno).

Valores que não devem mudar podem ser declarados de duas formas: com `const` (uma variável de verdade, que o compilador protege contra escrita) ou com `#define` (uma **macro**, que o pré-processador troca pelo texto antes da compilação, sem ocupar memória e sem tipo).

#### 🌍 Onde é usado na prática

- Escolher o tipo certo evita bugs de precisão: dinheiro em `float` acumula erro de arredondamento; sistemas financeiros usam inteiros (centavos) ou tipos decimais.
- Constantes nomeadas (`MAX_ALUNOS`, `PI`) deixam o código legível e mudam em um lugar só.
- `typedef` cria apelidos de tipo, muito usados em APIs (`size_t`, `FILE`, `uint32_t`).

#### 💼 Em processos seletivos

Perguntas sobre tipos aparecem como "pegadinhas" em testes técnicos: estouro de inteiro (*overflow*), divisão inteira e comparação de `float` com `==`.

Perguntas que costumam aparecer:

- Qual a diferença entre `const` e `#define`?
- Quanto vale `7 / 2` em C? E `7 / 2.0`?
- Por que não comparar dois `float` com `==`?
- O que acontece quando um `int` passa do maior valor possível?

#### 🐞 Erros comuns

- Usar uma variável local sem inicializar: ela guarda "lixo" de memória.
- Dividir dois inteiros esperando resultado com casas decimais.
- Esquecer que `#define` é substituição de texto: `#define DOBRO(x) x*2` faz `DOBRO(1+1)` virar `1+1*2 = 3`.

## 🧠 Como funciona o código

```c
int main(void) {

    int idade = 26;
    const int MAX_NUM = 100;

    printf("Minha variável int comum = %d\n", idade);
    printf("Minha variável int constante = %d\n", MAX_NUM);
    printf("Minha constante = %f\n", PI);

    // MAX_NUM = 99;

    return EXIT_SUCCESS;
}
```

O `#define PI 3.14159` não ocupa memória: o pré-processador troca cada `PI` pelo texto `3.14159` **antes** da compilação. Já o `const int MAX_NUM = 100` é uma variável de verdade, só que o compilador recusa qualquer atribuição a ela. Para ver isso, descomente a linha `// MAX_NUM = 99;` e compile: o GCC acusa `assignment of read-only variable`.

## 💻 Exemplo de execução

```text
Minha variável int comum = 26
Minha variável int constante = 100
Minha constante = 3.141590
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Variaveis` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Variaveis`:

```bash
gcc src/Prj_Variaveis.c -o Prj_Variaveis
./Prj_Variaveis
```

No Windows, rode `Prj_Variaveis.exe` (ou `.\Prj_Variaveis.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Variaveis
│
├── 📁 src
│   └── Prj_Variaveis.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1002: Área do Círculo](https://judge.beecrowd.com/pt/problems/view/1002)
- [Beecrowd 1008: Salário](https://judge.beecrowd.com/pt/problems/view/1008)

## 🔗 Projetos relacionados

- [Prj_HelloWorld](../Prj_HelloWorld): Hello World
- [Prj_Typedef](../Prj_Typedef): typedef
- [Prj_Memoria](../Prj_Memoria): Endereço de memória

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: tipos aritméticos](https://en.cppreference.com/w/c/language/arithmetic_types)
- [cppreference: const](https://en.cppreference.com/w/c/language/const)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: #define](https://en.cppreference.com/w/c/preprocessor/replace)

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
