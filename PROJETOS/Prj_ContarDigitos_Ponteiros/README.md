# Projeto Prj_ContarDigitos_Ponteiros (C) 🔢

> **Contar dígitos com ponteiros**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Conta quantos dígitos tem um número inteiro (`12345` tem 5). O resultado volta para o `main` por um ponteiro.

## 🎯 Conceitos trabalhados

- Divisão inteira por 10 para remover o último dígito
- Parâmetro de saída por ponteiro
- Caso especial do zero

## 📚 Entendendo o conceito

Este projeto trabalha **Ponteiros e passagem por referência** e **Operadores aritméticos, divisão inteira e resto**.

### Ponteiros e passagem por referência

Um **ponteiro** é uma variável que guarda um **endereço de memória**. O operador `&` pega o endereço de uma variável (`&x`) e o operador `*` acessa o valor que está naquele endereço (`*p`, a **desreferência**). Em `int *p = &x;`, `p` aponta para `x`, e `*p = 10;` muda o próprio `x`.

Como C só tem passagem por valor, ponteiros são a forma de uma função **alterar variáveis de quem a chamou** (passagem por referência) e de **devolver mais de um resultado** (parâmetros de saída). Vetores também são acessados por ponteiros: `v[i]` é exatamente `*(v + i)`.

#### 🌍 Onde é usado na prática

- Funções da biblioteca padrão que preenchem variáveis: `scanf("%d", &x)`, `strtol(texto, &fim, 10)`.
- Estruturas de dados encadeadas (listas, pilhas, filas, árvores, grafos) são feitas de nós ligados por ponteiros.
- Passar estruturas grandes por ponteiro evita copiá-las a cada chamada.
- Linguagens como Java, Python e C# usam referências, que são ponteiros com proteções; entender ponteiros explica por que `a = b` em objetos não copia o objeto.

#### 💼 Em processos seletivos

Ponteiros são tema certo em vagas de C, C++, sistemas embarcados e jogos, e aparecem indiretamente em qualquer vaga quando o assunto é lista encadeada ou passagem por referência. A pergunta clássica é escrever a função `troca` (*swap*) e explicar por que a versão sem ponteiros não funciona.

Perguntas que costumam aparecer:

- Escreva `void troca(int *a, int *b)`.
- Qual a diferença entre `int *p`, `*p` e `&p`?
- O que é um ponteiro nulo? E um ponteiro pendente (*dangling pointer*)?
- Por que `*p++` e `(*p)++` fazem coisas diferentes?

#### 🐞 Erros comuns

- Desreferenciar ponteiro não inicializado ou `NULL` (*segmentation fault*).
- Imprimir endereço com `%d` em vez de `%p`.
- Usar o ponteiro depois de liberar a memória para onde ele apontava.

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
// Função que conta o número de dígitos de um número inteiro
void contarDigitos(int *numero, int *quantidade) {
    int n = *numero;
    *quantidade = 0;

    // Se o número for zero, conta como um dígito
    if (n == 0) {
        *quantidade = 1;
        return;
    }

    // Conta os dígitos
    while (n != 0) {
        n /= 10; // Remove o último dígito
        (*quantidade)++; // Incrementa o contador
    }
}
```

Cada `n /= 10` tira o último dígito: `12345 → 1234 → 123 → 12 → 1 → 0`. São 5 divisões até zerar, então 5 dígitos. O `0` é tratado à parte porque o `while (n != 0)` nem entraria e o resultado seria 0 dígitos. Repare em `(*quantidade)++`: os parênteses fazem o `++` agir sobre o valor, não sobre o ponteiro. A versão recursiva do mesmo raciocínio está no [Prj_Soma_Recursiva](../Prj_Soma_Recursiva).

## 💻 Exemplo de execução

```text
Número: 12345
Quantidade de dígitos: 5
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ContarDigitos_Ponteiros` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ContarDigitos_Ponteiros`:

```bash
gcc src/Prj_ContarDigitos.c -o Prj_ContarDigitos_Ponteiros
./Prj_ContarDigitos_Ponteiros
```

No Windows, rode `Prj_ContarDigitos_Ponteiros.exe` (ou `.\Prj_ContarDigitos_Ponteiros.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ContarDigitos_Ponteiros
│
├── 📁 src
│   └── Prj_ContarDigitos.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 344: Reverse String (dois ponteiros)](https://leetcode.com/problems/reverse-string/)
- [LeetCode 283: Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva](../Prj_Soma_Recursiva): Soma recursiva dos dígitos
- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: ponteiros](https://en.cppreference.com/w/c/language/pointer)
- [Paulo Feofiloff (IME-USP): endereços e ponteiros](https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html)
- [Python Tutor: visualizar ponteiros em C passo a passo](https://pythontutor.com/c.html)
- [cppreference: operadores aritméticos](https://en.cppreference.com/w/c/language/operator_arithmetic)
- [cppreference: conversões implícitas](https://en.cppreference.com/w/c/language/conversion)

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
