#include "habilidades/danoContinuo/rajadaSombria.h"
#include <iostream>

RajadaSombria::RajadaSombria()
    : Habilidade("Rajada Sombria", 28, 16) {}

void RajadaSombria::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 10 + atacante.getAtaque() * 0.2;

    EfeitoContinuo efeito = {"dano de escuridao", dano, 3};  // 3 turnos de dano sombrio
    alvo.aplicarEfeito(efeito);

    std::cout << atacante.getNome() << " lançou Rajada Sombria. "
              << alvo.getNome() << " sofrerá " << dano << " de dano sombrio por 3 turnos.\n";
}

void RajadaSombria::mostrarDetalhes() const {
    cout << "- " << nome << " -" << endl;
    cout << "Tipo: Dano Contínuo (Sombra)" << endl;
    cout << "Dano base por turno: 10" << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Duração: 3 turnos" << endl;
    cout << "Descrição: Ataca o alvo com energia sombria que permanece, causando dano ao longo do tempo." << endl;
}