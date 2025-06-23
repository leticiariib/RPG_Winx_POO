#ifndef FLORA_H
#define FLORA_H

#include "personagens/personagem.h"

class Flora : public Personagem {
private:
    void checarDesbloqueioHabilidades() override;
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Flora();
    ~Flora() override = default;
};
#endif