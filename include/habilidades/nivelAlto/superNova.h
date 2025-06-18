#ifndef SUPER_NOVA_H
#define SUPER_NOVA_H

#include "habilidade.h"

class Supernova : public Habilidade {
public:
    Supernova();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif