//============================================================================
// Name        : Prj_ClasseAnimal_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void emitirSom() const {
        cout << "Animal emite um som" << endl;
    }
};

class Cachorro : public Animal {
public:
    void emitirSom() const {
        cout << "Cachorro late" << endl;
    }
};

int main(void) {
    Animal *a1 = new Animal();
    Animal *a2 = new Cachorro();

    a1->emitirSom();
    a2->emitirSom();

    return 0;
}

