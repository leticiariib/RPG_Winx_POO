#include "supernova.h"
#include <iostream>

Supernova::Supernova()
    : Habilidade("Supernova", 75, 45) {}

void Supernova::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.7;
    float dano_final = dano - (alvo.getDefesa() * 0.3); 

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);

    cout << atacante.getNome() << " criou uma Supernova, causando " << dano_final
         << " de dano de luz ofuscante em " << alvo.getNome() << "!\n";
}

void Supernova::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Dano Direto (Luz)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Uma explosão de luz tão forte quanto um sol, causando dano devastador." << endl;
}