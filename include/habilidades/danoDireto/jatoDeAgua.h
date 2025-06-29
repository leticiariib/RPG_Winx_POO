#ifndef JATO_DE_AGUA_H
#define JATO_DE_AGUA_H

#include "habilidades/habilidade.h"
class Personagem;

class JatoDeAgua : public Habilidade {
public:
    JatoDeAgua();
    void aplicar(Personagem& atacante, Personagem& alvo) override;
    virtual void mostrarDetalhes() const override;
};

#endif