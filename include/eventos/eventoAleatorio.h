#ifndef EVENTO_ALEATORIO_H
#define EVENTO_ALEATORIO_H

#include <string>
#include <vector>
#include <random>
#include "personagens/personagem.h"

class EventoAleatorio {
public:
    struct Opcao {
        std::string descricao;
        int impactoVida = 0;
        int impactoMagia = 0;
        std::string mensagemFinal;
    };

    struct Evento {
        std::string titulo;
        std::string descricao;
        std::vector<Opcao> opcoes;
    };

    EventoAleatorio();

    Evento sortearEvento(); 
    void executarOpcao(const Opcao& opcao, Personagem& personagem);

private:
    std::vector<Evento> eventos;
    std::mt19937 rng;
    void inicializarEventos();
};

#endif
