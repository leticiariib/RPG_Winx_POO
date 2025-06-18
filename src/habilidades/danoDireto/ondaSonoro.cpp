#include "ondaSonora.h"
#include <iostream>

OndaSonora::OndaSonora()
    : Habilidade("Onda Sonora", 42, 20) {}

void OndaSonora::aplicar(Personagem& atacante, Personagem& alvo) {
    // Dano sonoro que não é muito afetado pela defesa física
    float dano = dano_base + atacante.getAtaque() * 0.5;
    float dano_final = dano - (alvo.getDefesa() * 0.5); // Ignora 50% da defesa

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " disparou uma Onda Sonora, causando "
         << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void OndaSonora::mostrarDetalhes() const {
    cout << "- " << nome << " - " << endl;
    cout << "Tipo: Dano Direto (Som)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um ataque sônico poderoso que ignora metade da defesa do alvo." << endl;
}