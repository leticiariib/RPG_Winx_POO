#include "batalha.h"
#include "habilidades/habilidade.h"
#include <iostream>
#include <limits> // p/ limpar o buffer de entrada
#include <cstdlib> 
#include <ctime>   
#include <cmath> 

using namespace std; 

Batalha::Batalha(Personagem& j, vector<Inimigo*>& i, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA)
    : jogador(j), inimigos(i), inventarioPocoes(invP), inventarioArmaduras(invA) {
    srand(time(0)); // inicializa gerador de num. aleatorios 
    determinarOrdemDeBatalha();
}

void Batalha::determinarOrdemDeBatalha() {
    filaDeTurnos.push_back(&jogador);
    for (Inimigo* inimigo : inimigos) {
        filaDeTurnos.push_back(inimigo); 
    }

    // ordena ordem da batalha com base na velocidade, maior velocidade começa primeiro 
    sort(filaDeTurnos.begin(), filaDeTurnos.end(), [](const Personagem* a, const Personagem* b) {
        return a->getVelocidade() > b->getVelocidade();
    });

    cout << "A ordem de batalha foi definida! " << filaDeTurnos[0]->getNome() << " age primeiro." << endl;
}

bool Batalha::iniciar() {
    while (!batalhaTerminou) {
        executarTurno();
    }
    return jogador.estaVivo();
}

void Batalha::executarTurnoJogador() {
    cout << "\n--- SEU TURNO, " << jogador.getNome() << "! ---" << endl;

    // loop de acao do turno, pra caso o jogador escolha algo que nao de pra fazer ele nao perca o turno mas sim escolha novamente
    while (true) {
        cout << "\nO que fazer?" << endl;
        cout << "1. Usar Habilidade" << endl;
        cout << "2. Usar Pocao" << endl;
        cout << "3. Usar/Equipar Armadura" << endl;
        cout << "4. Defender" << endl;

        int escolhaAcao;
        cin >> escolhaAcao;

        // limpa o buffer de entrada para evitar erros e deixar limpo pra proxima leitura
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolhaAcao = 0; // Força uma escolha invalida para o switch
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (escolhaAcao) {
            case 1: { // Usar Habilidade
                cout << "\nEscolha uma habilidade (ou 0 para voltar):" << endl;
                const auto& habilidades = jogador.getHabilidades();
                for (int i = 0; i < habilidades.size(); ++i) {
                    cout << "\n--- Opcao " << i + 1 << " ---" << endl;
                    habilidades[i]->mostrarDetalhes();
                }
                
                cout << "\nSua escolha: ";
                int escolhaHab;
                cin >> escolhaHab;

                if (escolhaHab > 0 && escolhaHab <= habilidades.size()) {
                    Inimigo* alvo = escolherAlvo(); 
                    if(alvo){
                        jogador.usarHabilidade(escolhaHab - 1, *alvo);
                        return; // Ação valida, encerra o turno.
                    }
                } else {
                    cout << "Ação cancelada, voltando ao menu principal..." << endl;
                    // Não faz nada, o loop while vai repetir.
                }
                break; // Volta para o loop while(true)
            }
            case 2: { // Usar Poção
                if (inventarioPocoes.getTamanho() == 0) {
                    cout << "Inventario de pocoes vazio. Escolha outra acao." << endl;
                    // break para voltar ao menu principal, sem perder o turno.
                } else {
                    inventarioPocoes.mostrarItens();
                    cout << "\nEscolha uma pocao (ou 0 para voltar): ";
                    int escolhaPoc;
                    cin >> escolhaPoc;
                    if (escolhaPoc > 0 && escolhaPoc <= inventarioPocoes.getTamanho()) {
                        int indice = escolhaPoc - 1;
                        inventarioPocoes.getItem(indice)->aplicarEfeito(jogador);
                        inventarioPocoes.removerItem(indice);
                        return; // Ação válida, encerra o turno.
                    } else {
                        cout << "Ação cancelada, voltando ao menu principal..." << endl;
                    }
                }
                break; // Volta para o loop while(true)
            }
            case 3: { // Usar Armadura
                if (inventarioArmaduras.getTamanho() == 0) {
                    cout << "Nenhuma armadura no inventario. Escolha outra acao." << endl;
                } else {
                    inventarioArmaduras.mostrarItens();
                    cout << "\nEscolha uma armadura para usar o efeito (ou 0 para voltar): ";
                    int escolhaArm;
                    cin >> escolhaArm;
                    if (escolhaArm > 0 && escolhaArm <= inventarioArmaduras.getTamanho()) {
                        inventarioArmaduras.getItem(escolhaArm - 1)->aplicarEfeito(jogador);
                        return; // Acao valida, encerra o turno.
                    } else {
                        cout << "Acao cancelada, voltando ao menu principal..." << endl;
                    }
                }
                break; // Volta para o loop while(true)
            }
            case 4: { // Defender
                jogador.defender();
                return; 
            }
            default:
                cout << "Opcao invalida! Por favor, escolha uma acao da lista." << endl;
        } 
    } 
}

void Batalha::executarTurnoInimigo(Inimigo* inimigoDaVez) {
    cout << "\n--- TURNO DE " << inimigoDaVez->getNome() << "! ---" << endl;
    if (inimigoDaVez->getHabilidades().empty()) {
        cout << inimigoDaVez->getNome() << " nao sabe o que fazer e perde o turno." << endl;
        return;
    }
    // jogada do "computador" simples: escolhe uma habilidade aleatória
    int escolhaCompt = rand() % inimigoDaVez->getHabilidades().size();
    inimigoDaVez->usarHabilidade(escolhaCompt, jogador);
}

void Batalha::executarTurno() {
    Personagem* personagemDaVez = filaDeTurnos[indiceTurnoAtual];

    personagemDaVez->prepararParaNovoTurno();

    // verifica se o personagem foi derrotado pelos efeitos contínuos (ex: veneno)
    if (!personagemDaVez->estaVivo()) {
        verificarFimDeBatalha();
        indiceTurnoAtual = (indiceTurnoAtual + 1) % filaDeTurnos.size();
        return; 
    }

    mostrarStatusBatalha();

    if (personagemDaVez == &jogador) {
        executarTurnoJogador();
    } else {
        executarTurnoInimigo(static_cast<Inimigo*>(personagemDaVez));
    }
    verificarFimDeBatalha();

    indiceTurnoAtual = (indiceTurnoAtual + 1) % filaDeTurnos.size();
}

void Batalha::verificarFimDeBatalha() {
    bool todosInimigosMortos = true;
    for (const auto& inimigo : inimigos) {
        if (inimigo->estaVivo()) {
            todosInimigosMortos = false;
            break;
        }
    }
}

Inimigo* Batalha::escolherAlvo() {
    cout << "\nEscolha o alvo (ou 0 para cancelar):" << endl;
    vector<Inimigo*> alvosVivos;
    for (Inimigo* inimigo : inimigos) {
        if (inimigo->estaVivo()) {
            alvosVivos.push_back(inimigo);
            cout << alvosVivos.size() << ". " << inimigo->getNome() << " (Vida: " << inimigo->getVida() << ")" << endl;
        }
    }

    if (alvosVivos.empty()) return nullptr; // Não deveria acontecer, mas é uma segurança

    int escolhaAlvo;
    cin >> escolhaAlvo;
    if (escolhaAlvo > 0 && escolhaAlvo <= alvosVivos.size()) {
        return alvosVivos[escolhaAlvo - 1];
    }
    
    cout << "Seleção de alvo cancelada." << endl;
    return nullptr;
}