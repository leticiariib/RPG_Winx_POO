#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <iostream>
#include <string>
#include "personagem.h"

using namespace std;

class Habilidade{
    protected:
        string nome;
        float dano_base;
        float custo_mana;
    public:
        Habilidade(string n, float d, float cm)
            : nome{n}, dano_base{d}, custo_mana{cm} {}
       
        virtual void aplicar(Personagem& atacante, Personagem& alvo) = 0;
       
        string getNome() const {return nome;}
        float getCusto() const {return custo_mana;} //verificar se tem mana sufuciente
};

#endif
