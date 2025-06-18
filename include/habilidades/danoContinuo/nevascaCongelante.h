#ifndef NEVASCACONGELANTE_H
#define NEVASCACONGELANTE_H

#include "habilidade.h"

class NevascaCongelante : public Habilidade {
public:
    NevascaCongelante();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif