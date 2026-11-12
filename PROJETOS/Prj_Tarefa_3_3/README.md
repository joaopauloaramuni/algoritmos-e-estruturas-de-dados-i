# Projeto Prj_Tarefa_3_3 (C) 🏀

> **Tarefa 3.3: seleção de basquete**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do exercício 3 da **Tarefa 3**: com idade, altura (em cm) e sexo, informa se a pessoa está apta para o time juvenil feminino ou masculino de basquete.

📄 Enunciado: [Tarefa 3 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%203.pdf)

## 🎯 Conceitos trabalhados

- `if` aninhado
- Operador lógico `&&`
- Validação de uma opção codificada (1 ou 2)

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
// Função para validar a situação da pessoa
void validarSituacao(int idade, int altura, int sexo) {
    if (altura >= 180 && idade > 16) {
        if (sexo == 1) {
            printf("Apta a jogar no time Feminino Juvenil de Basquete.\n");
        } else if (sexo == 2) {
            printf("Apto a jogar no time Masculino Juvenil de Basquete.\n");
        } else {
            printf("Não apto.\n");
        }
    } else {
        printf("Não apto.\n");
    }
}
```

A regra comum (altura ≥ 180 cm **e** idade > 16) fica no `if` de fora. Só depois o sexo decide o time. Qualquer código de sexo diferente de 1 ou 2 também resulta em "Não apto".

## 💻 Exemplo de execução

```text
Digite a idade do candidato: 17
Digite a altura do candidato (em cm): 182
Digite o sexo do candidato (Feminino=1, Masculino=2): 1
Apta a jogar no time Feminino Juvenil de Basquete.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_3_3` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_3_3`:

```bash
gcc src/Prj_Tarefa_3_3.c -o Prj_Tarefa_3_3
./Prj_Tarefa_3_3
```

No Windows, rode `Prj_Tarefa_3_3.exe` (ou `.\Prj_Tarefa_3_3.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_3_3
│
├── 📁 src
│   └── Prj_Tarefa_3_3.c
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

- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Tarefa_3_2](../Prj_Tarefa_3_2): Tarefa 3.2: gasto de um fumante
- [Prj_IMC](../Prj_IMC): Cálculo do IMC

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
