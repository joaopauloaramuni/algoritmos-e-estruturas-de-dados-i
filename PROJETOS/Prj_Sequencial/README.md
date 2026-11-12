# Projeto Prj_Sequencial (C) ➡️

> **Estrutura sequencial**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê dois inteiros, soma e mostra o resultado. Cada instrução roda uma vez, de cima para baixo, sem desvios nem repetições: é a **estrutura sequencial**, ponto de partida para as estruturas de controle.

## 🎯 Conceitos trabalhados

- Estrutura sequencial
- Leitura com `scanf` e escrita com `printf`
- Atribuição e operador aritmético `+`

## 📚 Entendendo o conceito

Este projeto trabalha **Entrada e saída (printf, scanf e o buffer do teclado)** e **Operadores aritméticos, divisão inteira e resto**.

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

### Operadores aritméticos, divisão inteira e resto

Os operadores `+ - * /` funcionam como na matemática, com uma diferença importante: **se os dois lados são inteiros, a divisão é inteira** (`7 / 2` dá `3`). Basta um dos lados ser `float`/`double` para a conta ser feita com casas decimais (`7 / 2.0` dá `3.5`), o que se força com uma conversão (*cast*): `(double) soma / n`.

O operador `%` devolve o **resto** da divisão inteira (`7 % 2` dá `1`). Ele é a ferramenta para testar paridade (`n % 2 == 0`), pegar o último dígito (`n % 10`), andar em círculo (`(i + 1) % n`) e espalhar valores em uma tabela *hash* (`chave % tamanho`).

#### 🌍 Onde é usado na prática

- Relógios, calendários e *buffers* circulares usam resto (`hora % 24`, `indice % capacidade`).
- Tabelas *hash* usam `%` para mapear uma chave em uma posição do vetor.
- Algoritmos com dígitos (somar dígitos, inverter número, validar CPF) combinam `% 10` e `/ 10`.

#### 💼 Em processos seletivos

Problemas com `%` e `/ 10` estão entre os mais comuns em etapas técnicas iniciais: inverter um inteiro, verificar se um número é palíndromo sem convertê-lo em texto, somar dígitos, FizzBuzz.

Perguntas que costumam aparecer:

- Implemente FizzBuzz.
- Inverta os dígitos de um inteiro sem usar strings.
- Quanto vale `-7 % 3` em C? (Desde o C99, o resto tem o sinal do dividendo: `-1`.)

#### 🐞 Erros comuns

- Esperar casas decimais em `int / int`.
- Dividir por zero: com inteiros, o programa é encerrado; com `float`, o resultado vira `inf` ou `nan`.
- Imprimir um `float` com `%.0f` e achar que a conta está errada: o valor só foi arredondado na exibição.

## 🧠 Como funciona o código

```c
int main(void) {
    int ValA, ValB, ValC;

    printf("Entre com os números para serem somados: ");
    scanf("%d", &ValA);
    scanf("%d", &ValB);

    ValC = ValA + ValB;

    printf("O valor da soma é: %d\n", ValC);

    return 0;
}
```

O programa é um passo a passo direto: declara `ValA`, `ValB` e `ValC`, lê os dois primeiros, calcula `ValC = ValA + ValB` e imprime. Compare com o [Prj_CondicionalSimples](../Prj_CondicionalSimples), que é o mesmo programa com um `if` antes do `printf`.

## 💻 Exemplo de execução

```text
Entre com os números para serem somados: 40
35
O valor da soma é: 75
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Sequencial` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Sequencial`:

```bash
gcc src/Prj_Sequencial.c -o Prj_Sequencial
./Prj_Sequencial
```

No Windows, rode `Prj_Sequencial.exe` (ou `.\Prj_Sequencial.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Sequencial
│
├── 📁 src
│   └── Prj_Sequencial.c
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
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 🔗 Projetos relacionados

- [Prj_CondicionalSimples](../Prj_CondicionalSimples): Condicional simples (if)
- [Prj_Soma](../Prj_Soma): Função soma

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: scanf](https://en.cppreference.com/w/c/io/fscanf)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: getchar](https://en.cppreference.com/w/c/io/getchar)
- [cppreference: operadores aritméticos](https://en.cppreference.com/w/c/language/operator_arithmetic)
- [cppreference: conversões implícitas](https://en.cppreference.com/w/c/language/conversion)

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
