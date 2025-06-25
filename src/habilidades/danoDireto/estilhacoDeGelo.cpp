#include "habilidades/danoDireto/estilhacoDeGelo.h"
#include "personagens/personagem.h"
#include <iostream>

EstilhacoDeGelo::EstilhacoDeGelo()
    : Habilidade("Estilhaço de Gelo", 35, 16) {}

void EstilhacoDeGelo::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = dano_base + atacante.getAtaque() * 0.3;
    int defesa_reduzida = alvo.getDefesa() * 0.5;  // Redução maior da defesa, como se "perfurasse"
    int final = dano - defesa_reduzida;

    if (final < 0) final = 0;

    alvo.receberDano(final);

    std::cout << atacante.getNome() << " lançou Estilhaço de Gelo causando "
              << final << " de dano em " << alvo.getNome() << ".\n";
}

void EstilhacoDeGelo::mostrarDetalhes() const {
    cout << "- " << nome << " - " << endl;
    cout << "Tipo: Dano Direto (Gelo)" << endl;
    cout << "Dano base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Um ataque de gelo que perfura 50% da defesa do alvo." << endl;
}