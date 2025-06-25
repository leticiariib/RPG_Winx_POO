#ifndef FURIA_DO_DRAGAO_H
#define FURIA_DO_DRAGAO_H

#include "habilidades/habilidade.h"
class Personagem;

class FuriaDoDragao : public Habilidade {
public:
    FuriaDoDragao();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif