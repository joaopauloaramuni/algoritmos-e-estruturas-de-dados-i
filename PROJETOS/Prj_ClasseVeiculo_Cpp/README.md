# Projeto Prj_ClasseVeiculo_Cpp (C++) 🚙

> **C++: herança Veiculo → Carro**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra **herança** em C++: `Carro` herda de `Veiculo` e reaproveita o construtor e o método `exibirInformacoes` da classe base. Também mostra os três níveis de acesso: `private`, `protected` e `public`.

## 🎯 Conceitos trabalhados

- Herança pública (`class Carro : public Veiculo`)
- Chamada do construtor da classe base
- Modificadores `private`, `protected` e `public`

## 📚 Entendendo o conceito

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
// Classe derivada: Carro (herda de Veiculo)
class Carro: public Veiculo {
private:
    std::string marca;

public:
    Carro(const std::string &m, const std::string &mod, int a) :
            Veiculo(mod, a), marca(m) {
    }

    void exibirDetalhes() {
        std::cout << "Marca: " << marca << ", ";
        exibirInformacoes();  // Chama o método da classe base
    }
};
```

| Membro | Acesso | Quem enxerga |
| --- | --- | --- |
| `modelo` | `private` | Só a própria classe `Veiculo` |
| `ano` | `protected` | `Veiculo` e as classes filhas, como `Carro` |
| `exibirInformacoes()` | `public` | Qualquer código |

Dentro de `Carro`, `exibirDetalhes()` não consegue ler `modelo` diretamente, mas chama `exibirInformacoes()`, que pode.

## 💻 Exemplo de execução

```text
Marca: Toyota, Modelo: Corolla, Ano: 2022
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ClasseVeiculo_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ClasseVeiculo_Cpp`:

```bash
g++ src/Prj_ClasseVeiculo_Cpp.cpp -o Prj_ClasseVeiculo_Cpp
./Prj_ClasseVeiculo_Cpp
```

No Windows, rode `Prj_ClasseVeiculo_Cpp.exe` (ou `.\Prj_ClasseVeiculo_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_ClasseVeiculo_Cpp
│
├── 📁 src
│   └── Prj_ClasseVeiculo_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1603: Design Parking System](https://leetcode.com/problems/design-parking-system/)

## 🔗 Projetos relacionados

- [Prj_ClasseCarro_Cpp](../Prj_ClasseCarro_Cpp): C++: classe Carro
- [Prj_ClasseAnimal_Cpp](../Prj_ClasseAnimal_Cpp): C++: polimorfismo com virtual

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

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
