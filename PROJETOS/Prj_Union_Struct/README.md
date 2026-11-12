# Projeto Prj_Union_Struct (C) 🧬

> **Union dentro de struct**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Uma `struct Pessoa` com nome, idade e uma `union DadosAdicionais` que guarda **ou** um inteiro, **ou** um float, **ou** um texto, conforme a pessoa.

## 🎯 Conceitos trabalhados

- Union como campo de struct
- Inicializadores designados (`.valorInteiro = 123`)

## 📚 Entendendo o conceito

Este projeto trabalha **Enum e union** e **Structs e typedef**.

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

### Structs e typedef

Uma **struct** agrupa dados de tipos diferentes que pertencem à mesma coisa: um aluno tem nome (`char[]`), matrícula (`int`) e nota (`float`). Os campos são acessados com `.` (`aluno.nota`) ou, a partir de um ponteiro, com `->` (`p->nota`, que é o mesmo que `(*p).nota`).

Structs podem ser copiadas inteiras com `=`, passadas para funções e devolvidas por elas, e podem conter outras structs (um cliente tem um endereço). O `typedef` dá um nome curto ao tipo (`typedef struct aluno Aluno;`), dispensando escrever `struct` toda vez. Uma struct que contém um ponteiro para o próprio tipo (`struct no *prox;`) é a base de listas e árvores.

#### 🌍 Onde é usado na prática

- Registros de sistemas: cliente, produto, pedido. É o equivalente em C a uma classe só com atributos, ou a uma linha de tabela de banco de dados.
- APIs do sistema operacional usam structs para tudo: `struct tm` (data e hora), `struct stat` (informações de arquivo), `struct sockaddr` (endereços de rede).
- Formatos binários (cabeçalhos de imagens BMP, pacotes de rede) são lidos direto em structs.

#### 💼 Em processos seletivos

Structs aparecem como a forma de modelar o problema: ao implementar uma lista, uma fila ou um cadastro, a primeira coisa avaliada é a modelagem dos dados. Em vagas de C, perguntam sobre `.` × `->`, cópia de struct e **alinhamento** (por que `sizeof` de uma struct às vezes é maior que a soma dos campos).

Perguntas que costumam aparecer:

- Qual a diferença entre `.` e `->`?
- Passar uma struct por valor ou por ponteiro? Quando cada um?
- Por que `sizeof(struct)` pode ser maior que a soma dos campos?

#### 🐞 Erros comuns

- Usar `.` com ponteiro ou `->` com variável.
- Esquecer que copiar uma struct com um ponteiro dentro copia o endereço, não os dados apontados (cópia rasa).
- Escrever o nome do tipo errado no `typedef` (erro de compilação "unknown type name").

## 🧠 Como funciona o código

```c
int main(void) {
    // Criando uma instância da struct Pessoa
    struct Pessoa pessoa1 = { "João", 25, { .valorInteiro = 123} };
    struct Pessoa pessoa2 = { "Maria", 30, { .valorFlutuante = 42.0f } };
    struct Pessoa pessoa3 = { "Carlos", 22, { .texto = "Texto Extra" } };

    // Exibindo informações das pessoas
    printf("Nome: %s, Idade: %d, Dados Extras: %d\n", pessoa1.nome,
            pessoa1.idade, pessoa1.dadosExtras.valorInteiro);
    printf("Nome: %s, Idade: %d, Dados Extras: %.2f\n", pessoa2.nome,
            pessoa2.idade, pessoa2.dadosExtras.valorFlutuante);
    printf("Nome: %s, Idade: %d, Dados Extras: %s\n", pessoa3.nome,
            pessoa3.idade, pessoa3.dadosExtras.texto);

    return 0;
}
```

O `{ .valorFlutuante = 42.0f }` escolhe qual campo da union inicializar. O programa precisa "saber" qual campo foi usado em cada pessoa: em projetos reais, isso costuma ficar em um `enum` ao lado da union (*tagged union*).

## 💻 Exemplo de execução

```text
Nome: João, Idade: 25, Dados Extras: 123
Nome: Maria, Idade: 30, Dados Extras: 42.00
Nome: Carlos, Idade: 22, Dados Extras: Texto Extra
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Union_Struct` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Union_Struct`:

```bash
gcc src/Prj_Union_Struct.c -o Prj_Union_Struct
./Prj_Union_Struct
```

No Windows, rode `Prj_Union_Struct.exe` (ou `.\Prj_Union_Struct.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Union_Struct
│
├── 📁 src
│   └── Prj_Union_Struct.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)

## 🔗 Projetos relacionados

- [Prj_Union](../Prj_Union): Union
- [Prj_Enum_Struct](../Prj_Enum_Struct): Enum dentro de struct

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: enum](https://en.cppreference.com/w/c/language/enum)
- [cppreference: union](https://en.cppreference.com/w/c/language/union)
- [cppreference: struct](https://en.cppreference.com/w/c/language/struct)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: operador -> (acesso a membro)](https://en.cppreference.com/w/c/language/operator_member_access)

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
