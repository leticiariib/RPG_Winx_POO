#ifndef ONDA_SONORA_H
#define ONDA_SONORA_H

#include "habilidades/habilidade.h"
class Personagem;

class OndaSonora : public Habilidade {
public:
    OndaSonora();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif