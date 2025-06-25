#include "missoes/controladorDeMissoes.h"
#include <iostream>

ControladorDeMissoes::~ControladorDeMissoes() {
    for (auto const& par : missoes) {
        delete par.second;
    }
    missoes.clear();
}

void ControladorDeMissoes::adicionarMissao(Missao* novaMissao) {
    if (novaMissao) {
        missoes[novaMissao->getID()] = novaMissao;
    }
}

void ControladorDeMissoes::mostrarMissoesDisponiveis() const {
    std::cout << "\n--- Quadro de Missões Disponíveis ---" << std::endl;
    bool nenhumaDisponivel = true;
    
    for (auto const& par : missoes) {
        int id = par.first;
        Missao* missao = par.second;

        if (missao->getEstado() == EstadoMissao::PENDENTE) {
            std::cout << "[" << id << "] " << missao->getTitulo() << (missao->isPrincipal() ? " (Principal)" : " (Secundária)") << std::endl;
            nenhumaDisponivel = false;
        }
    }

    if (nenhumaDisponivel) {
        std::cout << "Nenhuma nova missão disponível no momento." << std::endl;
    }
}

void ControladorDeMissoes::mostrarMissoesAtivas() const {
    std::cout << "\n--- Diário de Missões Ativas ---" << std::endl;
    bool nenhumaAtiva = true;

    for (auto const& par : missoes) {
        Missao* missao = par.second;

        if (missao->getEstado() == EstadoMissao::ATIVA) {
            missao->mostrarProgresso();
            nenhumaAtiva = false;
        }
    }

    if (nenhumaAtiva) {
        std::cout << "Nenhuma missão ativa no momento." << std::endl;
    }
}

Missao* ControladorDeMissoes::getMissao(int id) {
    auto it = missoes.find(id);
    if (it != missoes.end()) {
        return it->second;
    }
    return nullptr;
}