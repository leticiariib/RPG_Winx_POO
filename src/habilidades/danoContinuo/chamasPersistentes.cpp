#include "chamasPersistentes.h"
#include <iostream>

ChamasPersistentes::ChamasPersistentes()
    : Habilidade("Chamas Persistentes", 30, 18) {}

void ChamasPersistentes::aplicar(Personagem& atacante, Personagem& alvo) {
    int dano = 12 + atacante.getAtaque() * 0.25;

    EfeitoContinuo efeito = {"dano por queimadura", dano, 3}; 
    alvo.aplicarEfeito(efeito);

    cout << atacante.getNome() << " lançou Chamas Persistentes. "
         << alvo.getNome() << " sofrerá " << dano << " de dano por 3 turnos.\n";
}

void ChamasPersistentes::mostrarDetalhes() const {
    cout << "- " << nome << " -" << endl;
    cout << "Tipo: Dano Contínuo (Fogo)" << endl;
    cout << "Dano base por turno: 12" << endl; // Reflete o valor usado na função aplicar
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Duração: 3 turnos" << endl;
    cout << "Descrição: Envolve o alvo em chamas que causam dano de queimadura ao longo do tempo." << endl;
}
