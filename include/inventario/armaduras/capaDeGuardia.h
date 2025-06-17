#ifndef CAPA_DE_GUARDIA_H
#define CAPA_DE_GUARDIA_H

#include "armadura.h"

class CapaDaGuardia : public Armadura {
    public:
        CapaDaGuardia() : Armadura("Capa da Guardiã", "Reduz dano recebido em 20% enquanto equipado.") {}
        void aplicarEfeito(Personagem& alvo) override{
             alvo.adicionarReducaoDeDano(0.2); 
        }
};

#endif