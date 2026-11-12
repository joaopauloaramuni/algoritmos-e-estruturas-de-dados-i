# 📁 PROJETOS (2024)

Projetos em C (e alguns em C++) da disciplina **Algoritmos e Estruturas de Dados I**, do curso de **Engenharia de Software da PUC Minas**, no 1º semestre de 2024, com o Prof. Dr. João Paulo Aramuni.

São **87 projetos** do Eclipse IDE for C/C++ Developers. Cada pasta tem um `README.md` com a explicação do código e do conceito (o que é, onde é usado, como aparece em processos seletivos, complexidade e erros comuns), uma execução real, instruções para rodar no Eclipse e no terminal, exercícios para praticar e links de documentação.

Os projetos estão agrupados na ordem em que os assuntos aparecem nas aulas.

🕰️ Os códigos que escrevi em 2010–2011, como aluno, estão no repositório [c](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS).

## Fundamentos

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 👋 [Prj_HelloWorld](Prj_HelloWorld) | O primeiro programa da disciplina: imprime `!!!Hello World!!!` no console. | Estrutura de um programa em C e compilação |
| ⌨️ [Prj_LeituraDados](Prj_LeituraDados) | Lê um número inteiro digitado pelo usuário e o mostra de volta. | Entrada e saída (printf, scanf e o buffer do teclado) |
| 🎲 [Prj_Rand](Prj_Rand) | Gera e mostra um número aleatório entre 0 e 100 usando `rand()`, com a semente iniciada pelo relógio (`srand(time(NULL))`). | Números aleatórios (rand e srand) |
| ➡️ [Prj_Sequencial](Prj_Sequencial) | Lê dois inteiros, soma e mostra o resultado. | Entrada e saída (printf, scanf e o buffer do teclado), Operadores aritméticos, divisão inteira e resto |
| 📦 [Prj_Variaveis](Prj_Variaveis) | Mostra as três formas de guardar um valor que aparecem logo no início da disciplina: uma **variável comum** (`int idade`), uma **variável constante** (`const int MAX_NUM`) e uma **constante de pré-processador** (`#define PI`). | Variáveis, tipos e constantes |

## Condicionais

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| ✅ [Prj_CondicionalComposta](Prj_CondicionalComposta) | Lê três notas, soma e informa se o aluno foi **Aprovado** (soma maior ou igual a 60) ou **Reprovado**. | Estruturas condicionais (if, else, else if) |
| 🔢 [Prj_CondicionalMultipla](Prj_CondicionalMultipla) | Lê um número de 1 a 5 e responde qual foi escolhido. | switch, case e o operador ternário, Estruturas condicionais (if, else, else if) |
| 🔀 [Prj_CondicionalSimples](Prj_CondicionalSimples) | Soma dois números e só mostra o resultado **se** a soma for maior que 60. | Estruturas condicionais (if, else, else if) |
| ⚖️ [Prj_IMC](Prj_IMC) | Calcula o **Índice de Massa Corporal** (IMC = peso ÷ altura²) e classifica o resultado em abaixo do peso, normal, acima do peso ou obeso, com uma cadeia de `if / else if`. | Estruturas condicionais (if, else, else if) |
| ❓ [Prj_Ternario](Prj_Ternario) | Escolhe entre dois valores com o **operador ternário** `condição ? valor_se_verdadeiro : valor_se_falso`, a forma compacta do `if/else`. | switch, case e o operador ternário |

