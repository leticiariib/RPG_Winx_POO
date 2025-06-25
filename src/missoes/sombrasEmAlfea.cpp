#include "missoes\sombrasEmAlfea.h"
#include "batalha.h"
#include "personagens\inimigos\ghoul.h"
#include "personagens\inimigos\icy.h"
#include "inventario\pocoes\elixirDaVida.h"
#include "inventario\pocoes\poDeFada.h"
#include "inventario\armaduras\capaDeGuardia.h"
#include <vector>
#include <iostream>

using namespace std; 

Missao_SombrasEmAlfea::Missao_SombrasEmAlfea() 
    : MissaoPrincipal(1, "Sombras em Alfea", "Investigue a invasão em Alfea e descubra o responsável.", {500}, true) 
{
    objetivos.push_back({"Derrote os invasores Ghouls", false});
    objetivos.push_back({"Confronte a líder da invasão", false});

    recompensa.xp = 500;
    recompensa.itens.push_back(new ElixirDaVida());
    recompensa.itens.push_back(new PoDeFada());
    recompensa.itens.push_back(new CapaDaGuardia());
}

void Missao_SombrasEmAlfea::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar(); // marca a missão como ATIVA
    
    // PARTE 1
    cout << "\nVocê chega na entrada de Alfea e encontra a barreira mágica rompida. Dois ghouls horrendos avançam em sua direção!" << endl;
    mostrarProgresso();

    // primeira batalha (1 vs 2)
    Ghoul ghoul1, ghoul2;
    vector<Inimigo*> grupoDeGhouls = {&ghoul1, &ghoul2};
    Batalha batalha1(fadaEscolhida, grupoDeGhouls, invP, invA);
    bool vitoria1 = batalha1.iniciar();

    if (!vitoria1) {
        cout << "Você foi derrotado... A missão falhou." << endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    cout << "\nCom os ghouls derrotados, você segue o rastro de destruição e magia de gelo até a biblioteca..." << endl;
    
    cout << "\nVOCÊ RECEBEU UMA RECOMPENSA DE ETAPA!" << endl;
    int xpBonus = 100;
    fadaEscolhida.ganharXP(xpBonus);
    cout << "Você encontrou um " << "Elixir da Vida" << " no chão!" << endl;
    invP.adicionarItem(new ElixirDaVida());
    mostrarProgresso();

    // PARTE 2
    cout << "No centro da biblioteca, Icy está prestes a pegar o Orbe do Caos. Ela se vira e sorri friamente. 'Você não devia ter vindo, fadinha!'" << endl;
    
    // segunda batalha (1 vs 1 Chefe)
    Icy icy;
    vector<Inimigo*> chefe = {&icy};
    Batalha batalha2(fadaEscolhida, chefe, invP, invA);
    bool vitoria2 = batalha2.iniciar();

    if (!vitoria2) {
        cout << "Icy era poderosa demais... A missão falhou." << endl;
        resetar();
        return;
    }

    objetivos[1].concluido = true;
    cout << "\nIcy foi derrotada, mas ela usa uma distração para escapar com o Orbe. Pelo menos você sabe quem é a inimiga agora." << endl;

    Recompensa recompensaFinal = completar(fadaEscolhida); // marca missao como concluida e recebe o xp 

    // add os itens da recompensa aos inventários corretos
    cout << "\nItens recebidos como recompensa:" << endl;
    for (Item* itemRecompensa : recompensaFinal.itens) {
        // usamos dynamic_cast para descobrir se o item é uma Poção ou uma Armadura
        Pocao* pocao = dynamic_cast<Pocao*>(itemRecompensa);
        Armadura* armadura = dynamic_cast<Armadura*>(itemRecompensa);

        if (pocao) {
            invP.adicionarItem(pocao);
        } else if (armadura) {
            invA.adicionarItem(armadura);
        }
    }
    // esvazia o vetor de recompensas da missão para não adicioná-los de novo por acidente
    // ponteiros agora são gerenciados pelos inventários
    this->recompensa.itens.clear(); 
    setEstado(EstadoMissao::COMPLETA);

}