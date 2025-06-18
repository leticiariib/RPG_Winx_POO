#ifndef CRESCENDO_ESTILHACANTE_H
#define CRESCENDO_ESTILHACANTE_H

#include "habilidade.h"

class CrescendoEstilhacante : public Habilidade {
public:
    CrescendoEstilhacante();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif