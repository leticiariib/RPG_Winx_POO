#ifndef KNUT_H
#define KNUT_H

#include "personagens\inimigo.h" //inimigo especial 

class Knut : public Inimigo {
public:
    Knut();
    ~Knut() override = default;
};

#endif