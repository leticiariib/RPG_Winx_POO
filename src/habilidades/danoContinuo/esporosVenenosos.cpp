#include "esporosVenenosos.h"
#include <iostream>

EsporosVenenosos::EsporosVenenosos()
    : Habilidade("Esporos Venenosos", 25, 12) {}

void EsporosVenenosos::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 8 + atacante.getAtaque() * 0.15;

    EfeitoContinuo efeito = {"dano por veneno", dano, 3};  
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " lançou Esporos Venenosos. "
         << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
}

void EsporosVenenosos::mostrarDetalhes() const {
    cout << "- " << nome << " -" << endl;
    cout << "Tipo: Dano Contínuo (Natureza/Veneno)" << endl;
    cout << "Dano base por turno: 8" << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Duração: 3 turnos" << endl;
    cout << "Descrição: Lança uma nuvem de esporos que envenenam o alvo, causando dano constante." << endl;
}