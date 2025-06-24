#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
#include <vector>
//#include "habilidades/habilidade.h"
class Habilidade; // declaracao forward

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
        int nivel;
        int xpAtual;
        int xpParaProximoNivel;
        vector<Habilidade*> habilidades;  
        vector<EfeitoContinuo> efeitos;
        vector<BuffTemporario> buffs; 

        bool estaDefendendo = false;

        void subirDeNivel();
        virtual void checarDesbloqueioHabilidades() {} 
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
            velocidade(velocidadeInicial),
            nivel(1), xpAtual(0), xpParaProximoNivel(100) {}

        virtual ~Personagem();

        virtual void receberDano(float dano);
        void defender();
        void prepararParaNovoTurno(); 
        void reduzirVelocidade(int quantidade);
        bool estaVivo() const { return vida > 0; }
        void mostrarStatusCompleto() const;

        void ganharXP(int xpGanho);
        void recuperarVida(float quantidade); 
        void recuperarTudo();
         
        void aplicarEfeito(EfeitoContinuo& efeito);
        void atualizarTurno();


        // getters 
        string getNome() const { return nome; }
        int getVida() const {return vida;}
        float getMagia() const {return magia;}
        float getAtaque() const { return ataque_magico; }
        float getDefesa() const { return defesa; }
        int getVelocidade() const { return velocidade; }
        int getNivel() const { return nivel; }
        int getVidaMaxima() const { return vidaMaxima; }
        float getMagiaMaxima() const { return magiaMaxima; }
        const vector<Habilidade*>& getHabilidades() const { return habilidades; }

        // funções dos efeitos de itens 
        void recuperarVidaPercentual(float porcentagem);
        void recuperarMagiaPercentual(float porcentagem);
        void aumentarDefesaTemporaria(float porcentagem, int turnos);
        void adicionarReducaoDeDano(float porcentagem);
        float getFatorReducaoCustoMagia() const;
        void usarHabilidade(int indiceHabilidade, Personagem& alvo);
        void adicionarBuff(const BuffTemporario& buff);

};

#endif
