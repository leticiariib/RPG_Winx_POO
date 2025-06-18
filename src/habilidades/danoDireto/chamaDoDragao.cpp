#include <iostream>
#include "chamaDoDragao.h"

ChamaDoDragao::ChamaDoDragao()
    : Habilidade("Chama do Dragao", 40, 20) {}

void ChamaDoDragao::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = dano_base + atacante.getAtaque() * 0.5;
    int defesa_reduzida = alvo.getDefesa() * 0.7;
    int final = dano - defesa_reduzida;

    if (final < 0) final = 0;

    alvo.receberDano(final);

    cout << atacante.getNome() << " lançou Chama do Dragão causando "
         << final << " de dano em " << alvo.getNome() << ".\n";
}

void ChamaDoDragao::mostrarDetalhes() const {
    cout << "- " << nome << " - " << endl;
    cout << "Tipo: Dano Direto (Fogo)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um poderoso ataque de fogo que ignora parte da defesa inimiga." << endl;
}
