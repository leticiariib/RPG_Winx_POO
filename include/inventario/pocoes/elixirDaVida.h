#ifndef ELIXIR_DA_VIDA_H
#define ELIXIR_DA_VIDA_H

#include "inventario/pocoes/pocoes.h"

class ElixirDaVida : public Pocao {
public:
    ElixirDaVida() : Pocao("Elixir da Vida", "Recupera 50% da vida.") {}

    void aplicarEfeito(Personagem& alvo) override{
        alvo.recuperarVidaPercentual(0.5);
    }
};
#endif
