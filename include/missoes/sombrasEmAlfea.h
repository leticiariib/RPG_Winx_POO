#ifndef MISSAO_SOMBRAS_EM_AFEA_H
#define MISSAO_SOMBRAS_EM_AFEA_H

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_SombrasEmAlfea : public MissaoPrincipal {
public:
    Missao_SombrasEmAlfea();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif