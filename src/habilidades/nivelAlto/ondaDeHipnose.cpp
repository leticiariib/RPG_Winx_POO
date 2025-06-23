#include "habilidades/nivelAlto/ondaDeHipnose.h"
#include <iostream>

OndaDeHipnose::OndaDeHipnose()
    : Habilidade("Onda de Hipnose", 40, 25) {}

void OndaDeHipnose::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.4f;
    float dano_final = dano - (alvo.getDefesa() * 0.6f);
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    alvo.reduzirVelocidade(20);

    cout << atacante.getNome() << " liberou uma Onda de Hipnose em " << alvo.getNome() << "!\n"
         << "Isso causou " << dano_final << " de dano e reduziu sua velocidade em 20.\n";
}

void OndaDeHipnose::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano Direto (Sombra/Controle)" << endl;
}