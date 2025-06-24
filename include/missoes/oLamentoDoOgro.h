#ifndef O_LAMENTO_DO_OGRO_H
#define O_LAMENTO_DO_OGRO_H

#include "missoes\missao.h"
#include "inventario\inventario.h"
#include "inventario\pocoes\pocoes.h"
#include "inventario\armaduras\armadura.h"

class Missao_oLamentoDoOgro : public MissaoSecundaria {
public:
    Missao_oLamentoDoOgro();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
};

#endif