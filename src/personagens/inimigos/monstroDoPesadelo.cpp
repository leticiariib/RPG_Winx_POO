#include "personagens/inimigos/monstroDoPesadelo.h"
#include "habilidades/danoContinuo/rajadaSombria.h"
#include "habilidades/danoDireto/sombraDoMedo.h"

MonstroDoPesadelo::MonstroDoPesadelo()
    // caracteristicas: Vida e ataque medianos, mas rápido para aplicar seus efeitos.
    : Inimigo("Monstro do Pesadelo", 95, 80, 35, 55, 65) {
    
    this->nivel = 8;
    habilidades.push_back(new RajadaSombria());
    habilidades.push_back(new SombraDoMedo());
}