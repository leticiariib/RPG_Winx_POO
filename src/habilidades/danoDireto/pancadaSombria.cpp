#include "habilidades/danoDireto/pancadaSombria.h"
#include <iostream>

// habilidade bem fraca, ideal pros inimigos faceis
PancadaSombria::PancadaSombria()
    : Habilidade("Pancada Sombria", 15, 0) {} 

void PancadaSombria::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.3f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 5) dano_final = 5; // garante um dano mínimo

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " usou Pancada Sombria, causando "
         << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void PancadaSombria::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano Direto (Sombra)" << endl;
}