# Projeto Prj_Array_Exer1 (C) ➗

> **Exercício: soma e média de um array**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê 5 inteiros em um array, calcula a **soma** durante a leitura e mostra a **média** com duas casas decimais.

## 🎯 Conceitos trabalhados

- Leitura de array com `for`
- Acumulador
- Conversão `(double)` para evitar divisão inteira

## 📚 Entendendo o conceito

Este projeto trabalha **Vetores (arrays)** e **Operadores aritméticos, divisão inteira e resto**.

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
    int numeros[5];
    int soma = 0;

    printf("Digite 5 números inteiros:\n");

    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma = soma + numeros[i];
    }

    double media = (double) soma / 5;

    printf("Soma: %d\n", soma);
    printf("Média: %.2lf\n", media);

    return 0;
}
```

`(double) soma / 5` converte a soma antes de dividir. Sem a conversão, `151 / 5` daria `30` (divisão inteira) em vez de `30.20`.

## 💻 Exemplo de execução

```text
Digite 5 números inteiros:
Número 1: 10
Número 2: 20
Número 3: 30
Número 4: 40
Número 5: 50
Soma: 150
Média: 30.00
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Exer1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Exer1`:

```bash
gcc src/Prj_Array_Exer1.c -o Prj_Array_Exer1
./Prj_Array_Exer1
```

No Windows, rode `Prj_Array_Exer1.exe` (ou `.\Prj_Array_Exer1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Exer1
│
├── 📁 src
│   └── Prj_Array_Exer1.c
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
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 🔗 Projetos relacionados

- [Prj_Prova_AV2](../Prj_Prova_AV2): Prova AV2: arrays e recursão
- [Prj_Tarefa_4](../Prj_Tarefa_4): Tarefa 4: vetores e matrizes

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays](https://en.cppreference.com/w/c/language/array)
- [cppreference: inicialização de arrays](https://en.cppreference.com/w/c/language/array_initialization)
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
