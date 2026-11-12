# Projeto Prj_CondicionalComposta (C) ✅

> **Condicional composta (if/else)**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê três notas, soma e informa se o aluno foi **Aprovado** (soma maior ou igual a 60) ou **Reprovado**. Mostra o `if/else`, em que sempre um dos dois caminhos é executado.

## 🎯 Conceitos trabalhados

- Estrutura condicional composta `if / else`
- Leitura de vários valores em um `scanf`
- Operador `>=`

## 📚 Entendendo o conceito

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
    float Nota1, Nota2, Nota3, NotaF;

    printf("Entre com as notas do aluno: ");
    scanf("%f %f %f", &Nota1, &Nota2, &Nota3);

    NotaF = Nota1 + Nota2 + Nota3;

    if (NotaF >= 60) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
```

As três notas podem ser digitadas na mesma linha, separadas por espaço, porque o formato `"%f %f %f"` lê os três valores de uma vez. A regra de aprovação (60 pontos no total) é a mesma usada nas disciplinas da PUC Minas.

## 💻 Exemplo de execução

```text
Entre com as notas do aluno: 20 25 30
Aprovado
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_CondicionalComposta` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_CondicionalComposta`:

```bash
gcc src/Prj_CondicionalComposta.c -o Prj_CondicionalComposta
./Prj_CondicionalComposta
```

No Windows, rode `Prj_CondicionalComposta.exe` (ou `.\Prj_CondicionalComposta.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_CondicionalComposta
│
├── 📁 src
│   └── Prj_CondicionalComposta.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1035: Teste de Seleção 1](https://judge.beecrowd.com/pt/problems/view/1035)
- [Beecrowd 1036: Fórmula de Bhaskara](https://judge.beecrowd.com/pt/problems/view/1036)
- [Beecrowd 1037: Intervalo](https://judge.beecrowd.com/pt/problems/view/1037)
- [Beecrowd 1041: Coordenadas de um Ponto](https://judge.beecrowd.com/pt/problems/view/1041)

## 🔗 Projetos relacionados

- [Prj_CondicionalSimples](../Prj_CondicionalSimples): Condicional simples (if)
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)
- [Prj_Ternario](../Prj_Ternario): Operador ternário

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

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
