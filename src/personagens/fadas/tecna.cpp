#include "personagens/fadas/tecna.h"
#include "habilidades/danoDireto/raioDeEnergia.h"
#include "habilidades/danoContinuo/curtoCircuito.h"
#include "habilidades/nivelAlto/firewallDigital.h" 

Tecna::Tecna() : Personagem("Tecna", 105, 90, 55, 70, 68) {
    // Caracteristica: defesa alta e ataques que ignoram defesas
    // Status: Vida, Magia, Defesa, Ataque Mágico, Velocidade

    habilidades.push_back(new RaioDeEnergia());
    habilidades.push_back(new CurtoCircuito());
}

bool Tecna::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Tecna::checarDesbloqueioHabilidades() {
    // No Nível 5, Tecna cria um programa de defesa e ataque perfeito.
    if (getNivel() >= 5 && !temHabilidade("Firewall Digital")) {
        habilidades.push_back(new FirewallDigital());
        cout << getNome() << " otimizou seus algoritmos e desbloqueou: Firewall Digital!" << endl;
    }
}