#ifndef ABRACO_DANATUREZA_H
#define ABRACO_DANATUREZA_H

#include "habilidades/habilidade.h"
class Personagem;

class AbracoDaNatureza : public Habilidade {
public:
    AbracoDaNatureza();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif