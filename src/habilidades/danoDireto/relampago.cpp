#include "habilidades/danoDireto/relampago.h"
#include <iostream>

RelampagoFulgurante::RelampagoFulgurante()
    : Habilidade("Relâmpago Fulgurante", 50, 20) {}

void RelampagoFulgurante::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.5f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " disparou um Relâmpago Fulgurante, causando "
         << dano_final << " de dano elétrico em " << alvo.getNome() << ".\n";
}

void RelampagoFulgurante::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano Direto (Trovão)" << endl;
}