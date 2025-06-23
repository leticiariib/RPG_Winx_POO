#ifndef MISSAO_SUSSURROSNABIBLIOTECA_H
#define MISSAO_SUSSURROSNABIBLIOTECA_H

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_SussurrosNaBiblioteca : public MissaoPrincipal {
public:
    Missao_SussurrosNaBiblioteca();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif