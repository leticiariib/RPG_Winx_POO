#ifndef INIMIGO_H
#define INIMIGO_H

#include "personagens/personagem.h"

class Inimigo : public Personagem {
public:
    using Personagem::Personagem; 
    virtual ~Inimigo() = default;
};

#endif