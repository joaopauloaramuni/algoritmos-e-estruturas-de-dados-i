# Projeto Prj_Palindromo_Recursivo (C) 🔁

> **Palíndromo recursivo**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se uma palavra é palíndromo com recursão, em duas versões: uma de uma linha só (com ternário e `&&`) e outra passo a passo, com comentários que rastreiam cada chamada para ARARA.

## 🎯 Conceitos trabalhados

- Recursão com dois índices (`left` e `right`)
- Curto-circuito do `&&`
- Rastreamento de chamadas recursivas

## 📚 Entendendo o conceito

Este projeto trabalha **Recursividade** e **Palíndromos e a técnica de dois ponteiros**.

### Recursividade

Uma função **recursiva** resolve um problema chamando a si mesma para uma versão **menor** do mesmo problema. Toda recursão correta tem duas partes:

1. **Caso base**: a versão tão pequena que a resposta é direta (o fatorial de 0 é 1; uma lista vazia tem soma 0).
2. **Passo recursivo**: reduz o problema e combina o resultado da chamada menor (`n! = n × (n-1)!`).

Cada chamada ganha um espaço próprio na **pilha de chamadas** (*call stack*), com as suas variáveis locais. As chamadas vão sendo empilhadas até o caso base e depois são resolvidas na ordem inversa, "de baixo para cima". Se o caso base nunca é alcançado, a pilha enche e o programa quebra com *stack overflow*.

Todo algoritmo recursivo pode ser reescrito com laços (e uma pilha explícita, se preciso). A recursão vale a pena quando o problema **já é recursivo por natureza**: árvores, divisão e conquista, combinações, *backtracking*.

#### 🌍 Onde é usado na prática

- Percorrer estruturas recursivas: pastas dentro de pastas no sistema de arquivos, o DOM de uma página HTML, um JSON aninhado, árvores de decisão.
- Algoritmos de divisão e conquista: *Merge Sort*, *Quicksort* (veja o artigo de Hoare, de 1961), busca binária.
- *Backtracking*: Sudoku, labirintos, problema das 8 rainhas, gerar permutações.
- Compiladores e interpretadores analisam expressões com funções recursivas (*recursive descent parser*).

#### 💼 Em processos seletivos

Recursão é um dos temas **mais cobrados** em etapas técnicas, de estágio a vagas sênior. Ela aparece sozinha (fatorial, Fibonacci, potência, inverter uma string) e, principalmente, como ferramenta para problemas de árvores, grafos, *backtracking* e programação dinâmica. Os avaliadores costumam pedir para você **explicar a pilha de chamadas**, identificar o caso base e dizer a complexidade de tempo e de memória. Um passo seguinte comum é otimizar o Fibonacci recursivo com **memoização** (guardar resultados já calculados).

Perguntas que costumam aparecer:

- Qual o caso base e o passo recursivo desta função?
- Qual a complexidade do Fibonacci recursivo ingênuo? Como melhorar? (O(2ⁿ) → O(n) com memoização ou laço.)
- O que é *stack overflow* e quando acontece em recursão?
- Converta esta recursão em um laço.
- O que é recursão de cauda (*tail recursion*)?

#### ⏱️ Complexidade

Depende de quantas chamadas são feitas e do trabalho em cada uma. Fatorial e soma de um vetor fazem n chamadas: O(n) de tempo e O(n) de pilha. Fibonacci ingênuo faz duas chamadas por nível: O(2ⁿ). A memória usada pela pilha cresce com a **profundidade** da recursão.

#### 🐞 Erros comuns

- Esquecer o caso base, ou ter um caso base que nunca é atingido (por exemplo, fatorial de número negativo).
- Não reduzir o problema a cada chamada.
- Recalcular os mesmos subproblemas várias vezes (Fibonacci).
- Usar recursão profunda (milhares de níveis) onde um laço simples resolve.

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

## 🧠 Como funciona o código

```c
int isPalindrome(char str[], int left, int right) {
    return (left >= right) ? 1 : (str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}
```

```c
int isPalindrome2(char str[], int left, int right) {
    // Quarta chamada recursiva: 3 >= 2 true
    // Terceira chamada recursiva: 2 >= 3 falso
    // Segunda chamada recursiva: 1 >= 4 falso
    // Primeira chamada recursiva: 0 >= 5 falso
    if (left >= right)
        return 1;

    // Quarta chamada recursiva: retornou 1 acima
    // Terceira chamada recursiva: A != A ? falso
    // Segunda chamada recursiva: R != R ? falso
    // Primeira chamada recursiva: A != A ? falso
    if (str[left] != str[right])
        // Verifica se os caracteres nos extremos são iguais
        return 0;

    // Chama recursivamente para o próximo par de caracteres
    return isPalindrome2(str, left + 1, right - 1);
    // Quarta chamada recursiva: ARARA -> R != A (Não chega a fazer esse teste) [left == 3 e right == 2]
    // Terceira chamada recursiva: ARXRA -> A != A [left == 2 e right == 3]
    // Segunda chamada recursiva: AXAXA -> R != R [left == 1 e right == 4]
    // Primeira chamada recursiva: XRARX -> A != A [left == 0 e right == 5]
    // >> ARARA <<
}
```

Se as letras das pontas são diferentes, não é palíndromo. Se são iguais, a resposta depende do pedaço de dentro, e a função chama a si mesma com `left + 1` e `right - 1`. Na versão de uma linha, o `&&` só faz a chamada recursiva se a comparação das pontas for verdadeira (curto-circuito).

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
Tamanho: 5 
A palavra é um palíndromo.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Palindromo_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Palindromo_Recursivo`:

```bash
gcc src/Prj_Palindromo_Recursivo.c -o Prj_Palindromo_Recursivo
./Prj_Palindromo_Recursivo
```

No Windows, rode `Prj_Palindromo_Recursivo.exe` (ou `.\Prj_Palindromo_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Palindromo_Recursivo
│
├── 📁 src
│   └── Prj_Palindromo_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [LeetCode 206: Reverse Linked List (versão recursiva)](https://leetcode.com/problems/reverse-linked-list/)
- [Beecrowd 1029: Fibonacci, Quantas Chamadas?](https://judge.beecrowd.com/pt/problems/view/1029)
- [Beecrowd 1153: Fatorial Simples](https://judge.beecrowd.com/pt/problems/view/1153)
- [LeetCode 125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

## 🔗 Projetos relacionados

- [Prj_Palindromo](../Prj_Palindromo): Palíndromo (iterativo)
- [Prj_Pali+File](../Prj_Pali+File): Palíndromos gravados em arquivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [String_Recursivo](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/String_Recursivo)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): recursão e algoritmos recursivos](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
- [VisuAlgo: visualização de recursão](https://visualgo.net/en/recursion)
- [Wikipedia: recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Python Tutor: veja a pilha de chamadas em C](https://pythontutor.com/c.html)
- [Wikipedia: Palindrome](https://en.wikipedia.org/wiki/Palindrome)

**Ferramentas e referências gerais**

- [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
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