## Repetição

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🔂 [Prj_DoWhile](Prj_DoWhile) | Lê e soma dois números três vezes usando `do-while`, que executa o bloco **pelo menos uma vez** antes de testar a condição. | Laços de repetição (while, do-while e for) |
| ⚖️ [Prj_DoWhile_Exer1](Prj_DoWhile_Exer1) | Mesmo exercício do Prj_While_Exer1, agora com `do-while`: lê números até o `0` e conta pares e ímpares. | Laços de repetição (while, do-while e for), Operadores aritméticos, divisão inteira e resto |
| 🧮 [Prj_DoWhile_Exer2](Prj_DoWhile_Exer2) | Versão com `do-while` do Prj_While_Exer2: conta os números digitados até o `-1`. | Laços de repetição (while, do-while e for) |
| 📋 [Prj_DoWhile_Menu](Prj_DoWhile_Menu) | Monta um **menu de opções** que se repete até o usuário escolher **Sair**. | Laços de repetição (while, do-while e for), switch, case e o operador ternário |
| 🔄 [Prj_For](Prj_For) | Lê e soma dois números três vezes com o laço `for`, que junta inicialização, condição e incremento na mesma linha. | Laços de repetição (while, do-while e for) |
| 📏 [Prj_Maior_Menor](Prj_Maior_Menor) | Lê 10 números e mostra o **maior** e o **menor** deles, sem guardar todos em um vetor. | Busca linear: maior, menor e contagem, Laços de repetição (while, do-while e for) |
| 🔁 [Prj_While](Prj_While) | Repete três vezes a leitura e a soma de dois números usando `while` e uma variável contadora. | Laços de repetição (while, do-while e for) |
| ⚖️ [Prj_While_Exer1](Prj_While_Exer1) | Lê números até o usuário digitar `0` e, no final, mostra quantos foram **pares** e quantos foram **ímpares**. | Laços de repetição (while, do-while e for), Operadores aritméticos, divisão inteira e resto |
| 🧮 [Prj_While_Exer2](Prj_While_Exer2) | Conta quantos números o usuário digitou até informar `-1`, o valor de saída (sentinela), que não entra na contagem. | Laços de repetição (while, do-while e for) |
| ♾️ [Prj_WhileInfinito](Prj_WhileInfinito) | Um `while (1)` que imprime a mesma frase para sempre. | Laços de repetição (while, do-while e for) |

## Funções

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🧩 [Prj_Funcao](Prj_Funcao) | Cria a função `calcularQuadrado`, que recebe um número e devolve o quadrado dele. | Funções e procedimentos |
| ➕ [Prj_Soma](Prj_Soma) | Função simples `soma(a, b)` que devolve a soma de dois inteiros, chamada pelo `main` com `x = 2` e `y = 3`. | Funções e procedimentos |

## Ponteiros e memória

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🔗 [Prj_ByVal_ByRef](Prj_ByVal_ByRef) | Compara duas funções que tentam somar 1 a uma variável: uma recebe uma **cópia** do valor (por valor) e não altera o original; a outra recebe o **endereço** (por referência) e altera. | Ponteiros e passagem por referência, Funções e procedimentos |
| 🧮 [Prj_Calculadora_Ponteiros](Prj_Calculadora_Ponteiros) | Calculadora de quatro operações em que cada operação é um **procedimento** (`void`) que devolve o resultado por um ponteiro (`int *resultado`), em vez de usar `return`. | Ponteiros e passagem por referência, Funções e procedimentos |
| 🔢 [Prj_ContarDigitos_Ponteiros](Prj_ContarDigitos_Ponteiros) | Conta quantos dígitos tem um número inteiro (`12345` tem 5). | Ponteiros e passagem por referência, Operadores aritméticos, divisão inteira e resto |
| 🔁 [Prj_Funcoes_Ponteiros](Prj_Funcoes_Ponteiros) | Duas funções clássicas com ponteiros: `troca`, que inverte os valores de duas variáveis do `main`, e `modifica`, que zera uma variável que começa valendo `1`. | Ponteiros e passagem por referência |
| 🗄️ [Prj_Heap](Prj_Heap) | Exemplo curto de **alocação dinâmica**: reserva dois blocos de memória no *heap* com `malloc` e libera um deles com `free`. | Memória: pilha (stack), heap e alocação dinâmica |
| 🧵 [Prj_IntercalarVetor](Prj_IntercalarVetor) | Junta dois vetores alternando os elementos (`1 3 5` + `2 4 6` → `1 2 3 4 5 6`) em um terceiro vetor criado com `malloc`. | Memória: pilha (stack), heap e alocação dinâmica, Vetores (arrays) |
| 🧠 [Prj_Memoria](Prj_Memoria) | Imprime o **endereço de memória** onde a variável `minhaVariavel` foi guardada. | Ponteiros e passagem por referência, Memória: pilha (stack), heap e alocação dinâmica |

