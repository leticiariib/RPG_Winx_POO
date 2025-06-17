#ifndef PO_DE_FADA_H
#define PO_DE_FADA_H

#include "pocoes.h"

class PoDeFada : public Pocao {
public:
    PoDeFada() : Pocao("Pó de Fada", "Recupera 20% da magia.") {}

    void aplicarEfeito(Personagem& alvo) override{
        alvo.recuperarMagiaPercentual(0.2);
    }
};

#endif
