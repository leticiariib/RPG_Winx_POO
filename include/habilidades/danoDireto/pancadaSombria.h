#ifndef PANCADASOMBRIA_H
#define PANCADASOMBRIA_H

#include "habilidades/habilidade.h"

class PancadaSombria : public Habilidade {
public:
    PancadaSombria();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif