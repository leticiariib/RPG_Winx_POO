#include "musa.h"
#include "ondaSonora.h"
#include "redemoinho.h"
#include "crescendoEstilhacante.h" 
Musa::Musa() : Personagem("Musa", 95, 105, 30, 75, 85) {
    // caract.: A mais rápida, ataca primeiro mas é frágil.

    // Habilidades iniciais
    habilidades.push_back(new OndaSonora());
    habilidades.push_back(new Redemoinho());
}

bool Musa::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Musa::checarDesbloqueioHabilidades() {
    // No Nível 4, Musa aprende a criar uma onda sonora devastadora.
    if (getNivel() >= 4 && !temHabilidade("Crescendo Estilhaçante")) {
        habilidades.push_back(new CrescendoEstilhacante());
        cout << getNome() << " atingiu a nota perfeita e desbloqueou: Crescendo Estilhaçante!" << endl;
    }
}