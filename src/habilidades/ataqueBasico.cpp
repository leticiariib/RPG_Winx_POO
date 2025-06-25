#include "habilidades\ataqueBasico.h"
#include "personagens\personagem.h"
#include <iostream>

using namespace std; 

AtaqueBasico::AtaqueBasico()
    : Habilidade("Ataque Básico", 5, 0) {} // Dano base muito baixo, CUSTO ZERO

void AtaqueBasico::aplicar(Personagem& atacante, Personagem& alvo) {
    // dano que escala muito pouco, para que habilidades de verdade sejam sempre melhores.
    float dano = dano_base + atacante.getAtaque() * 0.15f; 
    float dano_final = dano - (alvo.getDefesa() * 0.7f); 
    // garante que o ataque sempre cause pelo menos seu dano base (5).
    if (dano_final < dano_base) {
        dano_final = dano_base;
    }

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " usa um Ataque Básico, causando "
              << dano_final << " de dano em " << alvo.getNome() << ".\n";
}

void AtaqueBasico::mostrarDetalhes() const {
    cout << "- " << nome << " -" << endl;
    cout << "Tipo: Dano Direto (Comum)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um disparo de energia simples." << endl;
}