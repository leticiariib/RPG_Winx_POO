#ifndef ARMADURA_H
#define ARMADURA_H

#include "Item.h"
#include "Personagem.h"
#include <iostream>
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

class MantoDeEnchantix : public Armadura {
    public:
        MantoDeEnchantix() : Armadura("Manto de Enchantix", "Aumenta defesa física e mágica em 40% por 3 turnos.") {}

        void aplicarEfeito(Personagem& alvo) override;
};

class CapaDaGuardia : public Armadura {
    public:
        CapaDaGuardia() : Armadura("Capa da Guardiã", "Reduz dano recebido em 20% enquanto equipado.") {}

        void aplicarEfeito(Personagem& alvo) override;
};

#endif
