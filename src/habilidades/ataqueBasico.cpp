#include "habilidades\ataqueBasico.h"
#include "personagens\personagem.h"
#include <iostream>

AtaqueBasico::AtaqueBasico()
    : Habilidade("Ataque Básico", 5, 0) {} // Dano base muito baixo, CUSTO ZERO

void AtaqueBasico::aplicar(Personagem& atacante, Personagem& alvo) {
    // Dano que escala muito pouco, para que habilidades de verdade sejam sempre melhores.
    float dano = dano_base + atacante.getAtaque() * 0.1f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 1) dano_final = 1; // Garante pelo menos 1 de dano

    alvo.receberDano(dano_final);
    std::cout << atacante.getNome() << " usa um Ataque Básico, causando "
              << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void AtaqueBasico::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Dano Direto (Custo: 0)" << std::endl;
}