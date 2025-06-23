#ifndef GOLEMDEPEDRA_H
#define GOLEMDEPEDRA_H

#include "personagens/inimigo.h"

class GolemDePedra : public Inimigo {
public:
    GolemDePedra();
    ~GolemDePedra() override = default;
};

#endif