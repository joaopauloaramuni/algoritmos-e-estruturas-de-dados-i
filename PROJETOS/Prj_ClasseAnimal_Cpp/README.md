# Projeto Prj_ClasseAnimal_Cpp (C++) 🐶

> **C++: polimorfismo com virtual**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra **polimorfismo**: dois ponteiros do tipo `Animal*`, um apontando para um `Animal` e outro para um `Cachorro`. Por causa do `virtual`, cada um chama a sua própria versão de `emitirSom()`.

## 🎯 Conceitos trabalhados

- Método `virtual`
- Sobrescrita de método na classe filha
- Ponteiro da classe base apontando para objeto da filha
- `new`

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
class Animal {
public:
    virtual void emitirSom() const {
        cout << "Animal emite um som" << endl;
    }
};
```

```cpp
class Cachorro : public Animal {
public:
    void emitirSom() const {
        cout << "Cachorro late" << endl;
    }
};
```

Sem o `virtual`, `a2->emitirSom()` olharia só o tipo do ponteiro (`Animal*`) e imprimiria "Animal emite um som" duas vezes. Com o `virtual`, a decisão é feita durante a execução, pelo tipo real do objeto.

## 💻 Exemplo de execução

```text
Animal emite um som
Cachorro late
```

## ⚠️ Pontos de atenção

- Os objetos criados com `new` nunca são liberados com `delete`. Em um programa que termina logo isso não causa problema, mas o certo é `delete a1; delete a2;` antes do `return`, e a classe base deveria ter um destrutor `virtual ~Animal() {}`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ClasseAnimal_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ClasseAnimal_Cpp`:

```bash
g++ src/Prj_ClasseAnimal_Cpp.cpp -o Prj_ClasseAnimal_Cpp
./Prj_ClasseAnimal_Cpp
```

No Windows, rode `Prj_ClasseAnimal_Cpp.exe` (ou `.\Prj_ClasseAnimal_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_ClasseAnimal_Cpp
│
├── 📁 src
│   └── Prj_ClasseAnimal_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 1603: Design Parking System](https://leetcode.com/problems/design-parking-system/)

## 🔗 Projetos relacionados

- [Prj_ClasseVeiculo_Cpp](../Prj_ClasseVeiculo_Cpp): C++: herança Veiculo → Carro
- [Prj_Excecoes_Cpp](../Prj_Excecoes_Cpp): C++: tratamento de exceções

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
