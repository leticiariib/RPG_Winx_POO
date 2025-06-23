#ifndef CHAMAS_PERSISTENTES_H
#define CHAMAS_PERSISTENTES_H

#include "habilidades/habilidade.h"

class ChamasPersistentes : public Habilidade {
public:
    ChamasPersistentes();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif
