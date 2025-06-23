#include "monstroDoPesadelo.h"
#include "rajadaSombria.h"
#include "sombraDoMedo.h"

MonstroDoPesadelo::MonstroDoPesadelo()
    // caracteristicas: Vida e ataque medianos, mas rápido para aplicar seus efeitos.
    : Inimigo("Monstro do Pesadelo", 140, 80, 35, 55, 65) {
    
    this->nivel = 8;
    habilidades.push_back(new RajadaSombria());
    habilidades.push_back(new SombraDoMedo());
}