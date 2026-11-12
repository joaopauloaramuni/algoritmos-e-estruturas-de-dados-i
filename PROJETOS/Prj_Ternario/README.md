# Projeto Prj_Ternario (C) ❓

> **Operador ternário**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Escolhe entre dois valores com o **operador ternário** `condição ? valor_se_verdadeiro : valor_se_falso`, a forma compacta do `if/else`.

## 🎯 Conceitos trabalhados

- Operador condicional `?:`
- Expressões que devolvem valor
- Equivalência com `if/else`

## 📚 Entendendo o conceito

### switch, case e o operador ternário

O `switch` compara **uma** expressão inteira (ou `char`, ou `enum`) com várias constantes e salta direto para o `case` correspondente. O `break` encerra o `switch`; sem ele, a execução continua no `case` seguinte (*fall-through*). O `default` funciona como o `else` final.

O operador ternário `condição ? a : b` é um `if/else` que **devolve um valor**, por isso cabe dentro de expressões: `int maior = (x > y) ? x : y;`.

#### 🌍 Onde é usado na prática

- Menus de linha de comando, máquinas de estado (status de pedido, fases de um jogo) e interpretadores de comandos usam `switch`.
- Compiladores costumam transformar um `switch` com muitos casos em uma **tabela de saltos**, mais rápida que uma cadeia de `if`.
- O ternário é comum em atribuições curtas e em *templates* de interface (`ativo ? "Sim" : "Não"`).

#### 💼 Em processos seletivos

O `switch` aparece em perguntas sobre *fall-through* (o que imprime um `switch` sem `break`?) e em exercícios de máquina de estados. Ternários aninhados demais são vistos como problema de legibilidade em revisões de código.

Perguntas que costumam aparecer:

- O que acontece se faltar o `break` em um `case`?
- Quando usar `switch` em vez de `if / else if`?
- Reescreva um `if/else` simples com o operador ternário.

#### 🐞 Erros comuns

- Esquecer o `break`.
- Tentar usar `switch` com `float` ou com strings: não compila em C.
- Encadear ternários até ficarem ilegíveis.

## 🧠 Como funciona o código

```c
int main(void) {
    int numero = 10;
    // Estrutura de "se senão" usando operador ternário
    int resultado = (numero > 5) ? 2 : 3;

    printf("Resultado: %d\n", resultado);

    return 0;
}
```

`int resultado = (numero > 5) ? 2 : 3;` é o mesmo que:

```c
int resultado;
if (numero > 5) {
    resultado = 2;
} else {
    resultado = 3;
}
```

O ternário aparece bastante nas funções recursivas de uma linha, como no [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo).

## 💻 Exemplo de execução

```text
Resultado: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Ternario` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Ternario`:

```bash
gcc src/Prj_Ternario.c -o Prj_Ternario
./Prj_Ternario
```

No Windows, rode `Prj_Ternario.exe` (ou `.\Prj_Ternario.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Ternario
│
├── 📁 src
│   └── Prj_Ternario.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1050: DDD](https://judge.beecrowd.com/pt/problems/view/1050)
- [Beecrowd 1052: Mês](https://judge.beecrowd.com/pt/problems/view/1052)
- [Beecrowd 1038: Lanche](https://judge.beecrowd.com/pt/problems/view/1038)

## 🔗 Projetos relacionados

- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: switch](https://en.cppreference.com/w/c/language/switch)
- [cppreference: operador condicional (?:)](https://en.cppreference.com/w/c/language/operator_other)

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
