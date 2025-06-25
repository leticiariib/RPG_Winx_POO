#include "habilidades\danoDireto\clavaEsmagadora.h"
#include <iostream>

ClavaEsmagadora::ClavaEsmagadora()
    : Habilidade("Clava Esmagadora", 30, 0) {} 

void ClavaEsmagadora::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.5f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 10) dano_final = 10;

    alvo.receberDano(dano_final);
    std::cout << atacante.getNome() << " brandiu sua Clava Esmagadora, causando "
              << dano_final << " de dano em " << alvo.getNome() << "!\n";
}

void ClavaEsmagadora::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Dano Direto (Físico)" << std::endl;
}