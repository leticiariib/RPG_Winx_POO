#ifndef CLAVAESMAGADORA_H
#define CLAVAESMAGADORA_H

#include "habilidades\habilidade.h"
class Personagem;

class ClavaEsmagadora : public Habilidade {
public:
    ClavaEsmagadora();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif