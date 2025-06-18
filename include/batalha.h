#ifndef BATALHA_H
#define BATALHA_H

#include "personagem.h"
#include "inimigo.h"
#include "inventario.h"
#include "pocoes.h"
#include "armadura.h"
#include <vector>
#include <algorithm> // ordenar a fila de turnos

using namespace std; 

class Batalha {
    private:
        Personagem& jogador;
        Inimigo& inimigo;
        Inventario<Pocao*>& inventarioPocoes;
        Inventario<Armadura*>& inventarioArmaduras;

        vector<Personagem*> filaDeTurnos;
        int indiceTurnoAtual = 0;
        bool batalhaTerminou = false;

        void determinarOrdemDeBatalha();
        void executarTurno();
        void executarTurnoJogador();
        void executarTurnoInimigo();
        void mostrarStatusBatalha() const;
        void verificarFimDeBatalha();

    public:
        Batalha(Personagem& j, Inimigo& i, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA);
        void iniciar();
};

#endif