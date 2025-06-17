#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <iostream>
#include <string>
#include "personagem.h"

using namespace std;

class Habilidade {
protected:
    string nome;
    float dano_base;
    float custo_magia;

public:
    Habilidade(string n, float d, float cm);

    virtual void aplicar(Personagem& atacante, Personagem& alvo) = 0;
    virtual void mostrarDetalhes() const = 0;

    string getNome() const;
    float getCusto() const;
};

#endif
