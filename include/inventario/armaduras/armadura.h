#ifndef ARMADURA_H
#define ARMADURA_H

#include "inventario/item.h"
#include "personagens/personagem.h"
#include <iostream>
#include <string>
using namespace std;

class Armadura : public Item {
    protected:
        string nome;
        string efeito;

    public:
        Armadura(string nome, string efeito) : nome(nome), efeito(efeito) {}
        string getNome() const override {
            return nome;
        }
        void mostrarInfo() const override {
            cout << "Armadura: " << nome << "\nEfeito: " << efeito << endl;
        }
};

#endif
