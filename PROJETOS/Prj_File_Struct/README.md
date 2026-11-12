# Projeto Prj_File_Struct (C) 💾

> **Arquivo binário com struct**. Tema: **Arquivos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Grava uma struct inteira em um **arquivo binário** (`exemplo_struct.bin`) com `fwrite` e lê de volta com `fread`.

## 🎯 Conceitos trabalhados

- Modos binários `"wb"` e `"rb"`
- `fwrite` e `fread`
- `sizeof(struct ...)`

## 📚 Entendendo o conceito

Este projeto trabalha **Arquivos (texto e binário)** e **Structs e typedef**.

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
    // Abre o arquivo para escrita binária
    FILE *arquivo = fopen("exemplo_struct.bin", "wb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // Cria uma instância da estrutura
        struct ExemploStruct dadosParaGravar = { 13, 3.14,
                "Estrutura de exemplo" };

        // Escreve a estrutura no arquivo
        fwrite(&dadosParaGravar, sizeof(struct ExemploStruct), 1, arquivo);

        // Fecha o arquivo
        fclose(arquivo);
        printf("Estrutura gravada com sucesso.\n");
    } else {
        // Se houver erro na abertura do arquivo
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

    // Abre o arquivo para leitura binária
    FILE *arquivoLeitura = fopen("exemplo_struct.bin", "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoLeitura != NULL) {
        // Cria uma instância da estrutura para armazenar os dados lidos
        struct ExemploStruct dadosLidos;

        // Lê a estrutura do arquivo
        fread(&dadosLidos, sizeof(struct ExemploStruct), 1, arquivoLeitura);

        // Fecha o arquivo de leitura
        fclose(arquivoLeitura);

        // Exibe os dados lidos
        printf("Dados lidos da estrutura: Numero: %d, Decimal: %.2f, Texto: %s\n",
                dadosLidos.numero, dadosLidos.decimal, dadosLidos.texto);
    } else {
        // Se houver erro na abertura do arquivo de leitura
        printf("Erro ao abrir o arquivo para leitura.\n");
    }

    return 0;
}
```

Em vez de transformar cada campo em texto, o `fwrite` copia os bytes da struct direto para o disco. Por isso o `.bin` não é legível em um editor de texto. O arquivo depende da máquina (tamanho dos tipos, alinhamento, *endianness*): um `.bin` gravado em um computador pode não ser lido corretamente em outro.

## 💻 Exemplo de execução

```text
Estrutura gravada com sucesso.
Dados lidos da estrutura: Numero: 13, Decimal: 3.14, Texto: Estrutura de exemplo
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_File_Struct` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_File_Struct`:

```bash
gcc src/Prj_File_Struct.c -o Prj_File_Struct
./Prj_File_Struct
```

No Windows, rode `Prj_File_Struct.exe` (ou `.\Prj_File_Struct.exe` no PowerShell).

> 📂 Rode o programa de dentro da pasta do projeto: o arquivo é criado na pasta atual do terminal.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_File_Struct
│
├── 📁 src
│   └── Prj_File_Struct.c
├── exemplo_struct.bin            └── Arquivo binário gerado pelo programa ao rodar
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)

## 🔗 Projetos relacionados

- [Prj_File](../Prj_File): Arquivo texto: gravar e ler
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: fopen](https://en.cppreference.com/w/c/io/fopen)
- [cppreference: fwrite](https://en.cppreference.com/w/c/io/fwrite)
- [cppreference: fread](https://en.cppreference.com/w/c/io/fread)
- [cppreference: entrada e saída de arquivos (<stdio.h>)](https://en.cppreference.com/w/c/io)
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
