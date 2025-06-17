#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
#include <vector>
#include "habilidade.h"

using namespace std;

struct EfeitoContinuo {
    string tipo;
    int dano_por_turno;
    int duracao;
};

struct BuffTemporario {
    string tipo;
    float valor;
    int duracao;
};

class Personagem {
    protected:
        string nome;
        int vida;
        int vidaMaxima;
        float magia;
        float magiaMaxima;
        float defesa;
        float defesaBase;
        int velocidade;
        float ataque_magico;
        float reducaoDeDano = 0.0f;  
        vector<EfeitoContinuo> efeitos;
        vector<BuffTemporario> buffs; 
    public:
        Personagem(string nome, int vidaInicial, float magiaInicial, float defesaInicial, float ataqueMagicoInicial, int velocidadeInicial) 
            : nome(nome),
            vida(vidaInicial),
            vidaMaxima(vidaInicial),
            magia(magiaInicial),
            magiaMaxima(magiaInicial),
            defesa(defesaInicial),
            defesaBase(defesaInicial),
            ataque_magico(ataqueMagicoInicial),
            velocidade(velocidadeInicial) {}

        virtual void receberDano(float dano);
        void reduzirVelocidade(int quantidade);
        bool estaVivo() const { return vida > 0; }
        void aplicarEfeito(EfeitoContinuo& efeito);
        void atualizarTurno();
        virtual void mostarStatus() const;

        // getters 
        string getNome() const { return nome; }
        float getAtaque() const { return ataque_magico; }
        float getDefesa() const { return defesa; }
        int getVelocidade() const { return velocidade; }

        // funções dos efeitos de itens 
        void recuperarVidaPercentual(float porcentagem);
        void recuperarMagiaPercentual(float porcentagem);
        void aumentarDefesaTemporaria(float porcentagem, int turnos);
        void adicionarReducaoDeDano(float porcentagem);
        float getFatorReducaoCustoMagia() const;
        void usarHabilidade(Habilidade& habilidade, Personagem& alvo);
        void adicionarBuff(const BuffTemporario& buff);

};

#endif
