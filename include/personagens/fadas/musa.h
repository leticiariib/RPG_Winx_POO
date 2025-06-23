#ifndef MUSA_H
#define MUSA_H

#include "personagens/personagem.h"

class Musa : public Personagem {
private:
    void checarDesbloqueioHabilidades() override;
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Musa();
    ~Musa() override = default;
};
#endif