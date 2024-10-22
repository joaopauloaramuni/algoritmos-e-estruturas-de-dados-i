//============================================================================
// Name        : Prj_Excecoes_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept> // Necessário para std::runtime_error

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
