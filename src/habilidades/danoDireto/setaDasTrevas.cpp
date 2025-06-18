#include "setaDasTrevas.h"
#include <iostream>

SetaDasTrevas::SetaDasTrevas()
    : Habilidade("Seta das Trevas", 45, 18) {} // Dano considerável, custo médio

void SetaDasTrevas::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.6f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    std::cout << atacante.getNome() << " disparou uma Seta das Trevas, causando "
              << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void SetaDasTrevas::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Dano Direto (Sombra)" << std::endl;
}