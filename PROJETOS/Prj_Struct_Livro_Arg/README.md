# Projeto Prj_Struct_Livro_Arg (C) 📗

> **Struct Livro como argumento**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mesmo exemplo do [Prj_Struct_Livro](../Prj_Struct_Livro), agora com a função `printLivro`, que recebe um livro **por valor** e imprime os campos.

## 🎯 Conceitos trabalhados

- Struct como parâmetro de função (por valor)
- Protótipo de função com struct
- Reaproveitamento de código

## 📚 Entendendo o conceito

Este projeto trabalha **Structs e typedef** e **Funções e procedimentos**.

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

## 🧠 Como funciona o código

```c
void printLivro(struct Livro livro) {
    printf("Livro titulo : %s\n", livro.titulo);
    printf("Livro autor : %s\n", livro.autor);
    printf("Livro assunto : %s\n", livro.assunto);
    printf("Livro id_livro : %d\n", livro.id_livro);
}
```

Passar a struct por valor copia **todos** os campos para a função: são 204 bytes por chamada (`50 + 50 + 100 + 4`). Para structs grandes, o [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro) passa só o endereço.

## 💻 Exemplo de execução

```text
Livro titulo : Título genérico
Livro autor : Autor
Livro assunto : Um livro genérico
Livro id_livro : 123
Livro titulo : Outro título genérico
Livro autor : Autor 2
Livro assunto : Outro livro genérico
Livro id_livro : 456
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Livro_Arg` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Livro_Arg`:

```bash
gcc src/Prj_Struct_Livro_Arg.c -o Prj_Struct_Livro_Arg
./Prj_Struct_Livro_Arg
```

No Windows, rode `Prj_Struct_Livro_Arg.exe` (ou `.\Prj_Struct_Livro_Arg.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Livro_Arg
│
├── 📁 src
│   └── Prj_Struct_Livro_Arg.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)
- [Beecrowd 1009: Salário com Bônus](https://judge.beecrowd.com/pt/problems/view/1009)

## 🔗 Projetos relacionados

- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro
- [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro): Struct Livro por ponteiro

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: struct](https://en.cppreference.com/w/c/language/struct)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: operador -> (acesso a membro)](https://en.cppreference.com/w/c/language/operator_member_access)
- [cppreference: declaração de funções](https://en.cppreference.com/w/c/language/function_declaration)
- [cppreference: definição de funções](https://en.cppreference.com/w/c/language/function_definition)
- [cppreference: return](https://en.cppreference.com/w/c/language/return)

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
