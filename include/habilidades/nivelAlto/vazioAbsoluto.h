#ifndef VAZIOABSOLUTO_H
#define VAZIOABSOLUTO_H

#include "habilidades/habilidade.h"
class Personagem;

class VazioAbsoluto : public Habilidade {
public:
    VazioAbsoluto();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif