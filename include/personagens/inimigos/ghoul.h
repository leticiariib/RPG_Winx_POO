#ifndef GHOUL_H
#define GHOUL_H

#include "inimigo.h"

//inimigo p/ inicio do jogo

class Ghoul : public Inimigo {
public:
    Ghoul();
    ~Ghoul() override = default;
};

#endif