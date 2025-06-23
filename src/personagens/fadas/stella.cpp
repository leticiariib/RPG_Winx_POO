#include "personagens/fadas/stella.h"
#include "habilidades/danoContinuo/rajadaSombria.h"
#include "habilidades/danoDireto/raioDeEnergia.h"
#include "habilidades/nivelAlto/superNova.h" // Habilidade de Nível Alto

Stella::Stella() : Personagem("Stella", 100, 100, 45, 65, 65) {
    // Caracteristica: status bem distribuídos, sem pontos fracos.

    // Habilidades iniciais
    habilidades.push_back(new RajadaSombria());
    habilidades.push_back(new RaioDeEnergia());
}

bool Stella::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Stella::checarDesbloqueioHabilidades() {
    // No Nível 4, Stella aprende a concentrar seu poder em uma grande explosão.
    if (getNivel() >= 4 && !temHabilidade("Supernova")) {
        habilidades.push_back(new Supernova());
        cout << getNome() << " aprendeu a brilhar intensamente e desbloqueou: Supernova!" << endl;
    }
}