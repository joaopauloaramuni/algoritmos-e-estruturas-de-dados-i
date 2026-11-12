# Projeto Prj_Maior_Menor (C) 📏

> **Maior e menor de 10 números**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê 10 números e mostra o **maior** e o **menor** deles, sem guardar todos em um vetor.

## 🎯 Conceitos trabalhados

- Laço `for`
- Inicialização com o primeiro valor lido
- Comparações para atualizar máximo e mínimo

## 📚 Entendendo o conceito

Este projeto trabalha **Busca linear: maior, menor e contagem** e **Laços de repetição (while, do-while e for)**.

### Busca linear: maior, menor e contagem

Encontrar o maior ou o menor valor de uma sequência é o exemplo mais simples de **busca linear**: olhar cada elemento uma vez, guardando o melhor visto até agora.

O detalhe que separa a solução certa da errada é o **valor inicial**. Começar o máximo em `0` falha se todos os números forem negativos; o correto é começar com o **primeiro elemento** (ou com `INT_MIN`/`INT_MAX` de `<limits.h>`).

#### 🌍 Onde é usado na prática

- Relatórios: maior venda do mês, menor temperatura do dia.
- Algoritmos de ordenação por seleção repetem a busca do menor elemento.
- Contar ocorrências (quantos pares, quantos acima da média) é a mesma ideia com um contador.

#### 💼 Em processos seletivos

É um aquecimento comum em entrevistas e aparece como subproblema de questões maiores (o segundo maior elemento, a maior soma de um subvetor). Espera-se a solução em uma única passada, O(n), e sem memória extra.

Perguntas que costumam aparecer:

- Encontre o segundo maior elemento em uma passada.
- Encontre o maior e o menor ao mesmo tempo com menos comparações.
- Qual o valor inicial correto para o máximo?

#### ⏱️ Complexidade

O(n) de tempo e O(1) de memória.

#### 🐞 Erros comuns

- Inicializar o máximo com 0.
- Esquecer o caso de sequência vazia.

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

## 🧠 Como funciona o código

```c
int main(void) {
    int i, number;
    int maior, menor;

    // Solicita ao usuário que insira 10 números
    printf("Digite 10 números:\n");

    // Lê o primeiro número
    scanf("%d", &number);

    // Inicializa o maior e o menor com o primeiro número
    maior = number;
    menor = number;

    // Loop para ler os próximos 9 números
    for (i = 1; i < 10; i++) { // i = 1, 2, .... , 9, 10 falso
        scanf("%d", &number);

        // Verifica se o número atual é maior que o maior atual
        if (number > maior) {
            maior = number;
        }

        // Verifica se o número atual é menor que o menor atual
        if (number < menor) {
            menor = number;
        }
    }

    // Exibe o maior e o menor número
    printf("O maior número é: %d\n", maior);
    printf("O menor número é: %d\n", menor);

    return 0;
}
```

O truque é usar o **primeiro número lido** como maior e menor iniciais. Começar com `0` daria errado se todos os números fossem negativos (o maior seria `0`, que nem foi digitado). Os outros 9 números são comparados um a um.

## 💻 Exemplo de execução

```text
Digite 10 números:
5 12 -3 8 21 0 7 14 -9 3
O maior número é: 21
O menor número é: -9
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Maior_Menor` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Maior_Menor`:

```bash
gcc src/Prj_Maior_Menor.c -o Prj_Maior_Menor
./Prj_Maior_Menor
```

No Windows, rode `Prj_Maior_Menor.exe` (ou `.\Prj_Maior_Menor.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Maior_Menor
│
├── 📁 src
│   └── Prj_Maior_Menor.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1013: O Maior](https://judge.beecrowd.com/pt/problems/view/1013)
- [Beecrowd 1080: Maior e Posição](https://judge.beecrowd.com/pt/problems/view/1080)
- [Beecrowd 1180: Menor e Posição](https://judge.beecrowd.com/pt/problems/view/1180)
- [LeetCode 414: Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)
- [Beecrowd 1059: Números Pares](https://judge.beecrowd.com/pt/problems/view/1059)
- [Beecrowd 1060: Números Positivos](https://judge.beecrowd.com/pt/problems/view/1060)
- [Beecrowd 1078: Tabuada](https://judge.beecrowd.com/pt/problems/view/1078)

## 🔗 Projetos relacionados

- [Prj_Prova_AV2](../Prj_Prova_AV2): Prova AV2: arrays e recursão
- [Prj_Tarefa_4](../Prj_Tarefa_4): Tarefa 4: vetores e matrizes
- [Prj_For](../Prj_For): Laço for

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: limites dos tipos inteiros](https://en.cppreference.com/w/c/types/limits)
- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)

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
