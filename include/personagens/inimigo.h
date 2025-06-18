#ifndef INIMIGO_H
#define INIMIGO_H

#include "personagem.h"

class Inimigo : public Personagem {
public:
    using Personagem::Personagem; 
    virtual ~Inimigo() = default;
};

#endif