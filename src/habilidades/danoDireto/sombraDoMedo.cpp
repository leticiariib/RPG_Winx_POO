#include "habilidades\danoDireto\sombraDoMedo.h"
#include "personagens/personagem.h"
#include <iostream>

SombraDoMedo::SombraDoMedo()
    : Habilidade("Sombra do Medo", 30, 15) {}

void SombraDoMedo::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.4f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    alvo.reduzirVelocidade(15); 

    std::cout << atacante.getNome() << " projetou uma Sombra do Medo em " << alvo.getNome() << "!\n"
              << "Isso causou " << dano_final << " de dano e reduziu sua velocidade em 15.\n";
}

void SombraDoMedo::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Dano com Efeito (Sombra)" << std::endl;
}