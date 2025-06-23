#ifndef MONSTRO_DO_PANTANO_H
#define MONSTRO_DO_PANTANO_H

#include "personagens/inimigo.h"

//inimigo p/ inicio do jogo
class MonstroDoPantano : public Inimigo {
public:
    MonstroDoPantano();
    ~MonstroDoPantano() override = default;
};

#endif