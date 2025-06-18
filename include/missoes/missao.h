#ifndef MISSAO_H
#define MISSAO_H

#include <string>
#include <vector>
#include <iostream>
#include "recompensa.h"
#include "personagem.h"

using namespace std; 

enum class EstadoMissao {
    PENDENTE, // ainda nao foi acessada/aceita
    ATIVA,    // o jogador tá nela
    COMPLETA  // concluida
};

struct Objetivo {
    string descricao;
    bool concluido = false;
};

class Missao {
protected:
    int id;
    string titulo;
    string descricao;
    EstadoMissao estado;
    vector<Objetivo> objetivos;
    Recompensa recompensa;
    bool ehPrincipal;

public:
    // O construtor agora inclui um ID único e se a missão é principal
    Missao(int id, string titulo, string desc, Recompensa recomp, bool principal)
        : id(id), titulo(titulo), descricao(desc), estado(EstadoMissao::PENDENTE), recompensa(recomp), ehPrincipal(principal) {}
    
    virtual ~Missao() = default;

    // Métodos para controlar o fluxo da missão
    virtual void iniciar() {
        cout << "\nIniciando missao: " << titulo << endl;
        this->estado = EstadoMissao::ATIVA;
    }
    
    virtual Recompensa completar(Personagem& jogador) {
        cout << "\nMissao concluida: " << titulo << "!" << endl;
        cout << "Recompensa: " << recompensa.xp << " de XP." << endl;
        jogador.ganharXP(recompensa.xp);
        this->estado = EstadoMissao::COMPLETA;
        return recompensa;
    }

    void mostrarProgresso() const {
        cout << "\n[" << titulo << "]" << endl;
        for (const auto& obj : objetivos) {
            cout << "- " << obj.descricao << " [" << (obj.concluido ? "✓" : " ") << "]" << endl;
        }
    }

    // Getters
    int getID() const { return id; }
    string getTitulo() const { return titulo; }
    EstadoMissao getEstado() const { return estado; }
    bool isPrincipal() const { return ehPrincipal; }
};

#endif