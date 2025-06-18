#ifndef FIREWALLDIGITAL_H
#define FIREWALLDIGITAL_H

#include "habilidade.h"

class FirewallDigital : public Habilidade {
public:
    FirewallDigital();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    void mostrarDetalhes() const override;
};

#endif