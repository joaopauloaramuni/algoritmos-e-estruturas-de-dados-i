# Projeto Prj_Pali+File (C) 🗂️

> **Palíndromos gravados em arquivo**. Tema: **Arquivos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Junta dois assuntos: verifica palavras com a função recursiva de palíndromo e grava o resultado de cada uma em `exemplo.txt`. No final, lê o arquivo e mostra tudo.

## 🎯 Conceitos trabalhados

- Função recursiva de palíndromo
- `sprintf` para montar uma frase
- Gravação em arquivo dentro de um laço

## 📚 Entendendo o conceito

Este projeto trabalha **Arquivos (texto e binário)** e **Palíndromos e a técnica de dois ponteiros**.

### Arquivos (texto e binário)

Arquivos guardam dados depois que o programa termina. Em C, um arquivo é aberto com `fopen`, que devolve um `FILE *` (ou `NULL`, se falhar), e fechado com `fclose`. O **modo** de abertura decide o que se pode fazer:

| Modo | Significado |
| --- | --- |
| `"r"` | Leitura (o arquivo precisa existir) |
| `"w"` | Escrita (cria o arquivo ou **apaga** o conteúdo anterior) |
| `"a"` | Acréscimo no final |
| `"rb"`, `"wb"` | Leitura e escrita em modo binário |

Em **modo texto** usam-se `fprintf`, `fscanf`, `fgets` e `fputs`, e o arquivo pode ser lido por pessoas. Em **modo binário** usam-se `fwrite` e `fread`, que copiam os bytes da memória direto para o disco: é mais rápido e compacto, mas o arquivo depende da máquina (tamanho dos tipos, ordem dos bytes).

#### 🌍 Onde é usado na prática

- *Logs*, arquivos de configuração e exportação de dados (CSV).
- Formatos binários: imagens, áudio, executáveis, arquivos de *save* de jogos.
- Bancos de dados como o SQLite são, no fundo, um arquivo binário muito bem organizado.

#### 💼 Em processos seletivos

Em entrevistas de algoritmos, arquivos aparecem pouco. Já em vagas de *back-end* e de dados, perguntam sobre ler arquivos grandes sem carregar tudo na memória, linha por linha, e sobre a diferença entre texto e binário.

Perguntas que costumam aparecer:

- Qual a diferença entre os modos `"w"` e `"a"`?
- Por que verificar se `fopen` devolveu `NULL`?
- Quando preferir um formato binário a um formato texto?

#### 🐞 Erros comuns

- Não testar o retorno de `fopen`.
- Esquecer o `fclose`: os dados podem ficar no *buffer* e não chegar ao disco.
- Abrir com `"w"` um arquivo que se queria preservar.
- Passar texto lido do usuário como formato do `fprintf` (`fprintf(f, texto)`): use `fprintf(f, "%s", texto)`.

### Palíndromos e a técnica de dois ponteiros

Um **palíndromo** é uma palavra ou frase que se lê igual nos dois sentidos: ARARA, OVO, RADAR. A forma eficiente de verificar é a técnica de **dois ponteiros**: um índice começa no início, outro no fim, e os dois andam em direção ao meio comparando os caracteres. Se algum par for diferente, não é palíndromo; se os índices se cruzarem, é.

A mesma verificação tem uma forma recursiva natural: a palavra é palíndromo se as pontas são iguais **e** o miolo também é palíndromo.

#### 🌍 Onde é usado na prática

- A técnica de dois ponteiros resolve muitos problemas em vetores ordenados (achar pares com soma alvo, remover duplicados) sem memória extra.
- Bioinformática: sequências palindrômicas de DNA marcam pontos de corte de enzimas de restrição.

#### 💼 Em processos seletivos

"Verifique se uma string é palíndromo" é uma das perguntas de aquecimento mais comuns. As variações ignoram maiúsculas, espaços e pontuação, permitem remover um caractere ou pedem o maior palíndromo dentro de uma string. Dois ponteiros é um dos padrões que mais caem em entrevistas.

Perguntas que costumam aparecer:

- Verifique um palíndromo sem criar uma cópia invertida.
- Ignore espaços e maiúsculas ("Socorram-me, subi no ônibus em Marrocos").
- Verifique se um número inteiro é palíndromo sem convertê-lo em texto.

#### ⏱️ Complexidade

O(n) de tempo; O(1) de memória com dois ponteiros (O(n) se criar uma cópia invertida).

#### 🐞 Erros comuns

- Comparar além do `'\0'`.
- Esquecer que maiúsculas e minúsculas são caracteres diferentes.

## 🧠 Como funciona o código

```c
int isPalindrome(char str[], int left, int right) {
    return (left >= right) ?
            1 :
            (str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}
```

O `sprintf` funciona como um `printf`, mas escreve em uma string (`resultado`) em vez de na tela; a string é então gravada no arquivo. O `exemplo.txt` que acompanha o projeto tem o resultado de uma execução com ARARA, OVO e OTTO.

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
Deseja continuar? sim=1, sair=0: 1
Digite uma palavra: OVO
Deseja continuar? sim=1, sair=0: 1
Digite uma palavra: CASA
Deseja continuar? sim=1, sair=0: 0
Texto gravado com sucesso.
A palavra ARARA é um palíndromo.
A palavra OVO é um palíndromo.
A palavra CASA não é um palíndromo.
```

## ⚠️ Pontos de atenção

- `fprintf(arquivo, resultado)` usa o texto lido como **formato**. Se a palavra tiver um `%`, o `fprintf` vai tentar interpretá-lo. O seguro é `fprintf(arquivo, "%s", resultado)` ou `fputs(resultado, arquivo)`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Pali+File` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Pali+File`:

```bash
gcc src/Prj_Pali+File.c -o Prj_Pali_File
./Prj_Pali_File
```

No Windows, rode `Prj_Pali_File.exe` (ou `.\Prj_Pali_File.exe` no PowerShell).

> 📂 Rode o programa de dentro da pasta do projeto: o arquivo é criado na pasta atual do terminal.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Pali+File
│
├── 📁 src
│   └── Prj_Pali+File.c
├── exemplo.txt                   └── Arquivo gerado pelo programa ao rodar
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [LeetCode 9: Palindrome Number](https://leetcode.com/problems/palindrome-number/)
- [LeetCode 680: Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)

## 🔗 Projetos relacionados

- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_File](../Prj_File): Arquivo texto: gravar e ler

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: fopen](https://en.cppreference.com/w/c/io/fopen)
- [cppreference: fwrite](https://en.cppreference.com/w/c/io/fwrite)
- [cppreference: fread](https://en.cppreference.com/w/c/io/fread)
- [cppreference: entrada e saída de arquivos (<stdio.h>)](https://en.cppreference.com/w/c/io)
- [Wikipedia: Palindrome](https://en.wikipedia.org/wiki/Palindrome)

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
