#include "habilidades/nivelAlto/furiaDoDragao.h"
#include "personagens/personagem.h"
#include <iostream>

FuriaDoDragao::FuriaDoDragao()
    : Habilidade("Fúria do Dragão", 80, 50) {} 

void FuriaDoDragao::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.8; 
    float dano_final = dano - (alvo.getDefesa() * 0.5);  

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " liberou a Fúria do Dragão, causando "
         << dano_final << " de dano massivo em " << alvo.getNome() << "!\n";
}

void FuriaDoDragao::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Dano Direto (Fogo)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Libera o poder máximo da Chama do Dragão. Causa dano massivo e ignora parte da defesa." << endl;
}