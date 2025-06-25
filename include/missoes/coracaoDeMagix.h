#ifndef CORACAO_DE_MAGIX_H
#define CORACAO_DE_MAGIX_H

#include "missoes/missao.h"
#include "inventario/inventario.h"
#include "inventario/pocoes/pocoes.h"
#include "inventario/armaduras/armadura.h"

// A missão final da saga
class Missao_CoracaoDeMagix : public MissaoPrincipal {
public:
    Missao_CoracaoDeMagix();

    void executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);

private:
    // Uma função auxiliar para a fase de cura entre as batalhas
    void faseDePreparacao(Personagem& fadaEscolhida, Inventario<Pocao*>& invP);
};

#endif