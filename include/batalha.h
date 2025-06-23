#ifndef BATALHA_H
#define BATALHA_H

#include "personagens/personagem.h"
#include "personagens/inimigo.h"
#include "inventario/inventario.h"
#include "inventario/pocoes/pocoes.h"
#include "inventario/armaduras/armadura.h"
#include <vector>
#include <algorithm> // ordenar a fila de turnos

using namespace std; 

class Batalha {
    private:
        Personagem& jogador;
        vector<Inimigo*>& inimigos; 
        Inventario<Pocao*>& inventarioPocoes;
        Inventario<Armadura*>& inventarioArmaduras;

        vector<Personagem*> filaDeTurnos;
        int indiceTurnoAtual = 0;
        bool batalhaTerminou = false;

        void determinarOrdemDeBatalha();
        void executarTurno();
        void executarTurnoJogador();
        void executarTurnoInimigo(Inimigo*);
        void mostrarStatusBatalha() const;
        void verificarFimDeBatalha();
        Inimigo* escolherAlvo(); 

    public:
        Batalha(Personagem& j, vector<Inimigo*>& i, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
        bool iniciar();
};

#endif