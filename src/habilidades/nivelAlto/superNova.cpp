#include "supernova.h"
#include <iostream>

Supernova::Supernova()
    : Habilidade("Supernova", 75, 45) {} // Dano alto, custo alto

void Supernova::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.7;
    float dano_final = dano - (alvo.getDefesa() * 0.3); // Ignora um pouco de defesa

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    // Em um jogo mais complexo, aqui poderia aplicar um debuff de "cegueira" ou "redução de defesa"
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