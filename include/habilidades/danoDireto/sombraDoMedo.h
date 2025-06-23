#ifndef SOMBRA_DO_MEDO_H
#define SOMBRA_DO_MEDO_H

#include "habilidade.h"

class SombraDoMedo : public Habilidade {
public:
    SombraDoMedo();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif