#ifndef INIMIGO2_H
#define INIMIGO2_H

#include "personagem.h"

class Darcy : public Personagem {
public:
    Darcy() : Personagem("Darcy", 90, 100.0f, 20.0f, 10.0f) {}

    void mostarStatus() const override {
        cout << "Inimiga - ";
        Personagem::mostarStatus();
    }
};

#endif
