#include "missoes/missao.h"

void Missao::iniciar() {
    cout << "\nIniciando missao: " << titulo << endl;
    this->estado = EstadoMissao::ATIVA;
}

Recompensa Missao::completar(Personagem& jogador) {
    cout << "\nMissao concluida: " << titulo << "!" << endl;
    cout << "Recompensa: " << recompensa.xp << " de XP." << endl;
    jogador.ganharXP(recompensa.xp);
    this->estado = EstadoMissao::COMPLETA;
    return recompensa;
}

void Missao::mostrarProgresso() const {
    cout << "\n[" << titulo << "]" << endl;
    for (const auto& obj : objetivos) {
        cout << "- " << obj.descricao << " [" << (obj.concluido ? "✓" : " ") << "]" << endl;
    }
}

 void Missao::resetar() {
        cout << "A missão '" << titulo << "' pode ser tentada novamente." << endl;
        this->estado = EstadoMissao::PENDENTE;
        // Reseta o progresso dos objetivos também
        for (auto& obj : objetivos) {
            obj.concluido = false;
        }
}