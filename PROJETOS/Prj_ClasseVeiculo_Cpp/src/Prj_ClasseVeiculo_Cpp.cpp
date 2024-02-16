//============================================================================
// Name        : Prj_ClasseVeiculo_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

// Classe base: Veiculo
class Veiculo {
private:
	std::string modelo;

protected:
	int ano;

public:
	Veiculo(const std::string &mod, int a) :
			modelo(mod), ano(a) {
	}

	void exibirInformacoes() {
		std::cout << "Modelo: " << modelo << ", Ano: " << ano << std::endl;
	}
};

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

int main(void) {
	// Criando um objeto da classe Carro
	Carro meuCarro("Toyota", "Corolla", 2022);

	// Chamando o método para exibir detalhes do carro (que inclui informações do veículo)
	meuCarro.exibirDetalhes();

	return 0;
}
