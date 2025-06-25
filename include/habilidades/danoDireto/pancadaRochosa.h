#ifndef PANCADAROCHOSA_H
#define PANCADAROCHOSA_H

#include "habilidades/habilidade.h"
class Personagem;

class PancadaRochosa : public Habilidade {
public:
    PancadaRochosa();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif