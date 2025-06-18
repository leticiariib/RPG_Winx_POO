#ifndef GHOUL_H
#define GHOUL_H

#include "inimigo.h"

class Ghoul : public Inimigo {
public:
    Ghoul();
    ~Ghoul() override = default;
};

#endif