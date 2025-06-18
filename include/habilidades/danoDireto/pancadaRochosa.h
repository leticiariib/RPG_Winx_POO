#ifndef PANCADAROCHOSA_H
#define PANCADAROCHOSA_H

#include "habilidade.h"

class PancadaRochosa : public Habilidade {
public:
    PancadaRochosa();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif