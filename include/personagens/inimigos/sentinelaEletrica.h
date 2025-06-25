#ifndef SENTINELAELETRICA_H
#define SENTINELAELETRICA_H

#include "personagens/inimigo.h"

class SentinelaEletrica : public Inimigo {
public:
    SentinelaEletrica();
    ~SentinelaEletrica() override = default;
};

#endif