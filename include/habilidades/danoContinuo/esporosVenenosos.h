#ifndef ESPOROS_VENENOSOS_H
#define ESPOROS_VENENOSO_H

#include "habilidade.h"

class EsporosVenenosos : public Habilidade{
    public: 
    EsporosVenenosos(); 
    void aplicar(Personagem& atacante, Personagem& alvo) override;
};

#endif