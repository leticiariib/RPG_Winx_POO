#ifndef MISSAO_GIGANTEENFURECIDO_H
#define MISSAO_GIGANTEENFURECIDO_H

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_GiganteEnfurecido : public MissaoSecundaria {
public:
    Missao_GiganteEnfurecido();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif