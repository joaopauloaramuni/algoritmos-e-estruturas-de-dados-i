# Projeto Prj_Smith (C) 🔬

> **Números de Smith**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se um número é um **número de Smith**: um número composto em que a soma dos dígitos é igual à soma dos dígitos dos seus fatores primos. Exemplos: 4, 22, 27, 58, 85 e 94.

## 🎯 Conceitos trabalhados

- Soma de dígitos
- Teste de primalidade até a raiz quadrada (`i * i <= num`)
- Fatoração em primos
- Composição de funções pequenas

## 📚 Entendendo o conceito

### Números primos, dígitos e números de Smith

Um número **primo** só é divisível por 1 e por ele mesmo. Para testar se `n` é primo, basta tentar divisores até **√n** (`i * i <= n`): se `n` tivesse um divisor maior que √n, teria também um menor, que já teria sido encontrado. Todo inteiro maior que 1 se decompõe de forma única em fatores primos (22 = 2 × 11).

Um **número de Smith** é um número composto cuja soma dos dígitos é igual à soma dos dígitos dos seus fatores primos: 22 tem dígitos 2 + 2 = 4 e fatores 2 e 11, com dígitos 2 + 1 + 1 = 4. Problemas assim combinam três técnicas pequenas: extrair dígitos com `% 10` e `/ 10`, testar primalidade e fatorar.

#### 🌍 Onde é usado na prática

- Criptografia de chave pública (RSA) depende da dificuldade de fatorar números com centenas de dígitos.
- Dígitos verificadores (CPF, cartões de crédito com o algoritmo de Luhn, ISBN) usam somas e restos de dígitos.
- Funções *hash* e geradores pseudoaleatórios costumam usar primos.

#### 💼 Em processos seletivos

Teste de primalidade, crivo de Eratóstenes, soma de dígitos e números "especiais" (felizes, feios, perfeitos, Armstrong) são exercícios frequentes em testes online de nível inicial e em maratonas. O que se avalia é a otimização até √n e o tratamento dos casos 0, 1 e 2.

Perguntas que costumam aparecer:

- Teste se um número é primo em O(√n).
- Liste todos os primos até n (crivo de Eratóstenes).
- Some os dígitos de um número até restar um só dígito.

#### ⏱️ Complexidade

Teste de primalidade por divisão: O(√n). Crivo de Eratóstenes até n: O(n log log n).

#### 🐞 Erros comuns

- Considerar 1 como primo.
- Testar divisores até n em vez de √n.

## 🧠 Como funciona o código

```c
// Função para verificar se um número é primo
int eh_primo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}
```

```c
// Função para calcular a soma dos dígitos dos fatores primos de um número
int soma_digitos_fatores_primos(int num) {
    int soma = 0;
    int fator = 2;
    while (num > 1) {
        while (num % fator == 0) {
            soma += soma_digitos(fator);
            num /= fator;
        }
        fator++;
        while (!eh_primo(fator)) {
            fator++;
        }
    }
    return soma;
}
```

Para `22`: os dígitos somam `2 + 2 = 4`; os fatores primos são `2 × 11`, e os dígitos deles somam `2 + 1 + 1 = 4`. Como `4 = 4`, 22 é um número de Smith. Números primos ficam de fora pela definição (seriam todos de Smith, trivialmente).

## 💻 Exemplo de execução

```text
Digite um número: 22
22 é um número de Smith.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Smith` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Smith`:

```bash
gcc src/Prj_Smith.c -o Prj_Smith
./Prj_Smith
```

No Windows, rode `Prj_Smith.exe` (ou `.\Prj_Smith.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Smith
│
├── 📁 src
│   └── Prj_Smith.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 204: Count Primes](https://leetcode.com/problems/count-primes/)
- [LeetCode 258: Add Digits](https://leetcode.com/problems/add-digits/)
- [LeetCode 202: Happy Number](https://leetcode.com/problems/happy-number/)
- [Beecrowd 1165: Número Primo](https://judge.beecrowd.com/pt/problems/view/1165)

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva](../Prj_Soma_Recursiva): Soma recursiva dos dígitos
- [Prj_ContarDigitos_Ponteiros](../Prj_ContarDigitos_Ponteiros): Contar dígitos com ponteiros

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Smith number](https://en.wikipedia.org/wiki/Smith_number)
- [Wikipedia: Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

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
