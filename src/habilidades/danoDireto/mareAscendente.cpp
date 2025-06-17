#include <iostream>
#include "mareAscendente.h"

MareAscendente::MareAscendente()
    : Habilidade("Mare Ascendente", 35, 15) {}

void MareAscendente::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = dano_base + atacante.getAtaque() * 0.4;
    int defesa_reduzida = alvo.getDefesa() * 0.8;
    int final = dano - defesa_reduzida;

    if (final < 0) final = 0;

    alvo.receberDano(final);
    alvo.reduzirVelocidade(10);

    cout << atacante.getNome() << " lançou uma habilidade que causou "
         << final << " de dano e reduziu a velocidade de "
         << alvo.getNome() << " em 10.\n";
}
