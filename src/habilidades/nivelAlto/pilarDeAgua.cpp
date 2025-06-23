#include "habilidades/nivelAlto/pilarDeAgua.h"
#include <iostream>

PilarDeAgua::PilarDeAgua()
    : Habilidade("Pilar de Água", 70, 48) {}

void PilarDeAgua::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.6;
    float dano_final = dano - alvo.getDefesa();

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    alvo.reduzirVelocidade(25); 

    cout << atacante.getNome() << " conjurou um Pilar de Água, causando " << dano_final
         << " de dano e reduzindo drasticamente a velocidade de " << alvo.getNome() << "!\n";
}

void PilarDeAgua::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Dano Direto (Água)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um pilar de água pressurizada atinge o alvo, causando alto dano e forte redução de velocidade." << endl;
}