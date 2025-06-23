#ifndef MARE_ASCENDENTE_H
#define MARE_ASCENDENTE_H

#include "habilidades/habilidade.h"

class MareAscendente : public Habilidade {
public:
    MareAscendente();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif