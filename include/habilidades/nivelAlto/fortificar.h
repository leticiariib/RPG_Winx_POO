#ifndef FORTIFICAR_H
#define FORTIFICAR_H

#include "habilidades/habilidade.h"
class Personagem;

class Fortificar : public Habilidade {
public:
    Fortificar();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif