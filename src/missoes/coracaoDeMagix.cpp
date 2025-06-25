#include "missoes\coracaoDeMagix.h"
#include "batalha.h"
#include "personagens\inimigos\golemDePedra.h"             
#include "personagens\inimigos\feiticeiroDeTorrenuvosa.h"
#include "personagens\inimigos\icy.h"                      
#include "personagens\inimigos\darcy.h"
#include "personagens\inimigos\stormy.h"
#include <vector>
#include <iostream>
#include <limits>
#include <cmath> 

using namespace std; 

Missao_CoracaoDeMagix::Missao_CoracaoDeMagix() 
    : MissaoPrincipal(7, "O Coração de Magix", "O confronto final! Invada Torrenuvosa e impeça as Trix de corromper o núcleo de Magix.", {}, true) 
{
    objetivos.push_back({"Invada as defesas de Torrenuvosa", false});
    objetivos.push_back({"Suba a torre e derrote as Trix individualmente", false});
    objetivos.push_back({"Enfrente o poder combinado das Trix", false});

    recompensa.xp = 5000; 
}

// Função auxiliar para permitir que o jogador use poções entre as batalhas da "Escalada"
void Missao_CoracaoDeMagix::faseDePreparacao(Personagem& fada, Inventario<Pocao*>& invP) {
    cout << "\nVocê tem um breve momento para se preparar antes do próximo desafio..." << endl;
    while (true) {
        cout << "\nVida: " << fada.getVida() << "/" << fada.getVidaMaxima() 
                  << " | Magia: " << round(fada.getMagia()) << "/" << round(fada.getMagiaMaxima()) << endl;
        cout << "1. Usar Poção\n2. Continuar para a próxima batalha" << endl;
        cout << "Sua escolha: ";
        int escolha;
        cin >> escolha;
        
        if (cin.fail()) { cin.clear(); }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (escolha == 1) {
            if (invP.getTamanho() > 0) {
                invP.mostrarItens();
                cout << "Escolha uma poção (ou 0 para voltar): ";
                int escPoc;
                cin >> escPoc;
                if (escPoc > 0 && escPoc <= invP.getTamanho()) {
                    invP.getItem(escPoc - 1)->aplicarEfeito(fada);
                    invP.removerItem(escPoc - 1);
                }
            } else {
                cout << "Nenhuma poção no inventário!" << endl;
            }
        } else if (escolha == 2) {
            break;
        }
    }
}

void Missao_CoracaoDeMagix::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar();
    
    // PARTE 1: A INVASÃO
    cout << "\nTorrenuvosa está envolta em uma tempestade de magia sombria. Para entrar, você precisa passar pela guarda de elite das Trix." << endl;
    mostrarProgresso();

    GolemDePedra golem;
    FeiticeiroDeTorrenuvosa feiticeiro;
    vector<Inimigo*> inimigos1 = {&golem, &feiticeiro};
    Batalha batalha1(fadaEscolhida, inimigos1, invP, invA);
    if (!batalha1.iniciar()) {
        cout << "As defesas de Torrenuvosa eram impenetráveis... A missão falhou." << endl;
        resetar(); return;
    }
    objetivos[0].concluido = true;

    // PARTE 2: A ESCALADA (BOSS RUSH)
    cout << "\nVocê invade a torre. Cada uma das Trix te aguarda em um andar, tentando te parar com seu poder máximo." << endl;
    mostrarProgresso();
    
    // Luta contra Stormy
    faseDePreparacao(fadaEscolhida, invP);
    Stormy stormy;
    vector<Inimigo*> chefe1 = {&stormy};
    Batalha batalha2(fadaEscolhida, chefe1, invP, invA);
    if (!batalha2.iniciar()) { resetar(); return; }

    // Luta contra Darcy
    faseDePreparacao(fadaEscolhida, invP);
    Darcy darcy;
    vector<Inimigo*> chefe2 = {&darcy};
    Batalha batalha3(fadaEscolhida, chefe2, invP, invA);
    if (!batalha3.iniciar()) { resetar(); return; }

    // Luta contra Icy
    faseDePreparacao(fadaEscolhida, invP);
    Icy icy;
    vector<Inimigo*> chefe3 = {&icy};
    Batalha batalha4(fadaEscolhida, chefe3, invP, invA);
    if (!batalha4.iniciar()) { resetar(); return; }

    objetivos[1].concluido = true;

    // PARTE 3: O CONFRONTO FINAL
    cout << "\nVocê chega ao salão do trono. As três bruxas, exaustas mas furiosas, se unem e canalizam todo o poder restante do Orbe do Caos!" << endl;
    mostrarProgresso();

    Icy finalIcy;
    Darcy finalDarcy;
    Stormy finalStormy;
    // pra ficar mais justo e equilibrado diminuimos a vida das trix 
    float multiplicadorVidaFinal = 0.55f; // As Trix terão 55% da vida normal
    finalIcy.ajustarVidaMaxima(multiplicadorVidaFinal);
    finalDarcy.ajustarVidaMaxima(multiplicadorVidaFinal);
    finalStormy.ajustarVidaMaxima(multiplicadorVidaFinal);
    // também resetamos a vida delas para o novo máximo, para que comecem a luta curadas
    finalIcy.recuperarTudo();
    finalDarcy.recuperarTudo();
    finalStormy.recuperarTudo();

    vector<Inimigo*> trixUnidas = {&finalIcy, &finalDarcy, &finalStormy};
    Batalha batalhaFinal(fadaEscolhida, trixUnidas, invP, invA);
    if (!batalhaFinal.iniciar()) {
        cout << "O poder combinado das Trix era grande demais... O mal venceu." << endl;
        resetar(); return;
    }

    objetivos[2].concluido = true;

    // === FIM DO JOGO ===
    cout << "\n\nCom um grito final, as Trix são derrotadas e o Orbe do Caos se estilhaça em mil pedaços de luz!" << endl;
    cout << "A escuridão se dissipa de Torrenuvosa e a paz é restaurada na Dimensão Mágica." << endl;
    completar(fadaEscolhida);
    cout << "\n\nPARABÉNS! VOCÊ COMPLETOU O RPG DO CLUBE DAS WINX!\n\nFIM." << endl;
}