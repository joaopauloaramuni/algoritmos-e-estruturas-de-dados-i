//============================================================================
// Name        : Prj_Classe_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

// Definição da classe Carro
class Carro {
public:
	// Membros da classe
	std::string marca;
	std::string modelo;
	int ano;

	// Construtor
	Carro(const std::string &m, const std::string &mod, int a) :
			marca(m), modelo(mod), ano(a) {
	}

	// Construtor para criar um carro vazio
	Carro() : marca(""), modelo(""), ano(0) {
	}

	// Método para exibir informações sobre o carro
	void exibirInformacoes() {
		std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: "
				<< ano << std::endl;
	}
};

int main(void) {
	// Criando um objeto da classe Carro
	Carro meuCarro;

	// Criando um objeto da classe Carro usando o construtor
	//Carro meuCarro("Toyota", "Corolla", 2022);

	// Atribuindo valores aos membros da classe
	meuCarro.marca = "Toyota";
	meuCarro.modelo = "Corolla";
	meuCarro.ano = 2022;

	// Chamando o método para exibir informações sobre o carro
	meuCarro.exibirInformacoes();

	return 0;
}


