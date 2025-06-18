#ifndef ABRACO_DANATUREZA_H
#define ABRACO_DANATUREZA_H

#include "habilidade.h"

class AbracoDaNatureza : public Habilidade {
public:
    AbracoDaNatureza();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif