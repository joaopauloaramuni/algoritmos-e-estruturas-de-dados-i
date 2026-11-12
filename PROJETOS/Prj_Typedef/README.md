# Projeto Prj_Typedef (C) 🏷️

> **typedef**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria um **apelido** (`MeuInteiro`) para o tipo `int` com `typedef` e o usa para declarar uma variável.

## 🎯 Conceitos trabalhados

- Palavra-chave `typedef`
- Apelidos de tipo
- Escopo global

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
    // Usando o novo tipo criado com typedef
    MeuInteiro numero = 13;

    printf("Número: %d\n", numero);

    return 0;
}
```

`typedef int MeuInteiro;` não cria um tipo novo, só dá outro nome a um tipo que já existe. O uso mais comum aparece nos projetos de struct, como em `typedef struct { ... } Pessoa;`, que dispensa escrever `struct` toda vez.

## 💻 Exemplo de execução

```text
Número: 13
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Typedef` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Typedef`:

```bash
gcc src/Prj_Typedef.c -o Prj_Typedef
./Prj_Typedef
```

No Windows, rode `Prj_Typedef.exe` (ou `.\Prj_Typedef.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Typedef
│
├── 📁 src
│   └── Prj_Typedef.c
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

- [Prj_Struct_Pessoa_Arg](../Prj_Struct_Pessoa_Arg): Struct Pessoa com typedef
- [Prj_Enum](../Prj_Enum): Enum: dias da semana

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
