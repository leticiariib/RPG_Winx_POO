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
