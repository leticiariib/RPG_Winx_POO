#ifndef ONDADEHIPNOSE_H
#define ONDADEHIPNOSE_H

#include "habilidade.h"

class OndaDeHipnose : public Habilidade {
public:
    OndaDeHipnose();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif