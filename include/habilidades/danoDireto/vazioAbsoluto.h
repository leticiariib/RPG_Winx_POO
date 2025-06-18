#ifndef VAZIOABSOLUTO_H
#define VAZIOABSOLUTO_H

#include "habilidade.h"

class VazioAbsoluto : public Habilidade {
public:
    VazioAbsoluto();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif