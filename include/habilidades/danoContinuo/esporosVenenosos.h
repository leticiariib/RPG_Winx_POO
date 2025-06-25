#ifndef ESPOROS_VENENOSOS_H
#define ESPOROS_VENENOSO_H

#include "habilidades/habilidade.h"
class Personagem;

class EsporosVenenosos : public Habilidade{
    public: 
    EsporosVenenosos(); 
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif