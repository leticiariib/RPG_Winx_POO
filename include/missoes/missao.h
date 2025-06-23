#ifndef MISSAO_H
#define MISSAO_H

#include <string>
#include <vector>
#include <iostream>
#include "missoes/recompensa.h"
#include "personagens/personagem.h"

using namespace std;

enum class EstadoMissao {
    PENDENTE,
    ATIVA,
    COMPLETA
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
    Missao(int id, string titulo, string desc, Recompensa recomp, bool principal)
        : id(id), titulo(titulo), descricao(desc), estado(EstadoMissao::PENDENTE), recompensa(recomp), ehPrincipal(principal) {}

    virtual ~Missao() = default;

    // so as declaraçoes 
    virtual void iniciar();
    virtual Recompensa completar(Personagem& jogador);
    void mostrarProgresso() const;
    void resetar(); 

    int getID() const { return id; }
    string getTitulo() const { return titulo; }
    EstadoMissao getEstado() const { return estado; }
    bool isPrincipal() const { return ehPrincipal; }
};

// classes derivadas para distinguir os tipos de missão
class MissaoPrincipal : public Missao {
public:
    using Missao::Missao;
};

class MissaoSecundaria : public Missao {
public:
    using Missao::Missao;
};

#endif
