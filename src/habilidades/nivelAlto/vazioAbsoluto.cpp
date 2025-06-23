#include "habilidades/nivelAlto/vazioAbsoluto.h"
#include <iostream>

VazioAbsoluto::VazioAbsoluto()
    : Habilidade("Vazio Absoluto", 70, 50) {} 

void VazioAbsoluto::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.6f;
    float dano_final = dano - alvo.getDefesa();
    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    
    // roubo de vida funcionara assim: Darcy se cura em 50% do dano causado
    float cura = dano_final * 0.5f;
    atacante.recuperarVida(cura);

    cout << atacante.getNome() << " criou um Vazio Absoluto sobre " << alvo.getNome() << "!\n"
         << "Causou " << dano_final << " de dano e drenou " << cura << " de vida para si mesma.\n";
}

void VazioAbsoluto::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano com Roubo de Vida (Sombra)" << endl;
}