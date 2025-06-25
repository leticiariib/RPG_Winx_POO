#ifndef EVENTO_ALEATORIO_H
#define EVENTO_ALEATORIO_H

#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>  
#include "personagens/personagem.h"

using namespace std;

class EventoAleatorio {
public:
    struct Opcao {
        string descricao;
        int impactoVida = 0;
        int impactoMagia = 0;
        string mensagemFinal;
    };

    struct Evento {
        string titulo;
        string descricao;
        vector<Opcao> opcoes;
    };

    EventoAleatorio();

    Evento sortearEvento(); 
    void executarOpcao(const Opcao& opcao, Personagem& personagem);

private:
    vector<Evento> eventos;
    void inicializarEventos();
};

#endif