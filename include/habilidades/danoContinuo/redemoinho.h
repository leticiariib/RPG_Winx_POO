#ifndef REDEMOINHO_H
#define REDEMOINHO_H

#include "habilidade.h"

class Redemoinho : public Habilidade {
public:
    Redemoinho() : Habilidade("Jato de Agua", 35, 15) {}
    void aplicar(Personagem& atacante, Personagem& alvo) override {
        int dano = 10 + atacante.getAtaque() * 0.2;

        Personagem::EfeitoContinuo efeito = {"dano", dano, 3};
        alvo.aplicarEfeito(efeito);
        cout << atacante.getNome() << " lançou Redemoinho. "
                << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
    }
};

#endif