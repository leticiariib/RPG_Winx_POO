#ifndef CHEFE_H
#define CHEFE_H

#include "inimigo.h"

//tipo especial de inimigo : + forte
class Chefe : public Inimigo {
public:
    using Inimigo::Inimigo;
    virtual ~Chefe() = default;
};

#endif