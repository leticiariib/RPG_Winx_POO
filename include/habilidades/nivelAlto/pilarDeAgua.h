#ifndef PILAR_DE_AGUA_H
#define PILAR_DE_AGUA_H

#include "habilidade.h"

class PilarDeAgua : public Habilidade {
public:
    PilarDeAgua();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif