#ifndef RAIO_DE_ENERGIA_H
#define RAIO_DE_ENERGIA_H

#include "habilidades/habilidade.h"

class RaioDeEnergia : public Habilidade {
public:
    RaioDeEnergia();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif
