# Projeto Prj_HelloWorld (C) 👋

> **Hello World**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

O primeiro programa da disciplina: imprime `!!!Hello World!!!` no console. É o modelo que o **Eclipse IDE for C/C++ Developers** gera ao criar um projeto C novo (*Hello World ANSI C Project*), e serve para conferir se o compilador (GCC/MinGW) e a IDE estão instalados corretamente.

## 🎯 Conceitos trabalhados

- Estrutura mínima de um programa C (`#include`, `main`, `return`)
- Saída de texto com `puts`
- Constante `EXIT_SUCCESS` de `<stdlib.h>`
- Comentários de bloco `/* ... */`

## 📚 Entendendo o conceito

### Estrutura de um programa em C e compilação

Todo programa em C começa pela função `main`. Antes dela vêm as diretivas do **pré-processador** (`#include`, `#define`), que são resolvidas antes da compilação: o `#include <stdio.h>` cola no arquivo as declarações de `printf`, `puts`, `scanf` e companhia.

C é uma linguagem **compilada**: o código-fonte (`.c`) passa por pré-processamento, compilação (gera código objeto `.o`) e ligação (*linking*, junta o seu código com a biblioteca padrão) até virar um executável. O valor devolvido por `main` (`return 0` ou `EXIT_SUCCESS`) é o código de saída que o sistema operacional recebe: zero quer dizer "terminou bem".

#### 🌍 Onde é usado na prática

- C continua no núcleo de sistemas operacionais (Linux, partes do Windows e do macOS), bancos de dados (SQLite, PostgreSQL), interpretadores (CPython, Lua) e firmware de dispositivos embarcados.
- O código de saída de `main` é o que scripts, *pipelines* de CI e o próprio terminal usam para saber se um programa falhou.
- Entender as etapas de compilação ajuda a ler mensagens de erro: `undefined reference` é erro de **ligação**, não de sintaxe.

#### 💼 Em processos seletivos

Raramente alguém pergunta o "Hello World" em si, mas perguntas conceituais sobre a cadeia de compilação aparecem em vagas de sistemas embarcados, C/C++ e infraestrutura.

Perguntas que costumam aparecer:

- Quais são as etapas entre o arquivo `.c` e o executável?
- Qual a diferença entre erro de compilação e erro de ligação?
- O que o valor de retorno de `main` significa?

#### 🐞 Erros comuns

- Esquecer o `#include` de uma função: compiladores modernos tratam a declaração implícita como erro.
- Confundir `puts` (sempre quebra a linha) com `printf` (só quebra com `\n`).

## 🧠 Como funciona o código

```c
int main(void) {
    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    return EXIT_SUCCESS;
}
```

`puts` escreve a string e já acrescenta a quebra de linha no final, diferente do `printf`, que só quebra a linha quando encontra `\n`. O `return EXIT_SUCCESS` (que vale `0`) avisa ao sistema operacional que o programa terminou sem erros.

## 💻 Exemplo de execução

```text
!!!Hello World!!!
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_HelloWorld` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_HelloWorld`:

```bash
gcc src/Prj_HelloWorld.c -o Prj_HelloWorld
./Prj_HelloWorld
```

No Windows, rode `Prj_HelloWorld.exe` (ou `.\Prj_HelloWorld.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_HelloWorld
│
├── 📁 src
│   └── Prj_HelloWorld.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1000: Hello World!](https://judge.beecrowd.com/pt/problems/view/1000)
- [Beecrowd 1001: Extremamente Básico](https://judge.beecrowd.com/pt/problems/view/1001)

## 🔗 Projetos relacionados

- [Prj_Variaveis](../Prj_Variaveis): Variáveis e constantes
- [Prj_LeituraDados](../Prj_LeituraDados): Leitura de dados com scanf

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [aloMundo](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/aloMundo)
- [aloMundo2](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/aloMundo2)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: a função main](https://en.cppreference.com/w/c/language/main_function)
- [cppreference: pré-processador](https://en.cppreference.com/w/c/preprocessor)
- [GCC: documentação oficial](https://gcc.gnu.org/onlinedocs/)

**Ferramentas e referências gerais**

- [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
- [Python Tutor: execute C passo a passo e veja a memória](https://pythontutor.com/c.html)
- [VisuAlgo: estruturas de dados e algoritmos animados](https://visualgo.net/)
- [OnlineGDB: compile e rode C no navegador](https://www.onlinegdb.com/)
- [Eclipse CDT (IDE usada na disciplina)](https://eclipse.dev/cdt/)

**Livros**

- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Elsevier.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Campus/Elsevier.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. Elsevier.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
