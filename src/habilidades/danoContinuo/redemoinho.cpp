#include "redemoinho.h"
#include <iostream>

Redemoinho::Redemoinho()
    : Habilidade("Jato de Agua", 35, 15) {}

void Redemoinho::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 10 + atacante.getAtaque() * 0.2;

    EfeitoContinuo efeito = {"dano", dano, 3};
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " lançou Redemoinho. "
         << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
}
