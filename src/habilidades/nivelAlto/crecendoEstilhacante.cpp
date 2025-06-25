#include "habilidades/nivelAlto/crescendoEstilhacante.h"
#include "personagens/personagem.h"
#include <iostream>

CrescendoEstilhacante::CrescendoEstilhacante()
    : Habilidade("Crescendo Estilhaçante", 72, 45) {}

void CrescendoEstilhacante::aplicar(Personagem& atacante, Personagem& alvo) {
    float dano = dano_base + atacante.getAtaque() * 0.75;
    float dano_final = dano - (alvo.getDefesa() * 0.4); 

    if (dano_final < 0) dano_final = 0;

    alvo.receberDano(dano_final);
    cout << atacante.getNome() << " liberou um Crescendo Estilhaçante, causando "
         << dano_final << " de dano sônico que perfura a armadura de " << alvo.getNome() << "!\n";
}

void CrescendoEstilhacante::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Dano Direto (Som)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Uma onda sonora de frequência altíssima que ignora a maior parte da defesa inimiga." << endl;
}