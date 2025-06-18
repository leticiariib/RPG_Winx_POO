#ifndef FURACAO_DESTRUIDOR_H
#define FURACAO_DESTRUIDOR_H

#include "habilidade.h"

class FuracaoDestruidor : public Habilidade {
public:
    FuracaoDestruidor();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif