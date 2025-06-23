#include "habilidades/nivelAlto/fortificar.h"
#include <iostream>

Fortificar::Fortificar()
    : Habilidade("Fortificar", 0, 10) {} 

void Fortificar::aplicar(Personagem& atacante, Personagem& alvo) {
    atacante.aumentarDefesaTemporaria(0.50f, 3); // Aumenta a defesa em 50% por 3 turnos

    std::cout << atacante.getNome() << " usou Fortificar, tornando sua couraça de pedra ainda mais resistente!\n";
}

void Fortificar::mostrarDetalhes() const {
    std::cout << "- " << nome << " - Buff de Defesa" << std::endl;
}