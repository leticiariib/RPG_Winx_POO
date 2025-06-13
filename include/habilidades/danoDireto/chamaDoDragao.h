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
    int dano = dano_base + atacante.getAtaque() * 0.5;
    int defesa_reduzida = alvo.getDefesa() * 0.7; 
    int final = dano - defesa_reduzida;
    if (final < 0) final = 0;

    alvo.receberDano(final);
    cout << atacante.getNome() << " lançou Chama do Dragão causando " << final
        << " de dano em " << alvo.getNome() << ".\n"; 
}

#endif