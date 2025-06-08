#ifndef INIMIGO1_H
#define INIMIGO1_H

#include "personagem.h"

class Icy : public Personagem {
public:
    Icy() : Personagem("Icy", 100, 80.0f, 25.0f, 15.0f) {}

    void mostarStatus() const override { //sobrescreve o nome 
        cout << "Inimiga - ";
        Personagem::mostarStatus();
    }
};

#endif
