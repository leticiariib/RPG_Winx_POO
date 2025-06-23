#ifndef TECNA_H
#define TECNA_H

#include "personagens/personagem.h"

class Tecna : public Personagem {
private:
    void checarDesbloqueioHabilidades() override;
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Tecna();
    ~Tecna() override = default;
};
#endif