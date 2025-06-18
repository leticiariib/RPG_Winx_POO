#ifndef REDEMOINHO_H
#define REDEMOINHO_H

#include "habilidade.h"

class Redemoinho : public Habilidade {
public:
    Redemoinho();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif
