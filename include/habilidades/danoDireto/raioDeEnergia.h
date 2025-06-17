#ifndef RAIO_DE_ENERGIA_H
#define RAIO_DE_ENERGIA_H

#include "habilidade.h"

class RaioDeEnergia : public Habilidade {
public:
    RaioDeEnergia();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
};

#endif