## Arrays e matrizes

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 📚 [Prj_Array_Ex1](Prj_Array_Ex1) | Declara e inicializa um **array de inteiros** e um **array de strings** (os três Atléticos) e percorre os dois com `for` para imprimir os elementos. | Vetores (arrays) |
| 🔤 [Prj_Array_Ex2](Prj_Array_Ex2) | Lê três nomes, mostra os nomes na **ordem inversa** e depois cada nome com o seu comprimento, calculado por `strlen`. | Vetores (arrays), Strings em C |
| ➗ [Prj_Array_Exer1](Prj_Array_Exer1) | Lê 5 inteiros em um array, calcula a **soma** durante a leitura e mostra a **média** com duas casas decimais. | Vetores (arrays), Operadores aritméticos, divisão inteira e resto |
| 🔲 [Prj_Array_Exer2](Prj_Array_Exer2) | Soma todos os elementos de uma matriz 3×3 já inicializada (`1` a `9`), percorrendo linhas e colunas com dois `for` aninhados. | Matrizes (vetores bidimensionais) |
| 🧊 [Prj_Array_Exer3](Prj_Array_Exer3) | Calcula a média dos 8 elementos de uma **matriz tridimensional** 2×2×2 usando três laços aninhados e um contador. | Matrizes (vetores bidimensionais) |
| ▦ [Prj_Matriz](Prj_Matriz) | Lê uma matriz 3×3 elemento por elemento e a mostra organizada em linhas e colunas. | Matrizes (vetores bidimensionais) |

## Strings

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🔄 [Prj_Palindromo](Prj_Palindromo) | Verifica se uma palavra é um **palíndromo** (lida igual de trás para frente, como ARARA, OVO e OTTO) comparando as letras das pontas para o meio com dois índices. | Palíndromos e a técnica de dois ponteiros, Strings em C |
| 📝 [Prj_StrCpy](Prj_StrCpy) | Mostra as duas formas de colocar texto em um array de `char`: na **declaração** (`char string1[] = "Hello"`) e depois, com `strcpy`. | Strings em C |
| 📐 [Prj_StrLen](Prj_StrLen) | Calcula o comprimento da string `"Exemplo"` com `strlen` e imprime o resultado com `%zu`. | Strings em C |

## Structs, enums e unions

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 📅 [Prj_Enum](Prj_Enum) | Cria o tipo enumerado `enum DiaSemana` (DOMINGO a SABADO) e usa um `switch` para escrever o dia por extenso. | Enum e union, switch, case e o operador ternário |
| 🗓️ [Prj_Enum_Struct](Prj_Enum_Struct) | Uma `struct Compromisso` com descrição, dia (do tipo `enum DiaSemana`) e hora. | Enum e union, Structs e typedef |
| 📘 [Prj_Struct_Livro](Prj_Struct_Livro) | Define uma `struct Livro` com título, autor, assunto e id, preenche dois livros e imprime os campos de cada um. | Structs e typedef, Strings em C |
| 📗 [Prj_Struct_Livro_Arg](Prj_Struct_Livro_Arg) | Mesmo exemplo do Prj_Struct_Livro, agora com a função `printLivro`, que recebe um livro **por valor** e imprime os campos. | Structs e typedef, Funções e procedimentos |
| 📙 [Prj_Struct_Livro_Ponteiro](Prj_Struct_Livro_Ponteiro) | Terceira versão do exemplo do livro: `printLivro` recebe um **ponteiro** para a struct e acessa os campos com `->`. | Structs e typedef, Ponteiros e passagem por referência |
| 🧍 [Prj_Struct_Pessoa_Arg](Prj_Struct_Pessoa_Arg) | Cria o tipo `Pessoa` com `typedef struct`, monta um vetor de 10 pessoas (`Povo`) e mostra que uma struct inteira pode ser **copiada com uma única atribuição** (`P2 = Povo[4];`). | Structs e typedef |
| 🧓 [Prj_Struct_Pessoa_Iterativo](Prj_Struct_Pessoa_Iterativo) | Encontra a pessoa mais velha em um array de `Pessoa` (nome e idade) usando um laço `for`. | Structs e typedef, Busca linear: maior, menor e contagem |
| 👉 [Prj_Struct_Pessoa_Ponteiro](Prj_Struct_Pessoa_Ponteiro) | A função `SetPessoa` recebe um **ponteiro** para `Pessoa` e preenche os campos da struct original, mostrando as duas formas de acesso: `(*P).Idade` e `P->Peso`. | Structs e typedef, Ponteiros e passagem por referência |
| ↩️ [Prj_Struct_Pessoa_Return](Prj_Struct_Pessoa_Return) | Faz o mesmo que o Prj_Struct_Pessoa_Ponteiro, mas a função `SetPessoa` **devolve** uma struct preenchida em vez de receber um ponteiro. | Structs e typedef, Funções e procedimentos |
| 🏷️ [Prj_Typedef](Prj_Typedef) | Cria um **apelido** (`MeuInteiro`) para o tipo `int` com `typedef` e o usa para declarar uma variável. | Variáveis, tipos e constantes |
| 🔀 [Prj_Union](Prj_Union) | Uma `union` com um `int`, um `float` e uma string. | Enum e union |
| 🧬 [Prj_Union_Struct](Prj_Union_Struct) | Uma `struct Pessoa` com nome, idade e uma `union DadosAdicionais` que guarda **ou** um inteiro, **ou** um float, **ou** um texto, conforme a pessoa. | Enum e union, Structs e typedef |

## Arquivos

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 📄 [Prj_File](Prj_File) | Grava `Hello, World` no arquivo `exemplo.txt` e depois lê o arquivo linha por linha, mostrando o conteúdo. | Arquivos (texto e binário) |
| 💾 [Prj_File_Struct](Prj_File_Struct) | Grava uma struct inteira em um **arquivo binário** (`exemplo_struct.bin`) com `fwrite` e lê de volta com `fread`. | Arquivos (texto e binário), Structs e typedef |
| 🗂️ [Prj_Pali+File](Prj_Pali%2BFile) | Junta dois assuntos: verifica palavras com a função recursiva de palíndromo e grava o resultado de cada uma em `exemplo.txt`. | Arquivos (texto e binário), Palíndromos e a técnica de dois ponteiros |

## Recursão

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🧙 [Prj_Aramuni_Recursivo](Prj_Aramuni_Recursivo) | Um menu com **12 funções recursivas escritas em uma única linha cada**, usando operador ternário e operador vírgula: palíndromo, tamanho, cópia, concatenação, inversão e limpeza de string, contagem de letra, fatorial, Fibonacci, MDC, potência e Torre de Hanói. | Recursividade, Torre de Hanói, MDC e o algoritmo de Euclides |
| 🔍 [Prj_ContarElementoArray](Prj_ContarElementoArray) | Conta quantas vezes um elemento aparece em um array usando recursão. | Recursividade, Vetores (arrays) |
| ❗ [Prj_Fatorial_Recursivo](Prj_Fatorial_Recursivo) | Calcula o fatorial de 5 (`5! = 120`) de **três** formas: recursiva tradicional, recursiva em uma linha com operador ternário e iterativa com `for`. | Recursividade |
| 🐚 [Prj_Fibonacci_Recursivo](Prj_Fibonacci_Recursivo) | Calcula o n-ésimo termo da **sequência de Fibonacci** (0, 1, 1, 2, 3, 5, 8, 13...) de três formas: recursiva, recursiva em uma linha e com laço. | Recursividade |
| ✖️ [Prj_MultiplicaMatrizes_Recursivo](Prj_MultiplicaMatrizes_Recursivo) | Multiplica duas matrizes de qualquer tamanho alocadas dinamicamente, trocando os três `for` aninhados da multiplicação por **uma função recursiva** que controla os índices `i`, `j` e `k`. | Multiplicação de matrizes, Recursividade, Memória: pilha (stack), heap e alocação dinâmica |
| ✖️ [Prj_MultiplicaMatrizes_Recursivo_v2](Prj_MultiplicaMatrizes_Recursivo_v2) | Segunda versão do Prj_MultiplicaMatrizes_Recursivo: em vez de três índices, a função recursiva recebe **uma única posição** (`pos`) e calcula `i`, `j` e `k` a partir dela com divisão e resto. | Multiplicação de matrizes, Recursividade |
| 🔁 [Prj_Palindromo_Recursivo](Prj_Palindromo_Recursivo) | Verifica se uma palavra é palíndromo com recursão, em duas versões: uma de uma linha só (com ternário e `&&`) e outra passo a passo, com comentários que rastreiam cada chamada para ARARA. | Recursividade, Palíndromos e a técnica de dois ponteiros |
| 🚀 [Prj_Potencia_Recursiva](Prj_Potencia_Recursiva) | Calcula `base^expoente` de forma recursiva. | Recursividade |
| ↔️ [Prj_ReverterArray_Recursivo](Prj_ReverterArray_Recursivo) | Inverte a ordem dos elementos de um array (`1 2 3 4 5` → `5 4 3 2 1`) trocando as pontas e chamando a função para o pedaço do meio. | Recursividade, Vetores (arrays) |
| 🔢 [Prj_Soma_Recursiva](Prj_Soma_Recursiva) | Soma os dígitos de um número recursivamente: `1 + 2 + 3 + 4 + 5 = 15` para `12345`. | Recursividade, Operadores aritméticos, divisão inteira e resto |
| ➕ [Prj_Soma_Recursiva_Array](Prj_Soma_Recursiva_Array) | Soma os elementos de um array com recursão: a soma de `n` elementos é o último elemento mais a soma dos `n - 1` primeiros. | Recursividade, Vetores (arrays) |
| 👴 [Prj_Struct_Pessoa_Recursivo](Prj_Struct_Pessoa_Recursivo) | Encontra a pessoa mais velha em um array de `struct Pessoa` usando recursão. | Recursividade, Structs e typedef |
| 📈 [Prj_VerificarArrayOrdenado](Prj_VerificarArrayOrdenado) | Verifica, com recursão, se um array está em **ordem crescente**. | Recursividade, Vetores (arrays) |
| 🎯 [Prj_VerificarElementoPresenteArray](Prj_VerificarElementoPresenteArray) | Busca, com recursão, se um valor está presente no array, olhando do fim para o começo. | Recursividade, Vetores (arrays) |
| ✌️ [Prj_VerificarParesArray](Prj_VerificarParesArray) | Verifica, com recursão, se **todos** os elementos de um array são pares. | Recursividade, Vetores (arrays) |

## Jogos e desafios

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| ⏰ [Prj_ASCII_Clock](Prj_ASCII_Clock) | Um relógio digital no terminal: mostra a hora atual (HHMMSS) com dígitos desenhados em ASCII, em verde, e atualiza a cada segundo. | Terminal: caracteres especiais, códigos ANSI e espera, Strings em C |
| 🎲 [Prj_Dados](Prj_Dados) | Dois jogadores rolam dois dados cada (pressionando *Enter*) e vence quem tiver a maior soma. | Números aleatórios (rand e srand) |
| 🪢 [Prj_Forca](Prj_Forca) | Jogo da forca no console: o programa sorteia uma de 10 palavras, mostra os espaços com `_` e o jogador tem **6 tentativas** de errar. | Jogos de tabuleiro em console: estado, regras e IA simples, Strings em C |
| ⭕ [Prj_Jogo_da_Velha](Prj_Jogo_da_Velha) | Jogo da velha completo no console, com dois modos: **Multiplayer** (dois jogadores) e **Single Player** contra o computador, em três níveis: | Jogos de tabuleiro em console: estado, regras e IA simples, Matrizes (vetores bidimensionais) |
| 🍀 [Prj_Loteria](Prj_Loteria) | O programa sorteia um número de 0 a 100 e o jogador tenta acertar. | Números aleatórios (rand e srand) |
| 🚪 [Prj_MontyHall](Prj_MontyHall) | Simula o famoso **problema de Monty Hall**: o jogador escolhe uma de três portas, o apresentador abre uma porta vazia e pergunta se o jogador quer trocar. | Probabilidade e o problema de Monty Hall, Números aleatórios (rand e srand) |
| 🔬 [Prj_Smith](Prj_Smith) | Verifica se um número é um **número de Smith**: um número composto em que a soma dos dígitos é igual à soma dos dígitos dos seus fatores primos. | Números primos, dígitos e números de Smith |

## Tarefas e provas

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 📝 [Prj_Prova_AV2](Prj_Prova_AV2) | Resolução das questões da **prova AV2**. | Vetores (arrays), Recursividade |
| 🧾 [Prj_Tarefa_1](Prj_Tarefa_1) | Resolução da **Tarefa 1**. | Funções e procedimentos, Operadores aritméticos, divisão inteira e resto |
| 🛒 [Prj_Tarefa_2](Prj_Tarefa_2) | Resolução da **Tarefa 2**, com uma função por exercício, chamadas em sequência pelo `main`: | Laços de repetição (while, do-while e for), Funções e procedimentos |
| 🗳️ [Prj_Tarefa_3_1](Prj_Tarefa_3_1) | Resolução do exercício 1 da **Tarefa 3**: um menu registra votos para o Candidato A ou B, apura o resultado (vencedor ou empate) e sai na opção 4. | switch, case e o operador ternário, Laços de repetição (while, do-while e for) |
| 🚭 [Prj_Tarefa_3_2](Prj_Tarefa_3_2) | Resolução do exercício 2 da **Tarefa 3**: calcula quantos cigarros uma pessoa fumou ao longo da vida e quanto gastou, considerando 20 cigarros por maço. | Funções e procedimentos, Operadores aritméticos, divisão inteira e resto |
| 🏀 [Prj_Tarefa_3_3](Prj_Tarefa_3_3) | Resolução do exercício 3 da **Tarefa 3**: com idade, altura (em cm) e sexo, informa se a pessoa está apta para o time juvenil feminino ou masculino de basquete. | Estruturas condicionais (if, else, else if) |
| 📊 [Prj_Tarefa_4](Prj_Tarefa_4) | Resolução da **Tarefa 4**, uma função por exercício: | Vetores (arrays), Matrizes (vetores bidimensionais) |
| 🎄 [Prj_Triangulo](Prj_Triangulo) | Resolução do **Exercício de Revisão – Árvore de Natal**: desenha padrões de asteriscos no console a partir do número de linhas informado. | Laços de repetição (while, do-while e for) |

## C++ (bônus)

| Projeto | O que faz | Conceito |
| --- | --- | --- |
| 🐶 [Prj_ClasseAnimal_Cpp](Prj_ClasseAnimal_Cpp) | Mostra **polimorfismo**: dois ponteiros do tipo `Animal*`, um apontando para um `Animal` e outro para um `Cachorro`. | Orientação a objetos em C++: classes, herança e polimorfismo |
| 🚗 [Prj_ClasseCarro_Cpp](Prj_ClasseCarro_Cpp) | Primeiro contato com **orientação a objetos em C++**: a classe `Carro` com atributos (marca, modelo, ano), dois construtores e o método `exibirInformacoes`. | Orientação a objetos em C++: classes, herança e polimorfismo |
| 🚙 [Prj_ClasseVeiculo_Cpp](Prj_ClasseVeiculo_Cpp) | Mostra **herança** em C++: `Carro` herda de `Veiculo` e reaproveita o construtor e o método `exibirInformacoes` da classe base. | Orientação a objetos em C++: classes, herança e polimorfismo |
| 🚨 [Prj_Excecoes_Cpp](Prj_Excecoes_Cpp) | Mostra `try`, `throw` e `catch` em C++: antes de dividir por zero, o programa lança uma `std::runtime_error`, que é capturada e mostrada como erro. | Tratamento de exceções em C++, Orientação a objetos em C++: classes, herança e polimorfismo |

## 📄 Tarefas

Os enunciados das tarefas estão em [`TAREFAS/PDF`](../TAREFAS/PDF) e as resoluções nos projetos `Prj_Tarefa_*` e `Prj_Triangulo` (Exercício de Revisão).

## 📄 Licença

Todos os projetos estão licenciados sob a **MIT License**. Veja o arquivo [LICENSE](../LICENSE) na raiz do repositório.
