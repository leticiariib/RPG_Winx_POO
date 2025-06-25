#ifndef PILAR_DE_AGUA_H
#define PILAR_DE_AGUA_H

#include "habilidades/habilidade.h"
class Personagem;

class PilarDeAgua : public Habilidade {
public:
    PilarDeAgua();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif