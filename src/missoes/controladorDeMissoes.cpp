#include "missoes/controladorDeMissoes.h"
#include <iostream>

using namespace std; 

ControladorDeMissoes::~ControladorDeMissoes() {
    for (auto const& [id, missao] : missoes) {
        delete missao;
    }
    missoes.clear();
}

void ControladorDeMissoes::adicionarMissao(Missao* novaMissao) {
    if (novaMissao) {
        missoes[novaMissao->getID()] = novaMissao;
    }
}

void ControladorDeMissoes::mostrarMissoesDisponiveis() const {
    cout << "\n--- Quadro de Missões Disponíveis ---" << endl;
    bool nenhumaDisponivel = true;
    for (auto const& [id, missao] : missoes) {
        if (missao->getEstado() == EstadoMissao::PENDENTE) {
            cout << "[" << id << "] " << missao->getTitulo() << (missao->isPrincipal() ? " (Principal)" : " (Secundária)") << endl;
            nenhumaDisponivel = false;
        }
    }
    if (nenhumaDisponivel) {
        cout << "Nenhuma nova missão disponível no momento." << endl;
    }
}

void ControladorDeMissoes::mostrarMissoesAtivas() const {
    cout << "\n--- Diário de Missões Ativas ---" << endl;
     bool nenhumaAtiva = true;
    for (auto const& [id, missao] : missoes) {
        if (missao->getEstado() == EstadoMissao::ATIVA) {
            missao->mostrarProgresso();
            nenhumaAtiva = false;
        }
    }
     if (nenhumaAtiva) {
        cout << "Nenhuma missão ativa no momento." << endl;
    }
}

Missao* ControladorDeMissoes::getMissao(int id) {
    if (missoes.count(id)) {
        return missoes[id];
    }
    return nullptr;
}