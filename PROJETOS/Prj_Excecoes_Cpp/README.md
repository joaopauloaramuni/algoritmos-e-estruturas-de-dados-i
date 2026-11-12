# Projeto Prj_Excecoes_Cpp (C++) 🚨

> **C++: tratamento de exceções**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra `try`, `throw` e `catch` em C++: antes de dividir por zero, o programa lança uma `std::runtime_error`, que é capturada e mostrada como erro.

## 🎯 Conceitos trabalhados

- `try` / `catch` / `throw`
- `std::runtime_error` de `<stdexcept>`
- Ordem dos `catch` (do mais específico ao mais genérico)
- `catch (...)`

## 📚 Entendendo o conceito

Este projeto trabalha **Tratamento de exceções em C++** e **Orientação a objetos em C++: classes, herança e polimorfismo**.

### Tratamento de exceções em C++

Uma **exceção** sinaliza um erro que a função não consegue resolver sozinha. O código que pode falhar fica num bloco `try`; quando algo dá errado, a função **lança** a exceção com `throw`, e a execução pula para o primeiro `catch` compatível, desfazendo as chamadas no caminho.

A biblioteca padrão tem uma hierarquia de exceções: `std::exception` na raiz, `std::runtime_error` para erros de execução, `std::invalid_argument`, `std::out_of_range` e outras. Os `catch` são testados na ordem em que aparecem, do mais específico ao mais genérico. Erros de hardware, como a divisão inteira por zero, **não** viram exceções de C++ automaticamente: o próprio código precisa testar e lançar.

#### 🌍 Onde é usado na prática

- Tratar falhas de rede, de arquivo e de validação sem misturar a lógica de erro com a lógica principal.
- Java, C#, Python e JavaScript usam o mesmo modelo de `try/catch`.

#### 💼 Em processos seletivos

Perguntas sobre exceções são comuns em qualquer linguagem: quando lançar, quando capturar, a ordem dos `catch` e, em C++, a técnica RAII (recursos liberados pelos destrutores mesmo quando uma exceção é lançada).

Perguntas que costumam aparecer:

- Por que capturar a exceção mais específica primeiro?
- O que é RAII?
- Exceções ou códigos de erro? Quando usar cada um?

#### 🐞 Erros comuns

- Capturar `std::exception` antes das específicas (as específicas nunca são alcançadas).
- Usar exceções para fluxo normal do programa.

### Orientação a objetos em C++: classes, herança e polimorfismo

Uma **classe** junta dados (atributos) e as funções que trabalham com eles (métodos). É o passo seguinte à struct de C. Os pilares da orientação a objetos são:

| Pilar | Em C++ |
| --- | --- |
| Encapsulamento | `private`, `protected` e `public` controlam quem acessa cada membro |
| Herança | `class Carro : public Veiculo` reaproveita a classe base |
| Polimorfismo | Métodos `virtual` decidem, durante a execução, qual versão chamar |
| Abstração | Classes com métodos virtuais puros (`= 0`) definem interfaces |

O **construtor** inicializa o objeto (de preferência com a lista de inicialização `: modelo(m), ano(a)`), e C++ permite vários construtores com o mesmo nome e parâmetros diferentes (**sobrecarga**), o que C não permite.

#### 🌍 Onde é usado na prática

- Motores de jogos (Unreal Engine), navegadores (Chromium), bancos de dados e software de alto desempenho são escritos em C++.
- Os mesmos conceitos são a base de Java, C#, Python, Kotlin e Swift.

#### 💼 Em processos seletivos

Os quatro pilares, a diferença entre sobrecarga e sobrescrita, herança × composição e o papel do `virtual` (e do destrutor virtual) são perguntas muito comuns em entrevistas de qualquer linguagem orientada a objetos. Em vagas de C++, também se pergunta sobre a *vtable* e o gerenciamento de memória com `new`/`delete`.

Perguntas que costumam aparecer:

- Quais são os pilares da orientação a objetos?
- Qual a diferença entre sobrecarga e sobrescrita?
- Por que a classe base deve ter um destrutor virtual?
- Herança ou composição? Dê um exemplo.

#### 🐞 Erros comuns

- Esquecer o `virtual` e o método da classe filha não ser chamado por um ponteiro da classe base.
- Criar objetos com `new` e não liberar com `delete` (prefira objetos na pilha ou `std::unique_ptr`).
- Tornar públicos atributos que deveriam ser privados.

## 🧠 Como funciona o código

```cpp
int main() {
    try {
        // Código que pode gerar exceções
        int divisor = 0;
        if (divisor == 0) {
            throw std::runtime_error("Divisão por zero não permitida");
        }
        // O código abaixo não será executado se a exceção ocorrer acima
        int resultado = 10 / divisor;
        std::cout << "Resultado: " << resultado << std::endl;
    } catch (const std::runtime_error &e) {
        // Captura e trata exceções do tipo std::runtime_error
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        // Captura e trata outras exceções derivadas de std::exception
        std::cerr << "Exceção: " << e.what() << std::endl;
    } catch (...) {
        // Captura qualquer outra exceção não tratada pelos blocos anteriores
        std::cerr << "Exceção desconhecida" << std::endl;
    }

    return 0;
}
```

Divisão inteira por zero em C/C++ não gera exceção: o programa simplesmente trava (no Linux, com *Floating point exception*). Por isso o código testa o divisor e lança a exceção ele mesmo. Os `catch` são testados na ordem: `runtime_error` primeiro, depois qualquer `std::exception` e, por fim, `...`, que captura qualquer coisa. A mensagem sai em `std::cerr`, a saída de erros.

## 💻 Exemplo de execução

```text
Erro: Divisão por zero não permitida
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Excecoes_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Excecoes_Cpp`:

```bash
g++ src/Prj_Excecoes_Cpp.cpp -o Prj_Excecoes_Cpp
./Prj_Excecoes_Cpp
```

No Windows, rode `Prj_Excecoes_Cpp.exe` (ou `.\Prj_Excecoes_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_Excecoes_Cpp
│
├── 📁 src
│   └── Prj_Excecoes_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1603: Design Parking System](https://leetcode.com/problems/design-parking-system/)

## 🔗 Projetos relacionados

- [Prj_Calculadora_Ponteiros](../Prj_Calculadora_Ponteiros): Calculadora com ponteiros
- [Prj_ClasseAnimal_Cpp](../Prj_ClasseAnimal_Cpp): C++: polimorfismo com virtual

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: exceções](https://en.cppreference.com/w/cpp/language/exceptions)
- [cppreference: std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error)
- [cppreference: RAII](https://en.cppreference.com/w/cpp/language/raii)
- [cppreference: classes](https://en.cppreference.com/w/cpp/language/classes)
- [cppreference: classes derivadas (herança)](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference: funções virtuais](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference: construtores e listas de inicialização](https://en.cppreference.com/w/cpp/language/constructor)
- [learncpp.com: curso gratuito de C++](https://www.learncpp.com/)

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

- STROUSTRUP, B. *Princípios e práticas de programação com C++*. Bookman. Escrito pelo criador do C++.
- DEITEL, P.; DEITEL, H. *C++: como programar*. Pearson.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
