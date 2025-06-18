#include <iostream>
#include "jatoDeAgua.h"

JatoDeAgua::JatoDeAgua()
    : Habilidade("Jato de Agua", 35, 15) {}

void JatoDeAgua::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = dano_base + atacante.getAtaque() * 0.5;
    int final = dano - alvo.getDefesa();

    if (final < 0) final = 0;

    alvo.receberDano(final);

    cout << atacante.getNome() << " lançou Jato de Água causando "
         << final << " de dano direto.\n";
}

void JatoDeAgua::mostrarDetalhes() const {
    cout << "- " << nome << " - " << endl;
    cout << "Tipo: Dano Direto (Água)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um jato de água potente que duplica o ataque do usuário." << endl;
}
