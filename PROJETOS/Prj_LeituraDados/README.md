# Projeto Prj_LeituraDados (C) ⌨️

> **Leitura de dados com scanf**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê um número inteiro digitado pelo usuário e o mostra de volta. É o primeiro contato com a **entrada de dados** em C.

## 🎯 Conceitos trabalhados

- Função `scanf` com o especificador `%d`
- Operador de endereço `&`
- Fluxo entrada → processamento → saída

## 📚 Entendendo o conceito

### Entrada e saída (printf, scanf e o buffer do teclado)

`printf` escreve texto formatado na saída padrão e `scanf` lê da entrada padrão. Os dois usam **especificadores de formato**: `%d` (int), `%f` (float no `printf` e no `scanf`), `%lf` (double no `scanf`), `%c` (char), `%s` (string), `%p` (endereço).

O teclado não entrega os caracteres direto para o programa: eles ficam num **buffer** até o *Enter*. O `scanf("%d", ...)` lê o número e **deixa o `\n` no buffer**, e a próxima leitura de caractere ou de linha (`%c`, `getchar`, `fgets`) pega esse `\n` sobrando. Esse é o bug mais comum de quem começa em C.

#### 🌍 Onde é usado na prática

- Programas de linha de comando, ferramentas de terminal e scripts leem e escrevem pela entrada e saída padrão (`stdin`, `stdout`).
- Plataformas de programação competitiva (Beecrowd, Codeforces, HackerRank) avaliam o programa só pela saída: um espaço a mais reprova a solução.
- `fprintf(stderr, ...)` separa mensagens de erro da saída normal.

#### 💼 Em processos seletivos

Em testes online (HackerRank, Codility, Beecrowd) a leitura correta da entrada é metade do problema. Saber ler até o fim do arquivo (`while (scanf(...) == 2)`) e lidar com o `\n` sobrando economiza muito tempo.

Perguntas que costumam aparecer:

- Por que o programa "pula" a leitura de um caractere depois de um `scanf("%d")`?
- Por que `scanf("%d", &x)` precisa do `&`, e `scanf("%s", nome)` não?
- Qual a diferença entre `%f` no `printf` e `%lf` no `scanf`?

#### 🐞 Erros comuns

- Esquecer o `&` no `scanf` (o programa trava ou escreve em lugar errado).
- Usar `fflush(stdin)` para limpar o buffer: só funciona no Windows; o padrão C não define esse uso. O portável é `while (getchar() != '\n');` ou `scanf(" %c", &c)` com espaço antes do `%c`.
- Usar `gets`: foi removida do C11 porque não limita o tamanho da leitura. Use `fgets`.

## 🧠 Como funciona o código

```c
int main(void) {
    // Declaração da variável para armazenar o valor lido
    int numero;

    // Utilização da scanf para ler um inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Exibição do valor lido
    printf("Você digitou: %d\n", numero);

    return 0;
}
```

O `scanf("%d", &numero)` precisa saber **onde** guardar o valor lido, por isso recebe o endereço da variável (`&numero`) e não o valor dela. Esse mesmo `&` volta mais tarde na matéria de ponteiros.

## 💻 Exemplo de execução

```text
Digite um número inteiro: 42
Você digitou: 42
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_LeituraDados` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_LeituraDados`:

```bash
gcc src/Prj_LeituraDados.c -o Prj_LeituraDados
./Prj_LeituraDados
```

No Windows, rode `Prj_LeituraDados.exe` (ou `.\Prj_LeituraDados.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_LeituraDados
│
├── 📁 src
│   └── Prj_LeituraDados.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1003: Soma Simples](https://judge.beecrowd.com/pt/problems/view/1003)
- [Beecrowd 1004: Produto Simples](https://judge.beecrowd.com/pt/problems/view/1004)
- [Beecrowd 1005: Média 1](https://judge.beecrowd.com/pt/problems/view/1005)

## 🔗 Projetos relacionados

- [Prj_Sequencial](../Prj_Sequencial): Estrutura sequencial
- [Prj_Memoria](../Prj_Memoria): Endereço de memória
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: scanf](https://en.cppreference.com/w/c/io/fscanf)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: getchar](https://en.cppreference.com/w/c/io/getchar)

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
