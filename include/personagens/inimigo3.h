#ifndef INIMIGO3_H
#define INIMIGO3_H

#include "personagem.h"

class Stormy : public Personagem {
public:
    Stormy() : Personagem("Stormy", 110, 70.0f, 30.0f, 12.0f) {}

    void mostarStatus() const override {
        cout << "Inimiga - ";
        Personagem::mostarStatus();
    }
};

#endif
