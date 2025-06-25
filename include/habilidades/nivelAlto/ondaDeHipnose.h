#ifndef ONDADEHIPNOSE_H
#define ONDADEHIPNOSE_H

#include "habilidades/habilidade.h"
class Personagem;

class OndaDeHipnose : public Habilidade {
public:
    OndaDeHipnose();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif