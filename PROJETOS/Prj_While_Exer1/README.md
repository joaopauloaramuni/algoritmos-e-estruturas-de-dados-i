# Projeto Prj_While_Exer1 (C) ⚖️

> **while: contar pares e ímpares**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê números até o usuário digitar `0` e, no final, mostra quantos foram **pares** e quantos foram **ímpares**.

## 🎯 Conceitos trabalhados

- Laço `while` com valor sentinela (`0`)
- Operador de resto `%` para testar paridade
- Dois contadores independentes

## 📚 Entendendo o conceito

Este projeto trabalha **Laços de repetição (while, do-while e for)** e **Operadores aritméticos, divisão inteira e resto**.

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
    int contpar = 0, contimpar = 0, num = 400;

    while (num != 0) {
        printf("Entre com um número; para encerrar, digite 0: ");
        scanf("%d", &num);

        if (num != 0) {
            if (num % 2 == 0) { //operador de módulo - verifica o resto
                contpar = contpar + 1;
            } else {
                contimpar = contimpar + 1;
            }
        }
    }

    printf("A quantidade de números pares é: %d\n", contpar);
    printf("A quantidade de números ímpares é: %d\n", contimpar);

    return 0;
}
```

`num % 2 == 0` é verdadeiro quando o resto da divisão por 2 é zero, ou seja, quando o número é par. A variável `num` começa com `400` só para a condição `num != 0` ser verdadeira na primeira volta; o [Prj_DoWhile_Exer1](../Prj_DoWhile_Exer1) resolve o mesmo problema sem esse truque, com `do-while`.

## 💻 Exemplo de execução

```text
Entre com um número; para encerrar, digite 0: 4
Entre com um número; para encerrar, digite 0: 7
Entre com um número; para encerrar, digite 0: 10
Entre com um número; para encerrar, digite 0: 3
Entre com um número; para encerrar, digite 0: 0
A quantidade de números pares é: 2
A quantidade de números ímpares é: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_While_Exer1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_While_Exer1`:

```bash
gcc src/Prj_While_Exer1.c -o Prj_While_Exer1
./Prj_While_Exer1
```

No Windows, rode `Prj_While_Exer1.exe` (ou `.\Prj_While_Exer1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_While_Exer1
│
├── 📁 src
│   └── Prj_While_Exer1.c
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
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 🔗 Projetos relacionados

- [Prj_DoWhile_Exer1](../Prj_DoWhile_Exer1): do-while: contar pares e ímpares
- [Prj_While_Exer2](../Prj_While_Exer2): while: contar números digitados

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)
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
