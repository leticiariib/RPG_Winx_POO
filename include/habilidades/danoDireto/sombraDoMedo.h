#ifndef SOMBRA_DO_MEDO_H
#define SOMBRA_DO_MEDO_H

#include "habilidades/habilidade.h"

class SombraDoMedo : public Habilidade {
public:
    SombraDoMedo();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif