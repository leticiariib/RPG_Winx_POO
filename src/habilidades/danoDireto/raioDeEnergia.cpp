#include "raioDeEnergia.h"
#include <iostream>

RaioDeEnergia::RaioDeEnergia()
    : Habilidade("Raio de Energia", 30, 18) {}

void RaioDeEnergia::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = dano_base + atacante.getAtaque() * 0.4;
    int defesa_reduzida = alvo.getDefesa() * 0.6;
    int final = dano - defesa_reduzida;

    if (final < 0) final = 0;

    alvo.receberDano(final);

    std::cout << atacante.getNome() << " lançou Raio de Energia causando "
              << final << " de dano em " << alvo.getNome() << ".\n";
}
