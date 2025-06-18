#ifndef SETADASTREVAS_H
#define SETADASTREVAS_H

#include "habilidade.h"

class SetaDasTrevas : public Habilidade {
public:
    SetaDasTrevas();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif