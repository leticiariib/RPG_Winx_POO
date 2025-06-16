#ifndef POCAO_H
#define POCAO_H

#include "Item.h"
#include "Personagem.h"
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

class PoDeFada : public Pocao {
public:
    PoDeFada() : Pocao("Pó de Fada", "Recupera 20% da magia.") {}

    void aplicarEfeito(Personagem& alvo) override;
};

class ElixirDaVida : public Pocao {
public:
    ElixirDaVida() : Pocao("Elixir da Vida", "Recupera 50% da vida.") {}

    void aplicarEfeito(Personagem& alvo) override;
};

#endif
