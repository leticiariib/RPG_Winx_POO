#ifndef ATAQUEBASICO_H
#define ATAQUEBASICO_H

#include "habilidades\habilidade.h"

class AtaqueBasico : public Habilidade {
public:
    AtaqueBasico();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif