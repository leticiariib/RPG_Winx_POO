#ifndef AISHA_H
#define AISHA_H

#include "personagem.h"

class Aisha : public Personagem {
private:
    void checarDesbloqueioHabilidades() override;
    bool temHabilidade(const string& nomeHabilidade) const;

public:
    Aisha();
    ~Aisha() override = default;
};
#endif