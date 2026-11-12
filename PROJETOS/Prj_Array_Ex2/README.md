# Projeto Prj_Array_Ex2 (C) 🔤

> **Arrays de strings**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê três nomes, mostra os nomes na **ordem inversa** e depois cada nome com o seu comprimento, calculado por `strlen`.

## 🎯 Conceitos trabalhados

- Array de strings (`char nomes[3][30]`)
- Laço `for` decrescente
- `strlen` e o especificador `%zu` para `size_t`

## 📚 Entendendo o conceito

Este projeto trabalha **Vetores (arrays)** e **Strings em C**.

### Vetores (arrays)

Um **vetor** guarda vários valores do mesmo tipo em posições **contíguas** de memória, acessadas por um índice que começa em **0**. Em `int v[5];` os índices válidos vão de `v[0]` a `v[4]`.

Acessar `v[i]` custa O(1) porque o endereço é calculado direto: início do vetor + `i` × tamanho do elemento. Em compensação, o tamanho é fixo, e C **não verifica os limites**: ler `v[5]` não dá erro de compilação, apenas lê o que estiver na memória ao lado. Quando um vetor é passado para uma função, ele vira um ponteiro para o primeiro elemento, e o tamanho precisa ir junto como parâmetro.

#### 🌍 Onde é usado na prática

- Qualquer lista de tamanho conhecido: notas de uma turma, leituras de um sensor, *pixels* de uma linha de imagem.
- A memória contígua aproveita o *cache* do processador; por isso percorrer um vetor é muito mais rápido que percorrer uma lista encadeada.
- É a base de estruturas mais sofisticadas: pilhas e filas em vetor, *heaps*, tabelas *hash*.

#### 💼 Em processos seletivos

Vetores são o tema mais frequente em entrevistas técnicas. Os padrões que mais caem são **dois ponteiros**, **janela deslizante**, **soma de prefixos** e o uso de *hash* para contar elementos.

Perguntas que costumam aparecer:

- Some, calcule a média e encontre o maior elemento.
- Inverta um vetor no próprio lugar.
- Dado um vetor e um alvo, encontre dois números que somam o alvo (Two Sum).
- Por que o índice começa em 0?

#### ⏱️ Complexidade

Acesso por índice O(1); busca de um valor O(n); inserir no meio O(n), porque é preciso deslocar os elementos.

#### 🐞 Erros comuns

- Ler ou escrever fora dos limites (`i <= n`).
- Usar `sizeof(v) / sizeof(v[0])` dentro de uma função que recebeu o vetor por parâmetro (ali `v` é ponteiro, e a conta dá errado).
- Esquecer de inicializar o vetor antes de somar os elementos.

### Strings em C

C não tem um tipo `string`: uma string é um **vetor de `char` terminado pelo caractere nulo `'\0'`**. A palavra `"FUMEC"` ocupa 6 bytes, 5 letras mais o `'\0'`. Todas as funções de `<string.h>` dependem desse terminador para saber onde o texto acaba.

| Função | O que faz |
| --- | --- |
| `strlen(s)` | Conta os caracteres até o `'\0'` (sem contá-lo) |
| `strcpy(dest, orig)` | Copia `orig` para `dest`, incluindo o `'\0'` |
| `strcat(dest, orig)` | Acrescenta `orig` no fim de `dest` |
| `strcmp(a, b)` | Compara: 0 se iguais, negativo ou positivo conforme a ordem |

Nenhuma delas confere o tamanho do destino. Por isso estouros de *buffer* em strings estão entre as falhas de segurança mais antigas e mais exploradas.

#### 🌍 Onde é usado na prática

- Processamento de texto: validar CPF ou e-mail, contar palavras, montar mensagens.
- Protocolos de rede baseados em texto (HTTP, SMTP) e formatos como CSV e JSON.
- Falhas históricas de segurança (como o *worm* de Morris, de 1988, que explorou a função `gets`) vieram de strings sem limite de tamanho.

#### 💼 Em processos seletivos

Manipulação de strings é um dos temas mais cobrados: palíndromos, anagramas, inverter palavras, contar caracteres, compressão simples, encontrar uma substring. Em C, também é comum pedirem para **reimplementar** `strlen`, `strcpy` ou `strcmp` sem a biblioteca.

Perguntas que costumam aparecer:

- Implemente `strlen` e `strcpy` com ponteiros.
- Verifique se duas palavras são anagramas.
- Inverta as palavras de uma frase.
- Por que `gets` foi removida da linguagem?

#### ⏱️ Complexidade

`strlen` é O(n), porque precisa percorrer a string até achar o `'\0'`; chamar `strlen` na condição de um `for` deixa o laço O(n²).

#### 🐞 Erros comuns

- Esquecer espaço para o `'\0'`.
- Comparar strings com `==` (compara endereços, não o texto). Use `strcmp`.
- Atribuir com `=` depois da declaração (`nome = "Ana";` não compila). Use `strcpy`.
- Ler com `gets` ou com `scanf("%s")` sem limite. Use `fgets(s, sizeof s, stdin)` ou `scanf("%99s", s)`.

## 🧠 Como funciona o código

```c
int main(void) {

    // Declaração de um array de strings para armazenar três nomes
    char nomes[3][30];  // Supondo nomes com até 30 caracteres

    // Solicitar ao usuário para inserir três nomes
    for (int i = 0; i < 3; i++) {
        printf("Digite o %do nome: ", i + 1);
        scanf("%s", nomes[i]);
    }

    // Imprimir os nomes na ordem inversa
    printf("\nNomes na ordem inversa:\n");
    for (int i = 2; i >= 0; i--) {
        printf("%s\n", nomes[i]);
    }

    // Imprimir os nomes e seus comprimentos
    printf("\nNomes e comprimentos:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s - Comprimento: %zu\n", nomes[i], strlen(nomes[i]));
        //%zu é um especificador de formato usado em linguagem C para imprimir valores do tipo size_t.
        //Ele é particularmente útil quando você está trabalhando com funções que retornam valores do tipo size_t,
        //como strlen, que retorna o comprimento de uma string.
    }

    return 0;
}
```

No `scanf("%s", nomes[i])` não vai `&`: o nome de um array já é o endereço do primeiro elemento. O `%s` para no primeiro espaço, então nomes compostos ("Ana Clara") são lidos só até "Ana".

## 💻 Exemplo de execução

```text
Digite o 1o nome: Ana
Digite o 2o nome: Bruno
Digite o 3o nome: Carla

Nomes na ordem inversa:
Carla
Bruno
Ana

Nomes e comprimentos:
Ana - Comprimento: 3
Bruno - Comprimento: 5
Carla - Comprimento: 5
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Ex2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Ex2`:

```bash
gcc src/Prj_Array_Ex2.c -o Prj_Array_Ex2
./Prj_Array_Ex2
```

No Windows, rode `Prj_Array_Ex2.exe` (ou `.\Prj_Array_Ex2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Ex2
│
├── 📁 src
│   └── Prj_Array_Ex2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1: Two Sum](https://leetcode.com/problems/two-sum/)
- [LeetCode 1480: Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Beecrowd 1172: Substituição em Vetor I](https://judge.beecrowd.com/pt/problems/view/1172)
- [Beecrowd 1173: Preenchimento de Vetor I](https://judge.beecrowd.com/pt/problems/view/1173)
- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

## 🔗 Projetos relacionados

- [Prj_Array_Ex1](../Prj_Array_Ex1): Arrays: declaração e percurso
- [Prj_StrLen](../Prj_StrLen): Tamanho de string com strlen

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays](https://en.cppreference.com/w/c/language/array)
- [cppreference: inicialização de arrays](https://en.cppreference.com/w/c/language/array_initialization)
- [cppreference: biblioteca de strings (<string.h>)](https://en.cppreference.com/w/c/string/byte)
- [cppreference: strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [cppreference: strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [cppreference: strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)

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
