#include "esporosVenenosos.h"
#include <iostream>

EsporosVenenosos::EsporosVenenosos()
    : Habilidade("Esporos Venenosos", 25, 12) {}

void EsporosVenenosos::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 8 + atacante.getAtaque() * 0.15;

    EfeitoContinuo efeito = {"dano por veneno", dano, 3};  
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " lançou Esporos Venenosos. "
         << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
}
