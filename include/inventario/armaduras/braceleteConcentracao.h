#ifndef BRACELETE_CONCENTRACAO_H
#define BRACELETE_CONCENTRACAO_H

#include "inventario/armaduras/armadura.h"

class BraceleteConcentracao : public Armadura {
public:
    BraceleteConcentracao() : Armadura("Bracelete de Concentração", "Reduz custo de magia pela metade por 2 turnos.") {}

    void aplicarEfeito(Personagem& alvo) override {
        BuffTemporario buff;
        buff.tipo = "reducao_custo_magia";
        buff.valor = 0.5f;  
        buff.duracao = 2;   
        alvo.adicionarBuff(buff);

        cout << alvo.getNome() << " terá redução de custo de magia por 2 turnos graças ao Bracelete de Concentração!" << endl;
    }
};

#endif
