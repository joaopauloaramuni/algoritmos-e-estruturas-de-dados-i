# Projeto Prj_Heap (C) 🗄️

> **Alocação dinâmica (heap)**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Exemplo curto de **alocação dinâmica**: reserva dois blocos de memória no *heap* com `malloc` e libera um deles com `free`. O programa não imprime nada; a ideia é acompanhar a memória no depurador do Eclipse ou desenhar no quadro onde cada variável fica.

## 🎯 Conceitos trabalhados

- Diferença entre *stack* (pilha) e *heap*
- `malloc` e `free` de `<stdlib.h>`
- Ponteiro para `int`
- Vazamento de memória (*memory leak*)

## 📚 Entendendo o conceito

### Memória: pilha (stack), heap e alocação dinâmica

Um programa em C usa três regiões principais de memória:

| Região | O que guarda | Quem libera |
| --- | --- | --- |
| Estática | Variáveis globais e `static` | O sistema, quando o programa termina |
| Pilha (*stack*) | Variáveis locais e parâmetros de cada chamada de função | Automaticamente, no `return` |
| *Heap* | Blocos pedidos com `malloc`, `calloc` e `realloc` | O programador, com `free` |

A alocação dinâmica serve quando o tamanho só é conhecido durante a execução ("quantos alunos?") ou quando os dados precisam sobreviver ao fim da função que os criou. Cada `malloc` deve ter exatamente um `free`; memória que nunca é liberada é um **vazamento** (*memory leak*).

#### 🌍 Onde é usado na prática

- Estruturas que crescem: listas, árvores, vetores dinâmicos (como o `ArrayList` do Java e o `vector` do C++, que são implementados com realocação).
- Servidores que rodam por meses: um vazamento pequeno por requisição acaba derrubando a máquina.
- Ferramentas como Valgrind e AddressSanitizer (`gcc -fsanitize=address`) acham vazamentos e acessos a memória liberada.

#### 💼 Em processos seletivos

Perguntas sobre *stack* × *heap* são frequentes em vagas de C/C++, sistemas e jogos, e aparecem em entrevistas de Java/C#/Python para explicar *garbage collection*. *Stack overflow* (recursão profunda demais) e vazamento de memória são temas recorrentes.

Perguntas que costumam aparecer:

- Qual a diferença entre *stack* e *heap*?
- O que é um vazamento de memória e como detectar?
- Qual a diferença entre `malloc` e `calloc`?
- O que acontece ao usar um ponteiro depois do `free` (*use-after-free*)?

#### 🐞 Erros comuns

- Não verificar se `malloc` devolveu `NULL`.
- Esquecer o `free`, ou chamar `free` duas vezes no mesmo bloco.
- Ler um campo do nó depois de liberá-lo: `free(p); p = p->prox;` lê memória liberada. O certo é guardar `p->prox` antes do `free`.
- Calcular o tamanho errado: `malloc(n)` em vez de `malloc(n * sizeof(int))`.

## 🧠 Como funciona o código

```c
int main(void) {

    int x = 2;
    int *y = malloc(100);
    int *z = malloc(400);
    free(z);

    return 0;
}
```

| Variável | Onde fica | Tamanho |
| --- | --- | --- |
| `x` | Pilha (*stack*) | `sizeof(int)`, normalmente 4 bytes |
| `y` | O ponteiro fica na pilha; os 100 bytes ficam no *heap* | 100 bytes |
| `z` | O ponteiro fica na pilha; os 400 bytes ficam no *heap* | 400 bytes (liberados com `free`) |

O bloco apontado por `y` **nunca é liberado**: é um vazamento de memória proposital, para discutir em aula. Para conferir, rode com o Valgrind: `valgrind --leak-check=full ./Prj_Heap` mostra `definitely lost: 100 bytes in 1 blocks`.

## 💻 Exemplo de execução

```text
(o programa não imprime nada)
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Heap` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Heap`:

```bash
gcc src/Prj_Heap.c -o Prj_Heap
./Prj_Heap
```

No Windows, rode `Prj_Heap.exe` (ou `.\Prj_Heap.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Heap
│
├── 📁 src
│   └── Prj_Heap.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 707: Design Linked List (alocar e liberar nós)](https://leetcode.com/problems/design-linked-list/)

## 🔗 Projetos relacionados

- [Prj_Memoria](../Prj_Memoria): Endereço de memória
- [Prj_IntercalarVetor](../Prj_IntercalarVetor): Intercalar vetores com malloc
- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [exerstruct2](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/exerstruct2)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [cppreference: calloc](https://en.cppreference.com/w/c/memory/calloc)
- [cppreference: free](https://en.cppreference.com/w/c/memory/free)
- [Paulo Feofiloff (IME-USP): alocação dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Valgrind: guia rápido](https://valgrind.org/docs/manual/quick-start.html)

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
