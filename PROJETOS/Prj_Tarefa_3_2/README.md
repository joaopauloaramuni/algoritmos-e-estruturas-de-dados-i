# Projeto Prj_Tarefa_3_2 (C) 🚭

> **Tarefa 3.2: gasto de um fumante**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do exercício 2 da **Tarefa 3**: calcula quantos cigarros uma pessoa fumou ao longo da vida e quanto gastou, considerando 20 cigarros por maço. Como extra, estima o tempo de vida perdido (11 minutos por cigarro).

📄 Enunciado: [Tarefa 3 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%203.pdf)

## 🎯 Conceitos trabalhados

- Funções de cálculo
- Mistura de `int` e `float` (`/ 20.0`)
- Conversão de unidades (minutos para horas)

## 📚 Entendendo o conceito

Este projeto trabalha **Funções e procedimentos** e **Operadores aritméticos, divisão inteira e resto**.

### Funções e procedimentos

Uma **função** é um bloco de código com nome, que recebe **parâmetros** e pode devolver um valor com `return`. Quando não devolve nada (`void`), costuma ser chamada de **procedimento**. O **protótipo** (`int soma(int a, int b);`) declara a função antes do uso, para o compilador conhecer a assinatura.

Em C, os argumentos são **passados por valor**: a função recebe uma cópia, e alterar o parâmetro não muda a variável de quem chamou. Para alterar uma variável de fora, passa-se o endereço dela (um ponteiro). As variáveis declaradas dentro da função são **locais**: nascem na chamada e somem no `return`.

#### 🌍 Onde é usado na prática

- Evitar repetição: o mesmo cálculo usado em vários lugares vira uma função (o princípio DRY, *Don't Repeat Yourself*).
- Testes automatizados testam funções isoladas; código todo dentro do `main` é difícil de testar.
- Bibliotecas (como a `<string.h>` e a `<math.h>`) são conjuntos de funções.

#### 💼 Em processos seletivos

Em entrevistas práticas (*live coding*), dividir a solução em funções pequenas e bem nomeadas é um dos sinais de maturidade mais observados. Também é comum perguntarem a diferença entre passagem por valor e por referência.

Perguntas que costumam aparecer:

- Qual a diferença entre passar por valor e por referência?
- Para que serve o protótipo de uma função?
- Uma função pode devolver mais de um valor em C? Como?

#### 🐞 Erros comuns

- Chamar a função antes de declarar e sem protótipo.
- Esperar que alterar o parâmetro mude a variável original.
- Devolver o endereço de uma variável local (ela deixa de existir no `return`).

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
// Função para calcular o total gasto
float calcularTotalGasto(int cigarrosAoLongoDaVida, float precoMaco) {
    return (cigarrosAoLongoDaVida / 20.0) * precoMaco;
}
```

```c
// Função para calcular o tempo de vida perdido
float calcularTempoVidaPerdido(int cigarrosAoLongoDaVida) {
    // Estimativa de que cada cigarro reduz 11 minutos de vida
    return cigarrosAoLongoDaVida * 11 / 60.0;
}
```

Dividir por `20.0` (e não `20`) força a conta em ponto flutuante, para não perder os maços incompletos. Com 10 anos, 20 cigarros por dia e maço a R$ 12,50: `10 × 365 × 20 = 73.000` cigarros, `3.650` maços e R$ 45.625,00.

## 💻 Exemplo de execução

```text
Digite o número de anos que você fuma: 10
Digite o número de cigarros fumados por dia: 20
Digite o preço médio de um maço de cigarros: 12.50

Número de cigarros fumados ao longo da vida: 73000
Total gasto: R$45625.00
Tempo de vida perdido devido com o hábito de fumar: 13383.33 horas
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_3_2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_3_2`:

```bash
gcc src/Prj_Tarefa_3_2.c -o Prj_Tarefa_3_2
./Prj_Tarefa_3_2
```

No Windows, rode `Prj_Tarefa_3_2.exe` (ou `.\Prj_Tarefa_3_2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_3_2
│
├── 📁 src
│   └── Prj_Tarefa_3_2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1009: Salário com Bônus](https://judge.beecrowd.com/pt/problems/view/1009)
- [Beecrowd 1048: Aumento de Salário](https://judge.beecrowd.com/pt/problems/view/1048)
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 🔗 Projetos relacionados

- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Tarefa_3_3](../Prj_Tarefa_3_3): Tarefa 3.3: seleção de basquete

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: declaração de funções](https://en.cppreference.com/w/c/language/function_declaration)
- [cppreference: definição de funções](https://en.cppreference.com/w/c/language/function_definition)
- [cppreference: return](https://en.cppreference.com/w/c/language/return)
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
