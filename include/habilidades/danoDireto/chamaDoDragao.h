#ifndef CHAMA_DO_DRAGAO_H
#define CHAMA_DO_DRAGAO_H

#include "habilidade.h"

class ChamaDoDragao : public Habilidade {
public:
    ChamaDoDragao();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif