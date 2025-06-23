#ifndef DARCY_H
#define DARCY_H

#include "personagens/chefe.h"

class Darcy : public Chefe {
public:
    Darcy();
    ~Darcy() override = default;
};

#endif