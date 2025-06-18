#include "missao.h"

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