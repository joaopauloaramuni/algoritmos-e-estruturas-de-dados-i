# Projeto Prj_DoWhile_Menu (C) 📋

> **Menu com do-while e switch**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Monta um **menu de opções** que se repete até o usuário escolher **Sair**. É o padrão de menu usado em vários trabalhos da disciplina: `do-while` para repetir e `switch` para tratar a escolha.

## 🎯 Conceitos trabalhados

- Menu interativo
- `do-while` controlado por uma *flag* (`escolha`)
- `switch` com `default` para opção inválida

## 📚 Entendendo o conceito

Este projeto trabalha **Laços de repetição (while, do-while e for)** e **switch, case e o operador ternário**.

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
    int escolha;

    do {
        printf("Menu:\n");
        printf("1. Opção 1\n");
        printf("2. Opção 2\n");
        printf("3. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {//flag
        case 1:
            printf("Você escolheu a Opção 1.\n");
            break;
        case 2:
            printf("Você escolheu a Opção 2.\n");
            break;
        case 3:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
```

O laço só termina quando `escolha` vale `3`. Qualquer outro número cai no `default` e o menu aparece de novo. O mesmo padrão aparece, maior, no [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo) e na [Tarefa 3](../Prj_Tarefa_3_1).

## 💻 Exemplo de execução

```text
Menu:
1. Opção 1
2. Opção 2
3. Sair
Escolha uma opção: 1
Você escolheu a Opção 1.
(menu)
Escolha uma opção: 2
Você escolheu a Opção 2.
(menu)
Escolha uma opção: 3
Saindo do programa.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_DoWhile_Menu` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_DoWhile_Menu`:

```bash
gcc src/Prj_DoWhile.c -o Prj_DoWhile_Menu
./Prj_DoWhile_Menu
```

No Windows, rode `Prj_DoWhile_Menu.exe` (ou `.\Prj_DoWhile_Menu.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_DoWhile_Menu
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
- [Beecrowd 1050: DDD](https://judge.beecrowd.com/pt/problems/view/1050)
- [Beecrowd 1052: Mês](https://judge.beecrowd.com/pt/problems/view/1052)
- [Beecrowd 1038: Lanche](https://judge.beecrowd.com/pt/problems/view/1038)

## 🔗 Projetos relacionados

- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)
- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [Letra](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/Letra)
- [MenuOpcoes](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/MenuOpcoes)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)
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
