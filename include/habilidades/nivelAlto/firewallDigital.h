#ifndef FIREWALLDIGITAL_H
#define FIREWALLDIGITAL_H

#include "habilidades/habilidade.h"
class Personagem;

class FirewallDigital : public Habilidade {
public:
    FirewallDigital();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif