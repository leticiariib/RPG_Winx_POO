#include "habilidades/danoDireto/pancadaRochosa.h"
#include "personagens/personagem.h"
#include <iostream>

PancadaRochosa::PancadaRochosa()
    : Habilidade("Pancada Rochosa", 25, 0) {} 

void PancadaRochosa::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.5f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 5) dano_final = 5; 

    alvo.receberDano(dano_final);
    std::cout << atacante.getNome() << " atacou com uma Pancada Rochosa, causando "
              << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void PancadaRochosa::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Dano Direto (Físico/Terra)" << std::endl;
}