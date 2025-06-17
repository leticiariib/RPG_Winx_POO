#include "rajadaSombria.h"
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
