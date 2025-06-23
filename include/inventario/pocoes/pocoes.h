#ifndef POCAO_H
#define POCAO_H

#include "inventario/item.h"
#include "personagens/personagem.h"
#include <iostream>
using namespace std;

class Pocao : public Item {
protected:
    string nome;
    string efeito;

public:
    Pocao(string nome, string efeito) : nome(nome), efeito(efeito) {}

    string getNome() const override {
        return nome;
    }

    void mostrarInfo() const override {
        cout << "Poção: " << nome << "\nEfeito: " << efeito << endl;
    }
};

#endif
