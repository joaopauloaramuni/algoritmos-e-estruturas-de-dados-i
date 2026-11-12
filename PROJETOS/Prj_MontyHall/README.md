# Projeto Prj_MontyHall (C) 🚪

> **Problema de Monty Hall**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Simula o famoso **problema de Monty Hall**: o jogador escolhe uma de três portas, o apresentador abre uma porta vazia e pergunta se o jogador quer trocar. Trocar ganha em 2/3 das vezes; manter, em 1/3.

## 🎯 Conceitos trabalhados

- Sorteio da porta premiada
- Laço `do-while` para sortear até achar uma porta válida
- Validação da entrada
- Probabilidade condicional

## 📚 Entendendo o conceito

Este projeto trabalha **Probabilidade e o problema de Monty Hall** e **Números aleatórios (rand e srand)**.

### Probabilidade e o problema de Monty Hall

No problema de Monty Hall, há três portas, um prêmio atrás de uma delas, e o jogador escolhe uma. O apresentador, que sabe onde está o prêmio, abre uma das outras portas, sempre vazia, e oferece a troca. **Trocar ganha em 2/3 das vezes**; manter, em 1/3.

A intuição falha porque o apresentador não escolhe ao acaso: a chance de 1/3 da primeira escolha não muda, e os 2/3 restantes, que estavam espalhados nas outras duas portas, ficam concentrados na porta que sobrou. Uma simulação com milhares de rodadas confirma o resultado e é o jeito mais convincente de mostrar isso.

#### 🌍 Onde é usado na prática

- Testes A/B, análise de risco e qualquer decisão que dependa de informação nova (probabilidade condicional e teorema de Bayes).
- Simulação de Monte Carlo: quando a conta é difícil, simula-se e conta-se.

#### 💼 Em processos seletivos

Monty Hall é uma pergunta clássica em entrevistas de ciência de dados e finanças quantitativas, e problemas de simulação com números aleatórios aparecem em vagas de engenharia de dados e jogos.

Perguntas que costumam aparecer:

- Explique por que trocar é melhor.
- Escreva uma simulação com 10.000 rodadas e compare as duas estratégias.

### Números aleatórios (rand e srand)

Computadores são determinísticos, então `rand()` não gera números realmente aleatórios: ela produz uma sequência **pseudoaleatória** calculada a partir de uma **semente**. Mesma semente, mesma sequência. Por isso os programas chamam `srand(time(NULL))` **uma vez** no início, usando o relógio como semente.

`rand()` devolve um inteiro de 0 a `RAND_MAX`; para um intervalo, usa-se o resto: `rand() % 6 + 1` simula um dado de 1 a 6. (Esse truque tem um pequeno viés quando `RAND_MAX + 1` não é múltiplo do intervalo, irrelevante em jogos simples.)

#### 🌍 Onde é usado na prática

- Jogos (dados, cartas embaralhadas, inimigos), simulações e testes com dados sorteados.
- Métodos de Monte Carlo: estimar probabilidades e áreas sorteando muitos pontos.
- Algoritmos aleatorizados, como o *Quicksort* com pivô sorteado.
- **Nunca** para senhas, *tokens* ou criptografia: para isso existem geradores criptograficamente seguros (`/dev/urandom`, `getrandom`).

#### 💼 Em processos seletivos

Aparece em perguntas como embaralhar um vetor de forma justa (algoritmo de Fisher-Yates), sortear com pesos e explicar por que `rand()` não serve para segurança.

Perguntas que costumam aparecer:

- Por que o programa sorteia sempre o mesmo número sem `srand`?
- Embaralhe um vetor de forma que todas as permutações sejam igualmente prováveis.
- Por que não usar `rand()` para gerar senhas?

#### 🐞 Erros comuns

- Chamar `srand(time(NULL))` dentro de um laço (no mesmo segundo, a semente se repete).
- Esquecer o `+ 1` e sortear de 0 a 5 em vez de 1 a 6.

## 🧠 Como funciona o código

```c
int main(void) {

    printf("Bem-vindo ao jogo Monty Hall!");
    printf("\n\nEscolha uma porta (1, 2 ou 3): ");
    int portaEscolhida;
    scanf("%d", &portaEscolhida);

    // Validar a entrada do usuário
    if (portaEscolhida < 1 || portaEscolhida > 3) {
        printf("\nEscolha inválida. O número da porta deve ser 1, 2 ou 3.");
    } else {
        // Definir a porta premiada

        // Inicializa a semente para a função rand() usando o tempo atual
        srand(time(NULL));

        // Gera um número aleatório entre 1 e 3
        int portaPremiada = rand() % 3 + 1;
        // printf("\nA porta premiada é: %d", portaPremiada); //comente essa linha para ficar divertido

        // Simulação da abertura de uma das outras portas vazias
        int portaVazia = -1;
        do {
            portaVazia = rand() % 3 + 1;
        } while (portaVazia == portaPremiada || portaVazia == portaEscolhida);
        printf("\nO apresentador abriu a porta %d, que está vazia.", portaVazia);

        // Oferecer a opção de trocar de porta ou não
        printf("\n\nVocê deseja trocar para a outra porta? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);

        // Verifica se a opção é 's' para decidir se deve trocar a porta
        int trocarPorta = (opcao == 's' || opcao == 'S');

        // Determinar a nova porta escolhida (caso o jogador opte por trocar)
        int portaEscolhidaOriginal = portaEscolhida;
        if (trocarPorta) {
            do {
                portaEscolhida = rand() % 3 + 1;
            } while (portaEscolhida == portaVazia
                    || portaEscolhida == portaEscolhidaOriginal);
            printf("\nVocê trocou para a porta %d.", portaEscolhida);
            //portaEscolhida agora é a porta nova que foi trocada
            //portaEscolhidaOriginal é a porta escolhida no início do jogo, antes da troca
        }

        // Determinar o resultado final
        if (portaEscolhida == portaPremiada) {
            printf("\nVocê ganhou! Parabéns!");
        } else {
            printf("\nVocê perdeu. A porta premiada era a %d.", portaPremiada);
        }

        // Resultado final
        printf("\n\nPorta premiada: %d", portaPremiada);
        printf("\nPorta vazia: %d", portaVazia);
        printf("\nPorta escolhida: %d", portaEscolhida);
        printf("\nPorta escolhida Originalmente: %d", portaEscolhidaOriginal);
    }

    return EXIT_SUCCESS;
}
```

O apresentador nunca abre a porta premiada nem a escolhida, por isso o `do-while` sorteia de novo até cair em uma porta vazia diferente da escolhida. A linha comentada `// printf("\nA porta premiada é: %d", portaPremiada);` revela o prêmio antes da hora, para testar.

Por que trocar é melhor? Na primeira escolha, a chance de acertar é 1/3. Os outros 2/3 ficam nas duas portas restantes; quando o apresentador elimina uma delas, os 2/3 ficam todos na porta que sobrou.

## 💻 Exemplo de execução

```text
Bem-vindo ao jogo Monty Hall!

Escolha uma porta (1, 2 ou 3): 2

O apresentador abriu a porta 3, que está vazia.

Você deseja trocar para a outra porta? (s/n): s

Você trocou para a porta 1.
Você perdeu. A porta premiada era a 2.

Porta premiada: 2
Porta vazia: 3
Porta escolhida: 1
Porta escolhida Originalmente: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_MontyHall` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_MontyHall`:

```bash
gcc src/Prj_MontyHall.c -o Prj_MontyHall
./Prj_MontyHall
```

No Windows, rode `Prj_MontyHall.exe` (ou `.\Prj_MontyHall.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_MontyHall
│
├── 📁 src
│   └── Prj_MontyHall.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 384: Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

## 🔗 Projetos relacionados

- [Prj_Loteria](../Prj_Loteria): Loteria
- [Prj_Rand](../Prj_Rand): Números aleatórios

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Monty Hall problem](https://en.wikipedia.org/wiki/Monty_Hall_problem)
- [cppreference: rand](https://en.cppreference.com/w/c/numeric/random/rand)
- [cppreference: srand](https://en.cppreference.com/w/c/numeric/random/srand)
- [Wikipedia: Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

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
