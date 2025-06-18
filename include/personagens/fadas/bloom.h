#ifndef BLOOM_H
#define BLOOM_H

#include "personagem.h"

class Bloom : public Personagem {
private:
    void checarDesbloqueioHabilidades() override; 
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Bloom();
    ~Bloom() override = default;
};

#endif