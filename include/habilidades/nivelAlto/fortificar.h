#ifndef FORTIFICAR_H
#define FORTIFICAR_H

#include "habilidade.h"

class Fortificar : public Habilidade {
public:
    Fortificar();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif