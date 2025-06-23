#include "habilidades/danoContinuo/curtoCircuito.h"
#include <iostream>

CurtoCircuito::CurtoCircuito()
    : Habilidade("Curto-Circuito", 13, 17) {}

void CurtoCircuito::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano_por_turno = dano_base + atacante.getAtaque() * 0.25;

    EfeitoContinuo efeito = {"dano elétrico", dano_por_turno, 3};
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " causou um Curto-Circuito em " << alvo.getNome() << ". "
         << "O alvo sofrerá " << dano_por_turno << " de dano elétrico por 3 turnos.\n";
}

void CurtoCircuito::mostrarDetalhes() const {
    cout << "- " << nome << " - " << endl;
    cout << "Tipo: Dano Contínuo (Elétrico)" << endl;
    cout << "Dano base por turno: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Sobrecarrega o alvo com energia, causando dano elétrico contínuo por 3 turnos." << endl;
}