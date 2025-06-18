#include "bloom.h"
#include "chamaDoDragao.h"
#include "chamasPersistentes.h"
#include "furiaDoDragao.h" 

Bloom::Bloom() : Personagem("Bloom", 90, 110, 35, 80, 70) {
    // Caracteristicas: Maior Ataque Mágico, mas baixa defesa e vida

    // Habilidades iniciais
    habilidades.push_back(new ChamaDoDragao());
    habilidades.push_back(new ChamasPersistentes());
}

bool Bloom::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Bloom::checarDesbloqueioHabilidades() {
    // No Nível 5, Bloom libera seu poder supremo
    if (getNivel() >= 5 && !temHabilidade("Fúria do Dragão")) {
        habilidades.push_back(new FuriaDoDragao());
        cout << getNome() << " sentiu o poder ancestral e desbloqueou: Fúria do Dragão!" << endl;
    }
}