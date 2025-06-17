#include "habilidade.h"

Habilidade::Habilidade(string n, float d, float cm)
    : nome{n}, dano_base{d}, custo_magia{cm} {}

string Habilidade::getNome() const {
    return nome;
}

float Habilidade::getCusto() const {
    return custo_magia;
}
