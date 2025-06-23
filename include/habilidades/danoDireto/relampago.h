#ifndef RELAMPAGOFULGURANTE_H
#define RELAMPAGOFULGURANTE_H

#include "habilidades/habilidade.h"

class RelampagoFulgurante : public Habilidade {
public:
    RelampagoFulgurante();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif