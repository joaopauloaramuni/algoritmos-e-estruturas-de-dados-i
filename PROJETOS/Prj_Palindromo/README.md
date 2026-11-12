# Projeto Prj_Palindromo (C) 🔄

> **Palíndromo (iterativo)**. Tema: **Strings**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se uma palavra é um **palíndromo** (lida igual de trás para frente, como ARARA, OVO e OTTO) comparando as letras das pontas para o meio com dois índices.

## 🎯 Conceitos trabalhados

- Dois índices em um mesmo `for` (`i++, j--`)
- `break` para sair do laço
- Variável *flag* (`palindromo`)

## 📚 Entendendo o conceito

Este projeto trabalha **Palíndromos e a técnica de dois ponteiros** e **Strings em C**.

### Palíndromos e a técnica de dois ponteiros

Um **palíndromo** é uma palavra ou frase que se lê igual nos dois sentidos: ARARA, OVO, RADAR. A forma eficiente de verificar é a técnica de **dois ponteiros**: um índice começa no início, outro no fim, e os dois andam em direção ao meio comparando os caracteres. Se algum par for diferente, não é palíndromo; se os índices se cruzarem, é.

A mesma verificação tem uma forma recursiva natural: a palavra é palíndromo se as pontas são iguais **e** o miolo também é palíndromo.

#### 🌍 Onde é usado na prática

- A técnica de dois ponteiros resolve muitos problemas em vetores ordenados (achar pares com soma alvo, remover duplicados) sem memória extra.
- Bioinformática: sequências palindrômicas de DNA marcam pontos de corte de enzimas de restrição.

#### 💼 Em processos seletivos

"Verifique se uma string é palíndromo" é uma das perguntas de aquecimento mais comuns. As variações ignoram maiúsculas, espaços e pontuação, permitem remover um caractere ou pedem o maior palíndromo dentro de uma string. Dois ponteiros é um dos padrões que mais caem em entrevistas.

Perguntas que costumam aparecer:

- Verifique um palíndromo sem criar uma cópia invertida.
- Ignore espaços e maiúsculas ("Socorram-me, subi no ônibus em Marrocos").
- Verifique se um número inteiro é palíndromo sem convertê-lo em texto.

#### ⏱️ Complexidade

O(n) de tempo; O(1) de memória com dois ponteiros (O(n) se criar uma cópia invertida).

#### 🐞 Erros comuns

- Comparar além do `'\0'`.
- Esquecer que maiúsculas e minúsculas são caracteres diferentes.

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
int main(void) { // Palíndromo - ARARA - OVO - OTTO - SOCORRAMMESUBINOONIBUSEMMARROCOS
    char palavra[100];
    int i, j, tamanho;
    int palindromo = 1;

    printf("Digite uma palavra: ");
    fflush(stdout);
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    //A comparação acontece de fora pra dentro
    //  A R A R A
    //i=A R
    //j=      R A
    // Verificar se é um palíndromo
    for(i = 0, j = tamanho - 1; i < j; i++, j--) {
        printf("i: %c\n", palavra[i]);
        printf("j: %c\n", palavra[j]);
        if(palavra[i] != palavra[j]) {
            palindromo = 0;
            break;
        }
    }
    if(palindromo) {
        printf("\nA palavra é um palíndromo.\n");
    } else {
        printf("\nA palavra não é um palíndromo.\n");
    }

    return 0;
}
```

`i` começa na primeira letra e `j` na última. A cada volta os dois andam um passo para o meio, e o laço para quando se cruzam (`i < j`). Os `printf` de `i` e `j` dentro do laço estão lá para acompanhar as comparações. A frase do comentário, SOCORRAMMESUBINOONIBUSEMMARROCOS, também é um palíndromo.

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
i: A
j: A
i: R
j: R

A palavra é um palíndromo.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Palindromo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Palindromo`:

```bash
gcc src/Prj_Palindromo.c -o Prj_Palindromo
./Prj_Palindromo
```

No Windows, rode `Prj_Palindromo.exe` (ou `.\Prj_Palindromo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Palindromo
│
├── 📁 src
│   └── Prj_Palindromo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [LeetCode 9: Palindrome Number](https://leetcode.com/problems/palindrome-number/)
- [LeetCode 680: Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)
- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)

## 🔗 Projetos relacionados

- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_Pali+File](../Prj_Pali+File): Palíndromos gravados em arquivo

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [pali](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/pali)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Palindrome](https://en.wikipedia.org/wiki/Palindrome)
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
