# Projeto Prj_Struct_Pessoa_Iterativo (C) 🧓

> **Pessoa mais velha (iterativo)**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Encontra a pessoa mais velha em um array de `Pessoa` (nome e idade) usando um laço `for`. Compare com a versão recursiva no [Prj_Struct_Pessoa_Recursivo](../Prj_Struct_Pessoa_Recursivo).

## 🎯 Conceitos trabalhados

- Array de structs inicializado com `{ }`
- Busca do máximo com laço
- Função que devolve struct

## 📚 Entendendo o conceito

Este projeto trabalha **Structs e typedef** e **Busca linear: maior, menor e contagem**.

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

### Busca linear: maior, menor e contagem

Encontrar o maior ou o menor valor de uma sequência é o exemplo mais simples de **busca linear**: olhar cada elemento uma vez, guardando o melhor visto até agora.

O detalhe que separa a solução certa da errada é o **valor inicial**. Começar o máximo em `0` falha se todos os números forem negativos; o correto é começar com o **primeiro elemento** (ou com `INT_MIN`/`INT_MAX` de `<limits.h>`).

#### 🌍 Onde é usado na prática

- Relatórios: maior venda do mês, menor temperatura do dia.
- Algoritmos de ordenação por seleção repetem a busca do menor elemento.
- Contar ocorrências (quantos pares, quantos acima da média) é a mesma ideia com um contador.

#### 💼 Em processos seletivos

É um aquecimento comum em entrevistas e aparece como subproblema de questões maiores (o segundo maior elemento, a maior soma de um subvetor). Espera-se a solução em uma única passada, O(n), e sem memória extra.

Perguntas que costumam aparecer:

- Encontre o segundo maior elemento em uma passada.
- Encontre o maior e o menor ao mesmo tempo com menos comparações.
- Qual o valor inicial correto para o máximo?

#### ⏱️ Complexidade

O(n) de tempo e O(1) de memória.

#### 🐞 Erros comuns

- Inicializar o máximo com 0.
- Esquecer o caso de sequência vazia.

## 🧠 Como funciona o código

```c
// Função iterativa para encontrar a pessoa mais velha
Pessoa encontraMaisVelho(Pessoa Pessoas[], int n) {
    Pessoa maisVelho = Pessoas[0];

    for (int i = 1; i < n; i++) {
        if (Pessoas[i].idade > maisVelho.idade) {
            maisVelho = Pessoas[i];
        }
    }

    return maisVelho;
}
```

Começa supondo que a primeira pessoa é a mais velha e compara com as outras. Quando acha alguém mais velho, guarda a struct inteira em `maisVelho`.

## 💻 Exemplo de execução

```text
Pessoa mais velha: Maria, 35 anos
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Iterativo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Iterativo`:

```bash
gcc src/Prj_Struct_Pessoa_Iterativo.c -o Prj_Struct_Pessoa_Iterativo
./Prj_Struct_Pessoa_Iterativo
```

No Windows, rode `Prj_Struct_Pessoa_Iterativo.exe` (ou `.\Prj_Struct_Pessoa_Iterativo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Iterativo
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Iterativo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)
- [Beecrowd 1013: O Maior](https://judge.beecrowd.com/pt/problems/view/1013)
- [Beecrowd 1080: Maior e Posição](https://judge.beecrowd.com/pt/problems/view/1080)
- [Beecrowd 1180: Menor e Posição](https://judge.beecrowd.com/pt/problems/view/1180)
- [LeetCode 414: Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Recursivo](../Prj_Struct_Pessoa_Recursivo): Pessoa mais velha (recursivo)
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: struct](https://en.cppreference.com/w/c/language/struct)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: operador -> (acesso a membro)](https://en.cppreference.com/w/c/language/operator_member_access)
- [cppreference: limites dos tipos inteiros](https://en.cppreference.com/w/c/types/limits)

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
