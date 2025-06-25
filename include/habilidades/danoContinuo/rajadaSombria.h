#ifndef RAJADA_SOMBRIA_H
#define RAJADA_SOMBRIA_H

#include "habilidades/habilidade.h"
class Personagem;

class RajadaSombria : public Habilidade {
public:
    RajadaSombria();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif
