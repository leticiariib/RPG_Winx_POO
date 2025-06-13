#ifndef JATO_DE_AGUA_H
#define JATO_DE_AGUA_H

#include "habilidade.h"

class JatoDeAgua : public Habilidade {
public:
    JatoDeAgua() : Habilidade("Jato de Agua", 35, 15) {}
    void aplicar(Personagem& atacante, Personagem& alvo) override {
        int dano = dano_base + atacante.getAtaque() * 0.5;
        int final = dano - alvo.getDefesa();
        if (final < 0) final = 0;
        alvo.receberDano(final);
        cout << atacante.getNome() << " lançou Jato de Água causando " << final << " de dano direto.\n";
    }
};

#endif