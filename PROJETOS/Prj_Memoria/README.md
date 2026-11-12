# Projeto Prj_Memoria (C) 🧠

> **Endereço de memória**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Imprime o **endereço de memória** onde a variável `minhaVariavel` foi guardada. É a ponte entre variáveis e ponteiros: toda variável mora em algum endereço da memória RAM.

## 🎯 Conceitos trabalhados

- Operador `&` (endereço de)
- Especificador `%p` para endereços
- Memória de pilha (*stack*)

## 📚 Entendendo o conceito

Este projeto trabalha **Ponteiros e passagem por referência** e **Memória: pilha (stack), heap e alocação dinâmica**.

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
    int minhaVariavel = 13;
    printf("O endereço de memória de 'minhaVariavel' é: %p\n", &minhaVariavel);
    return 0;
}
```

O `&minhaVariavel` devolve o endereço da variável e o `%p` o formata em hexadecimal. O valor muda a cada execução porque o sistema operacional sorteia a posição da pilha (ASLR, *Address Space Layout Randomization*), uma proteção de segurança.

## 💻 Exemplo de execução

```text
O endereço de memória de 'minhaVariavel' é: 0x7ffc2dbeb3d4
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Memoria` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Memoria`:

```bash
gcc src/Prj_Memoria.c -o Prj_Memoria
./Prj_Memoria
```

No Windows, rode `Prj_Memoria.exe` (ou `.\Prj_Memoria.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Memoria
│
├── 📁 src
│   └── Prj_Memoria.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 344: Reverse String (dois ponteiros)](https://leetcode.com/problems/reverse-string/)
- [LeetCode 283: Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [LeetCode 707: Design Linked List (alocar e liberar nós)](https://leetcode.com/problems/design-linked-list/)

## 🔗 Projetos relacionados

- [Prj_Heap](../Prj_Heap): Alocação dinâmica (heap)
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência
- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera

## 🕰️ O mesmo assunto em 2011

Antes de ser professor, escrevi códigos sobre este assunto como aluno de Ciência da Computação na FUMEC (2010–2011), nas disciplinas de Estruturas de Dados I e II do Prof. Rafael Nunes. Vale comparar as duas versões:

- [Ponteiros](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS/Ponteiros)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: ponteiros](https://en.cppreference.com/w/c/language/pointer)
- [Paulo Feofiloff (IME-USP): endereços e ponteiros](https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html)
- [Python Tutor: visualizar ponteiros em C passo a passo](https://pythontutor.com/c.html)
- [cppreference: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [cppreference: calloc](https://en.cppreference.com/w/c/memory/calloc)
- [cppreference: free](https://en.cppreference.com/w/c/memory/free)
- [Paulo Feofiloff (IME-USP): alocação dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Valgrind: guia rápido](https://valgrind.org/docs/manual/quick-start.html)

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
