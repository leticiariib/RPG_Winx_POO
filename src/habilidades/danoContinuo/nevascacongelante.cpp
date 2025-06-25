#include "habilidades/danoContinuo/nevascaCongelante.h"
#include "personagens/personagem.h"
#include <iostream>

NevascaCongelante::NevascaCongelante()
    : Habilidade("Nevasca Congelante", 10, 20) {}

void NevascaCongelante::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano_por_turno = dano_base + atacante.getAtaque() * 0.2f;

    EfeitoContinuo efeito = {"dano de gelo", dano_por_turno, 3};
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " conjurou uma Nevasca Congelante! "
         << alvo.getNome() << " sofrerá " << dano_por_turno << " de dano por 3 turnos.\n";
}

void NevascaCongelante::mostrarDetalhes() const {
    cout << "- " << nome << " - Dano Contínuo (Gelo)" << endl;
}