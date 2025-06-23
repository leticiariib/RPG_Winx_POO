#ifndef ECOS_DE_CORRUPCAO
#define ECOS_DE_CORRUPCAO

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_EcosDaCorrupcao : public MissaoPrincipal {
public:
    Missao_EcosDaCorrupcao();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif