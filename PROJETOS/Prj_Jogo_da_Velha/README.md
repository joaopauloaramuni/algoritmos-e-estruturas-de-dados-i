# Projeto Prj_Jogo_da_Velha (C) ⭕

> **Jogo da velha**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Jogo da velha completo no console, com dois modos: **Multiplayer** (dois jogadores) e **Single Player** contra o computador, em três níveis:

| Nível | Estratégia do computador |
| --- | --- |
| EASY | Joga em uma casa vazia sorteada |
| MEDIUM | Completa ou bloqueia linhas, colunas e diagonais com duas peças iguais; se não houver, sorteia |
| HARD | Começa pelos cantos (jogada estratégica) e depois segue a lógica do MEDIUM |

É uma reedição do jogo da velha que fiz como aluno de ED1 na FUMEC, em 2011.

## 🎯 Conceitos trabalhados

- Matriz `char tabuleiro[3][3]` como estado do jogo
- Variáveis globais
- Funções para cada etapa (limpar, imprimir, jogar, verificar)
- Decisões do computador com `if/else if` e `rand`

## 📚 Entendendo o conceito

Este projeto trabalha **Jogos de tabuleiro em console: estado, regras e IA simples** e **Matrizes (vetores bidimensionais)**.

### Jogos de tabuleiro em console: estado, regras e IA simples

Um jogo como o jogo da velha ou a forca é um bom exercício de **modelagem**: o **estado** do jogo (o tabuleiro, as letras descobertas, as tentativas) fica em variáveis e matrizes, e o programa repete um ciclo **ler jogada → validar → atualizar o estado → verificar fim de jogo → trocar o turno**.

Uma "inteligência artificial" simples para o computador pode seguir regras em ordem de prioridade: ganhar se puder, bloquear se o adversário for ganhar, ocupar uma casa estratégica (centro, cantos) e, por fim, jogar ao acaso. A versão ótima do jogo da velha usa o algoritmo **minimax**, que explora recursivamente todas as jogadas possíveis; com ele o computador nunca perde.

#### 🌍 Onde é usado na prática

- A mesma estrutura de ciclo de jogo e de máquina de estados está em jogos comerciais, em simuladores e em sistemas com fluxo de telas.
- O minimax, com podas alfa-beta, foi a base dos programas de xadrez por décadas.

#### 💼 Em processos seletivos

Projetar um jogo da velha (ou um jogo de cartas) é uma pergunta comum de **design orientado a objetos** e de *live coding*, e verificar o vencedor em uma matriz é um exercício frequente. O minimax aparece em vagas de jogos e em maratonas.

Perguntas que costumam aparecer:

- Verifique se há vencedor em um tabuleiro de jogo da velha.
- Como verificar o vencedor em O(1) a cada jogada?
- Como o computador escolheria a jogada ótima? (minimax)

#### 🐞 Erros comuns

- Não validar se a posição está dentro do tabuleiro e livre.
- Verificar só linhas e colunas e esquecer as diagonais.

### Matrizes (vetores bidimensionais)

Uma **matriz** `int m[3][4];` é um vetor de linhas: 3 linhas, cada uma com 4 colunas. Na memória, as linhas ficam uma depois da outra (ordem por linhas, *row-major*), então `m[i][j]` está na posição `i * 4 + j` a partir do início.

Percorrer uma matriz pede dois laços aninhados: o de fora nas linhas, o de dentro nas colunas. Ao passar uma matriz para uma função, a primeira dimensão pode ficar vazia, mas as outras são obrigatórias (`int m[][4]`), porque o compilador precisa delas para calcular o endereço de `m[i][j]`.

#### 🌍 Onde é usado na prática

- Imagens (cada *pixel* em `[linha][coluna]`), planilhas, tabuleiros de jogos, mapas de jogos 2D.
- Álgebra linear: transformações em computação gráfica, redes neurais (multiplicação de matrizes é a operação central do aprendizado de máquina).
- Grafos representados por matriz de adjacência.

#### 💼 Em processos seletivos

Problemas de matriz aparecem bastante: girar uma imagem 90°, percorrer em espiral, zerar linhas e colunas, buscar em matriz ordenada e problemas de grade (ilhas, caminhos) que usam busca em largura ou em profundidade.

Perguntas que costumam aparecer:

- Transponha uma matriz.
- Gire uma matriz quadrada 90° no próprio lugar.
- Some a diagonal principal e a secundária.
- Percorra a matriz em espiral.

#### ⏱️ Complexidade

Percorrer uma matriz n × m custa O(n·m).

#### 🐞 Erros comuns

- Trocar a ordem dos índices (`m[j][i]`).
- Percorrer por colunas no laço de fora: o resultado é o mesmo, mas fica mais lento por causa do *cache*.

## 🧠 Como funciona o código

```c
//Verifica se deu empate
int verificaempate() {

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2]
            != ' ' && tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' '
            && tabuleiro[1][2] != ' ' && tabuleiro[2][0] != ' '
            && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

        printf("Deu Velha! Empate...");
        return 0;
    }

    return 1;
}
```

```c
//-------------------------------------------------------------------------
//Preenche o tabuleiro do jogo com espacos (tabuleiro[lin][col] = ' ')
void limpa(void) {
    int lin, col;
    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 3; col++) {
            tabuleiro[lin][col] = ' ';
        }
    }
}
```

O `main` repete o ciclo **jogada do jogador 1 → verifica vencedor → verifica empate → jogada do jogador 2 (ou do computador)** até alguém vencer ou o tabuleiro encher. As jogadas são digitadas como `linha coluna` (de `0 0` a `2 2`), conforme o quadro de POSICOES que aparece antes de cada jogada.

## 💻 Exemplo de execução

```text
**** JOGO DA VELHA ****

MENU
 1 - Single Player
 2 - Multiplayer

Opcao: 2

---------------
    GAME     
---------------
   |   |   
--- --- ---
   |   |   
--- --- ---
   |   |   

Simbolo x ou o: Simbolo incorreto, digite de novo...

Simbolo x ou o: x

---------------
    POSICOES     
---------------
0 0 | 0 1 | 0 2
  --- --- ---
1 0 | 1 1 | 1 2
  --- --- ---
2 0 | 2 1 | 2 2
---------------
Jogada: 0 0

---------------
    GAME     
---------------
 x |   |   
--- --- ---
   |   |   
--- --- ---
   |   |   

(quadro de posições)
Jogada: 1 1

---------------
    GAME     
---------------
 x |   |   
--- --- ---
   | o |   
--- --- ---
   |   |   

(quadro de posições)
Jogada: 0 1

---------------
    GAME     
---------------
 x | x |   
...
```

## ⚠️ Pontos de atenção

- O código usa `fflush(stdin)` antes dos `scanf`, o que funciona no Windows (MinGW) mas não é garantido no Linux e no macOS. Se o "Simbolo x ou o" for pedido duas vezes, troque `scanf("%c", &jogador1)` por `scanf(" %c", &jogador1)` (com espaço antes do `%c`).
- No modo MEDIUM/HARD, várias mensagens `Jogada: %d %d` mostram coordenadas que não batem com a casa realmente jogada (por exemplo, `printf("Jogada: %d %d", 2, a)` nas diagonais). O tabuleiro impresso logo depois está certo.
- Uma das condições da diagonal confere `tabuleiro[2][2] == ' '` em vez de `tabuleiro[0][0] == ' '`, então o computador não completa essa diagonal no canto `0 0`.
- A jogada não valida se `lin` e `col` estão entre 0 e 2: digitar `5 5` escreve fora da matriz.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Jogo_da_Velha` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Jogo_da_Velha`:

```bash
gcc src/Teste.c -o Prj_Jogo_da_Velha
./Prj_Jogo_da_Velha
```

No Windows, rode `Prj_Jogo_da_Velha.exe` (ou `.\Prj_Jogo_da_Velha.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**. O OnlineGDB roda em Linux: veja os **Pontos de atenção**.

## 📂 Estrutura do projeto

```text
📁 Prj_Jogo_da_Velha
│
├── 📁 src
│   └── Teste.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1275: Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)
- [LeetCode 794: Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/)
- [LeetCode 867: Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [LeetCode 1572: Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)
- [LeetCode 48: Rotate Image](https://leetcode.com/problems/rotate-image/)
- [LeetCode 54: Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [Beecrowd 1181: Linha na Matriz](https://judge.beecrowd.com/pt/problems/view/1181)

## 🔗 Projetos relacionados

- [Prj_Forca](../Prj_Forca): Jogo da forca
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [ed1_velha](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/ed1_velha)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe)
- [Wikipedia: Minimax](https://en.wikipedia.org/wiki/Minimax)
- [cppreference: arrays multidimensionais](https://en.cppreference.com/w/c/language/array)
- [Wikipedia: ordem por linhas e por colunas](https://en.wikipedia.org/wiki/Row-_and_column-major_order)

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
