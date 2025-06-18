#include "aisha.h"
#include "mareAscendente.h"
#include "jatoDeAgua.h"       
#include "pilarDeAgua.h"      // Habilidade de Nível Alto

Aisha::Aisha() : Personagem("Aisha", 110, 95, 40, 68, 75) {
    // Caracteristicas: Bons status ofensivos e velocidade

    habilidades.push_back(new MareAscendente());
    habilidades.push_back(new JatoDeAgua());
}

bool Aisha::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Aisha::checarDesbloqueioHabilidades() {
    // No Nível 4, Aisha domina o controle da água para um ataque devastador.
    if (getNivel() >= 4 && !temHabilidade("Pilar de Água")) {
        habilidades.push_back(new PilarDeAgua());
        cout << getNome() << " dominou as marés e desbloqueou: Pilar de Água!" << endl;
    }
}