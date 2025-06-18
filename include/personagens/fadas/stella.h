#ifndef STELLA_H
#define STELLA_H

#include "personagem.h"

class Stella : public Personagem {
private:
    void checarDesbloqueioHabilidades() override;
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Stella();
    ~Stella() override = default;
};
#endif