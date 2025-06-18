#include "firewallDigital.h"
#include <iostream>

FirewallDigital::FirewallDigital()
    // É uma habilidade de buff, o "dano base" não será usado para dano
    : Habilidade("Firewall Digital", 0, 35) {}

void FirewallDigital::aplicar(Personagem& atacante, Personagem& alvo) {
    // Esta habilidade aplica um buff em si mesma 
    atacante.aumentarDefesaTemporaria(0.50f, 3); // Aumenta a defesa em 50% por 3 turnos

    cout << atacante.getNome() << " ativou a Firewall Digital, aumentando sua própria defesa significativamente por 3 turnos!\n";
}

void FirewallDigital::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Buff (Tecnologia)" << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Cria uma barreira de energia que aumenta drasticamente a defesa do usuário por vários turnos." << endl;
}