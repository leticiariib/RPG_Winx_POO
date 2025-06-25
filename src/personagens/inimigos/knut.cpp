#include "personagens\inimigos\knut.h"
#include "habilidades\danoDireto\clavaEsmagadora.h"

Knut::Knut()
    // caracteristicas de Mini-Chefe: Vida e Ataque altos, Defesa decente, mas lento.
    : Inimigo("Knut, o Ogro", 140, 20, 50, 55, 40) {

    this->nivel = 5;
    habilidades.push_back(new ClavaEsmagadora());
}