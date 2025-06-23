#include "missoes/controladorDeMissoes.h"
#include <iostream>

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
    std::cout << "\n--- Quadro de Missões Disponíveis ---" << std::endl;
    bool nenhumaDisponivel = true;
    for (auto const& [id, missao] : missoes) {
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
    for (auto const& [id, missao] : missoes) {
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
    if (missoes.count(id)) {
        return missoes[id];
    }
    return nullptr;
}