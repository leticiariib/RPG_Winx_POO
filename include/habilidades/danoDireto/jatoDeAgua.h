#ifndef JATO_DE_AGUA_H
#define JATO_DE_AGUA_H

#include "habilidade.h"

class JatoDeAgua : public Habilidade {
public:
    JatoDeAgua();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
};

#endif