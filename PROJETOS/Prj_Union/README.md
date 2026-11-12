# Projeto Prj_Union (C) 🔀

> **Union**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Uma `union` com um `int`, um `float` e uma string. Os três campos **dividem o mesmo espaço de memória**, então só o último valor gravado é válido.

## 🎯 Conceitos trabalhados

- `union` × `struct`
- Memória compartilhada entre campos
- Tamanho da union = tamanho do maior campo

## 📚 Entendendo o conceito

### Enum e union

Um **`enum`** cria constantes inteiras com nome: em `enum Dia { DOMINGO, SEGUNDA, ... };`, `DOMINGO` vale 0, `SEGUNDA` vale 1, e assim por diante. Serve para deixar o código legível (`case TERCA:` em vez de `case 2:`) e para restringir os valores possíveis de um campo.

Uma **`union`** parece uma struct, mas **todos os campos dividem o mesmo espaço de memória**: o tamanho da union é o do maior campo, e só o último campo gravado tem valor válido. Quando se guarda numa union **um** de vários tipos possíveis, costuma-se acompanhar a union de um `enum` que diz qual campo está em uso (a chamada *tagged union*).

#### 🌍 Onde é usado na prática

- `enum`: estados de um pedido, direções de um jogo, códigos de erro, opções de um menu.
- `union`: interpretadores e compiladores (um valor pode ser inteiro, real ou texto), mensagens de protocolos de rede e economia de memória em sistemas embarcados.
- O conceito reaparece em linguagens modernas: `enum` com dados em Rust e Swift e *sum types* em linguagens funcionais.

#### 💼 Em processos seletivos

Menos frequentes que structs, mas aparecem em vagas de C/C++ e embarcados, principalmente a diferença de memória entre struct e union.

Perguntas que costumam aparecer:

- Qual o `sizeof` de uma union com um `int`, um `double` e um `char[20]`?
- Qual a diferença entre struct e union?
- O que é uma *tagged union*?

#### 🐞 Erros comuns

- Ler um campo da union diferente do último gravado.
- Imprimir um `enum` com `%d` esperando o nome da constante (C não guarda os nomes; é preciso um vetor de strings).

## 🧠 Como funciona o código

```c
int main(void) {
    dado.i = 10; /* union sera do tipo inteiro */
    printf("Sou inteiro : %d\n", dado.i);
    dado.f = 34.5; /* union sera do tipo float */
    printf("Sou real : %f\n", dado.f);
    strcpy(dado.str, "Sou String"); /* union sera do tipo String */
    printf("Sou string : %s\n", dado.str);

    return 0;
}
```

Uma `struct` com esses campos ocuparia 28 bytes (4 + 4 + 20). A `union` ocupa só 20, o tamanho do maior campo. Depois do `strcpy`, ler `dado.i` daria um número sem sentido, formado pelos primeiros bytes da string.

## 💻 Exemplo de execução

```text
Sou inteiro : 10
Sou real : 34.500000
Sou string : Sou String
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Union` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Union`:

```bash
gcc src/Prj_Union.c -o Prj_Union
./Prj_Union
```

No Windows, rode `Prj_Union.exe` (ou `.\Prj_Union.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Union
│
├── 📁 src
│   └── Prj_Union.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Union_Struct](../Prj_Union_Struct): Union dentro de struct
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: enum](https://en.cppreference.com/w/c/language/enum)
- [cppreference: union](https://en.cppreference.com/w/c/language/union)

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
