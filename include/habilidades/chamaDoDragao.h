#ifndef CHAMA_DO_DRAGA0_H
#define CHAMA_DO_DRAGAO_H

#include "habilidade.h"

class ChamaDoDragao : public Habilidade{
    public: 
        ChamaDoDragao(); 
        void aplicar(Personagem& atacante, Personagem& alvo) override; 
};

ChamaDoDragao::ChamaDoDragao()
   : Habilidade("Chama do Dragao", 40, 20) {}

void ChamaDoDragao::aplicar(Personagem& atacante, Personagem& alvo){
    int dano = dano_base + atacante.getAtaqueMagico()*0.5; 
    int defesa_reduzida =  alvo.getDefesa()*0.7;
    int dano_final = dano - defesa_reduzida; 
    alvo.receberDano(dano_final); 
}

#endif