#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "personagens/personagem.h"
using namespace std;

class Item {
    public:
        virtual string getNome() const = 0;
        virtual void mostrarInfo() const = 0;
        virtual void aplicarEfeito(Personagem& alvo) = 0;  
        virtual ~Item() {}
};

#endif
