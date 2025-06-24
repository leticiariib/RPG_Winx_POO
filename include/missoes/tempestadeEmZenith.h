#ifndef MISSAO_TEMPESTADE_EM_ZENITH_H
#define MISSAO_TEMPESTADE_EM_ZENITH_H

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_TempestadeEmZenith : public MissaoPrincipal {
public:
    Missao_TempestadeEmZenith();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif