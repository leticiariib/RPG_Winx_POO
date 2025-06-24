#ifndef MONSTRODOPESADELO_H
#define MONSTRODOPESADELO_H

#include "personagens/inimigo.h"

class MonstroDoPesadelo : public Inimigo {
public:
    MonstroDoPesadelo();
    ~MonstroDoPesadelo() override = default;
};

#endif