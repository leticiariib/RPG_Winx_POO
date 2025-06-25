#include "habilidades/danoContinuo/redemoinho.h"
#include "personagens/personagem.h"
#include <iostream>

Redemoinho::Redemoinho()
    : Habilidade("Redemoinho", 35, 15) {}

void Redemoinho::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 10 + atacante.getAtaque() * 0.2;

    EfeitoContinuo efeito = {"dano de escuridao", dano, 3};
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " lançou Redemoinho. "
         << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
}

void Redemoinho::mostrarDetalhes() const {
    cout << "- " << nome << " -" << endl;
    cout << "Tipo: Dano Contínuo (Vento)" << endl;
    cout << "Dano base por turno: 10" << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Duração: 3 turnos" << endl;
    cout << "Descrição: Cria um redemoinho cortante ao redor do alvo que causa dano a cada turno." << endl;
}