#include "habilidades/nivelAlto/furacaoDestruidor.h"
#include <iostream>

FuracaoDestruidor::FuracaoDestruidor()
    : Habilidade("Furacão Destruidor", 75, 48) {}

void FuracaoDestruidor::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.8f;
    float dano_final = dano - (alvo.getDefesa() * 0.4f);
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " criou um Furacão Destruidor, causando "
         << dano_final << " de dano massivo em " << alvo.getNome() << "!\n";
}

void FuracaoDestruidor::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano Direto com Perfuração (Vento)" << endl;
}