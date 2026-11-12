# Projeto Prj_CondicionalMultipla (C) 🔢

> **Condicional múltipla (else if e switch)**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê um número de 1 a 5 e responde qual foi escolhido. O mesmo problema é resolvido **duas vezes**: primeiro com uma cadeia de `if / else if` e depois com `switch`, a alternativa mais enxuta. Por isso a resposta aparece repetida na saída.

## 🎯 Conceitos trabalhados

- `if / else if / else` encadeado
- `switch`, `case`, `break` e `default`
- Comparação de valores inteiros

## 📚 Entendendo o conceito

Este projeto trabalha **switch, case e o operador ternário** e **Estruturas condicionais (if, else, else if)**.

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

### Estruturas condicionais (if, else, else if)

As estruturas condicionais decidem **qual trecho de código roda**. O `if` executa um bloco se a condição for verdadeira; o `if/else` escolhe entre dois caminhos; a cadeia `if / else if / else` testa várias condições em ordem e executa só a primeira verdadeira.

Em C, **qualquer valor diferente de zero é verdadeiro** e zero é falso. As condições combinam operadores relacionais (`<`, `>`, `<=`, `>=`, `==`, `!=`) e lógicos (`&&` e, `||` ou, `!` não). O `&&` e o `||` fazem **curto-circuito**: se o lado esquerdo já decide o resultado, o direito nem é avaliado.

#### 🌍 Onde é usado na prática

- Validação de dados: idade negativa, campo vazio, senha curta.
- Regras de negócio: faixas de desconto, aprovação por nota, classificação de IMC.
- O curto-circuito protege acessos: `if (p != NULL && p->valor > 0)` nunca lê `p->valor` com ponteiro nulo.

#### 💼 Em processos seletivos

Condicionais aparecem em praticamente todo exercício. O que os avaliadores observam é a **ordem** das condições (do caso mais específico ao mais geral), a cobertura dos casos de borda (zero, negativo, valor no limite da faixa) e a ausência de condições redundantes.

Perguntas que costumam aparecer:

- Classifique um triângulo (equilátero, isósceles, escaleno ou inválido).
- Diga se um ano é bissexto.
- O que acontece em `if (x = 5)`?

#### 🐞 Erros comuns

- Usar `=` (atribuição) no lugar de `==` (comparação): `if (x = 5)` é sempre verdadeiro.
- Escrever `if (18 <= idade <= 60)`: em C isso compara `(18 <= idade)` (0 ou 1) com 60. O certo é `idade >= 18 && idade <= 60`.
- Esquecer as chaves e achar que duas linhas estão dentro do `if`.

## 🧠 Como funciona o código

```c
int main(void) {
    int escolha;

    printf("Digite um número de 1 a 5: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Você escolheu o número 1.\n");
    } else if (escolha == 2) {
        printf("Você escolheu o número 2.\n");
    } else if (escolha == 3) {
        printf("Você escolheu o número 3.\n");
    } else if (escolha == 4) {
        printf("Você escolheu o número 4.\n");
    } else if (escolha == 5) {
        printf("Você escolheu o número 5.\n");
    } else {
        printf("Opção inválida.\n");
    }

    // Alternativa mais enxuta
    switch (escolha) {
    case 1:
        printf("Você escolheu o número 1.\n");
        break;
    case 2:
        printf("Você escolheu o número 2.\n");
        break;
    case 3:
        printf("Você escolheu o número 3.\n");
        break;
    case 4:
        printf("Você escolheu o número 4.\n");
        break;
    case 5:
        printf("Você escolheu o número 5.\n");
        break;
    default:
        printf("Opção inválida.\n");
    }

    return 0;
}
```

O `switch` compara a variável com cada `case` e pula direto para o que bate. O `break` encerra o `switch`; sem ele, a execução "cai" para o `case` seguinte (*fall-through*). O `default` funciona como o `else` final.

## 💻 Exemplo de execução

```text
Digite um número de 1 a 5: 3
Você escolheu o número 3.
Você escolheu o número 3.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_CondicionalMultipla` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_CondicionalMultipla`:

```bash
gcc src/Prj_CondicionalMultipla.c -o Prj_CondicionalMultipla
./Prj_CondicionalMultipla
```

No Windows, rode `Prj_CondicionalMultipla.exe` (ou `.\Prj_CondicionalMultipla.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_CondicionalMultipla
│
├── 📁 src
│   └── Prj_CondicionalMultipla.c
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
- [Beecrowd 1035: Teste de Seleção 1](https://judge.beecrowd.com/pt/problems/view/1035)
- [Beecrowd 1036: Fórmula de Bhaskara](https://judge.beecrowd.com/pt/problems/view/1036)
- [Beecrowd 1037: Intervalo](https://judge.beecrowd.com/pt/problems/view/1037)
- [Beecrowd 1041: Coordenadas de um Ponto](https://judge.beecrowd.com/pt/problems/view/1041)

## 🔗 Projetos relacionados

- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch
- [Prj_Enum](../Prj_Enum): Enum: dias da semana

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [switch](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/switch)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: switch](https://en.cppreference.com/w/c/language/switch)
- [cppreference: operador condicional (?:)](https://en.cppreference.com/w/c/language/operator_other)
- [cppreference: if](https://en.cppreference.com/w/c/language/if)
- [cppreference: operadores lógicos](https://en.cppreference.com/w/c/language/operator_logical)
- [cppreference: operadores de comparação](https://en.cppreference.com/w/c/language/operator_comparison)

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
