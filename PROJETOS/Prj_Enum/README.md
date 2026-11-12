# Projeto Prj_Enum (C) 📅

> **Enum: dias da semana**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria o tipo enumerado `enum DiaSemana` (DOMINGO a SABADO) e usa um `switch` para escrever o dia por extenso.

## 🎯 Conceitos trabalhados

- `enum` e constantes nomeadas
- Valores implícitos (DOMINGO = 0, SEGUNDA = 1...)
- `enum` em `switch`

## 📚 Entendendo o conceito

Este projeto trabalha **Enum e union** e **switch, case e o operador ternário**.

### Enum e union

Um **`enum`** cria constantes inteiras com nome: em `enum Dia { DOMINGO, SEGUNDA, ... };`, `DOMINGO` vale 0, `SEGUNDA` vale 1, e assim por diante. Serve para deixar o código legível (`case TERCA:` em vez de `case 2:`) e para restringir os valores possíveis de um campo.

Uma **`union`** parece uma struct, mas **todos os campos dividem o mesmo espaço de memória**: o tamanho da union é o do maior campo, e só o último campo gravado tem valor válido. Quando se guarda numa union **um** de vários tipos possíveis, costuma-se acompanhar a union de um `enum` que diz qual campo está em uso (a chamada *tagged union*).

#### 🌍 Onde é usado na prática

- `enum`: estados de um pedido, direções de um jogo, códigos de erro, opções de um menu.
- `union`: interpretadores e compiladores (um valor pode ser inteiro, real ou texto), mensagens de protocolos de rede e economia de memória em sistemas embarcados.
- O conceito reaparece em linguagens modernas: `enum` com dados em Rust e Swift e *sum types* em linguagens funcionais.

#### 💼 Em processos seletivos

Menos frequentes que structs, mas aparecem em vagas de C/C++ e embarcados, principalmente a diferença de memória entre struct e union.

Perguntas que costumam aparecer:

- Qual o `sizeof` de uma union com um `int`, um `double` e um `char[20]`?
- Qual a diferença entre struct e union?
- O que é uma *tagged union*?

#### 🐞 Erros comuns

- Ler um campo da union diferente do último gravado.
- Imprimir um `enum` com `%d` esperando o nome da constante (C não guarda os nomes; é preciso um vetor de strings).

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
    // Declaração de uma variável do tipo enum DiaSemana
    enum DiaSemana hoje = TERCA;

    // Uso do enum em uma estrutura de controle (switch)
    switch (hoje) {
    case DOMINGO:
        printf("Hoje é domingo.\n");
        break;
    case SEGUNDA:
        printf("Hoje é segunda-feira.\n");
        break;
    case TERCA:
        printf("Hoje é terça-feira.\n");
        break;
    case QUARTA:
        printf("Hoje é quarta-feira.\n");
        break;
    case QUINTA:
        printf("Hoje é quinta-feira.\n");
        break;
    case SEXTA:
        printf("Hoje é sexta-feira.\n");
        break;
    case SABADO:
        printf("Hoje é sábado.\n");
        break;
    default:
        printf("Dia desconhecido.\n");
        break;
    }

    return 0;
}
```

Por baixo, cada constante do `enum` é um inteiro: DOMINGO vale 0, SEGUNDA 1 e assim por diante. A vantagem é ler `case TERCA:` em vez de `case 2:`.

## 💻 Exemplo de execução

```text
Hoje é terça-feira.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Enum` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Enum`:

```bash
gcc src/Prj_Enum.c -o Prj_Enum
./Prj_Enum
```

No Windows, rode `Prj_Enum.exe` (ou `.\Prj_Enum.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Enum
│
├── 📁 src
│   └── Prj_Enum.c
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

- [Prj_Enum_Struct](../Prj_Enum_Struct): Enum dentro de struct
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [switch](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/switch)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: enum](https://en.cppreference.com/w/c/language/enum)
- [cppreference: union](https://en.cppreference.com/w/c/language/union)
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
