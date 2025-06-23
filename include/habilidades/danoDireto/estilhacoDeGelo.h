#ifndef ESTILHACO_DE_GELO_H
#define ESTILHACO_DE_GELO_H

#include "habilidades/habilidade.h"

class EstilhacoDeGelo : public Habilidade {
public:
    EstilhacoDeGelo();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif
