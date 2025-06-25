#ifndef CURTO_CIRCUITO_H
#define CURTO_CIRCUITO_H

#include "habilidades/habilidade.h"
class Personagem;

class CurtoCircuito : public Habilidade {
public:
    CurtoCircuito();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif