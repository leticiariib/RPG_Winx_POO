#ifndef FURIA_DO_DRAGAO_H
#define FURIA_DO_DRAGAO_H

#include "habilidade.h"

class FuriaDoDragao : public Habilidade {
public:
    FuriaDoDragao();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif