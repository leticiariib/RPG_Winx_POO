#include "batalha.h"
#include "habilidades/habilidade.h"
#include <iostream>
#include <limits> // p/ limpar o buffer de entrada
#include <cstdlib> 
#include <ctime>   

Batalha::Batalha(Personagem& j, Inimigo& i, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA)
    : jogador(j), inimigo(i), inventarioPocoes(invP), inventarioArmaduras(invA) {
    srand(time(0)); // inicializa gerador de num. aleatorios 
    determinarOrdemDeBatalha();
}

void Batalha::determinarOrdemDeBatalha() {
    filaDeTurnos.push_back(&jogador);
    filaDeTurnos.push_back(&inimigo);

    // ordena ordem da batalha com base na velocidade, maior velocidade começa primeiro 
    std::sort(filaDeTurnos.begin(), filaDeTurnos.end(), [](const Personagem* a, const Personagem* b) {
        return a->getVelocidade() > b->getVelocidade();
    });

    cout << "A ordem de batalha foi definida! " << filaDeTurnos[0]->getNome() << " age primeiro." << endl;
}

void Batalha::iniciar() {
    while (!batalhaTerminou) {
        executarTurno();
    }
}

void Batalha::executarTurno() {
    Personagem* personagemDaVez = filaDeTurnos[indiceTurnoAtual];

    personagemDaVez->prepararParaNovoTurno();

    //verificar se personagem sobreviveu aos efeitos continuos ou danos
    if (!personagemDaVez->estaVivo()) {
        verificarFimDeBatalha();
        if (batalhaTerminou) return;
    } else {
        mostrarStatusBatalha();

        // verifica se é o turno do jogador ou do inimigo
        if (personagemDaVez == &jogador) {
            executarTurnoJogador();
        } else {
            executarTurnoInimigo();
        }
    }
    
    verificarFimDeBatalha();

    // passar para o próximo na fila
    indiceTurnoAtual = (indiceTurnoAtual + 1) % filaDeTurnos.size();
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
                    jogador.usarHabilidade(escolhaHab - 1, inimigo);
                    return; // Ação valida, encerra o turno.
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

void Batalha::executarTurnoInimigo() {
    cout << "\n--- TURNO DE " << inimigo.getNome() << "! ---" << endl;
    if (inimigo.getHabilidades().empty()) {
        cout << inimigo.getNome() << " nao sabe o que fazer e perde o turno." << endl;
        return;
    }
    // jogada do "computador" simples: escolhe uma habilidade aleatória
    int escolhaCompt = rand() % inimigo.getHabilidades().size();
    inimigo.usarHabilidade(escolhaCompt, jogador);
}

void Batalha::mostrarStatusBatalha() const {
    cout << "\n----------------------------------------" << endl;
    cout << jogador.getNome() << " | Vida: " << jogador.getVida() << " | Magia: " << jogador.getMagia() << endl;
    cout << inimigo.getNome() << " | Vida: " << inimigo.getVida() << " | Magia: " << inimigo.getMagia() << endl;
    cout << "----------------------------------------" << endl;
}

void Batalha::verificarFimDeBatalha() {
    if (!jogador.estaVivo()) {
        mostrarStatusBatalha();
        cout << "\nVOCÊ FOI DERROTADO!" << endl;
        batalhaTerminou = true;
    } else if (!inimigo.estaVivo()) {
        mostrarStatusBatalha();
        cout << "\nVITORIA! " << inimigo.getNome() << " foi derrotado!" << endl;
        batalhaTerminou = true;
    }
}