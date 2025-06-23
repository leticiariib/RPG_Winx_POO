#ifndef STORMY_H
#define STORMY_H

#include "personagens/chefe.h"

class Stormy : public Chefe {
public:
    Stormy();
    ~Stormy() override = default;
};

#endif