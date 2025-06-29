#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <chrono>
#include <thread>

#include "hub.h"

#include "personagens/personagem.h"
#include "batalha.h"
#include "habilidades/habilidade.h"
#include "inventario/inventario.h"
#include "inventario/item.h"
#include "inventario/armaduras/armadura.h"
#include "inventario/armaduras/braceleteConcentracao.h"
#include "inventario/armaduras/capaDeGuardia.h"
#include "inventario/armaduras/mantoDeEnchantrix.h"
#include "inventario/pocoes/elixirDaVida.h"
#include "inventario/pocoes/pocoes.h"
#include "inventario/pocoes/poDeFada.h"

#include "habilidades/danoContinuo/chamasPersistentes.h"
#include "habilidades/danoContinuo/curtoCircuito.h"
#include "habilidades/danoContinuo/esporosVenenosos.h"
#include "habilidades/danoContinuo/nevascaCongelante.h"
#include "habilidades/danoContinuo/rajadaSombria.h"
#include "habilidades/danoContinuo/redemoinho.h"

#include "habilidades/danoDireto/chamaDoDragao.h"
#include "habilidades/danoDireto/estilhacoDeGelo.h"
#include "habilidades/danoDireto/jatoDeAgua.h"
#include "habilidades/danoDireto/mareAscendente.h"
#include "habilidades/danoDireto/ondaSonora.h"
#include "habilidades/danoDireto/pancadaRochosa.h"
#include "habilidades/danoDireto/pancadaSombria.h"
#include "habilidades/danoDireto/raioDeEnergia.h"
#include "habilidades/danoDireto/relampago.h"
#include "habilidades/danoDireto/setaDasTrevas.h"
#include "habilidades/danoDireto/sombraDoMedo.h"
#include "habilidades/danoDireto/clavaEsmagadora.h"

#include "missoes/controladorDeMissoes.h"
#include "missoes/missao.h"
#include "missoes/ecosDaCorrupcao.h"
#include "missoes/missaoGiganteEnfurecido.h"
#include "missoes/recompensa.h"
#include "missoes/sombrasEmAlfea.h"
#include "missoes/sussurrosNaBibliotecaSombria.h"
#include "missoes/coracaoDeMagix.h"
#include "missoes/oLamentoDoOgro.h"
#include "missoes/tempestadeEmZenith.h"

#include "habilidades/nivelAlto/abracoDaNatureza.h"
#include "habilidades/nivelAlto/crescendoEstilhacante.h"
#include "habilidades/nivelAlto/firewallDigital.h"
#include "habilidades/nivelAlto/fortificar.h"
#include "habilidades/nivelAlto/furacaoDestruidor.h"
#include "habilidades/nivelAlto/furiaDoDragao.h"
#include "habilidades/nivelAlto/ondaDeHipnose.h"
#include "habilidades/nivelAlto/pilarDeAgua.h"
#include "habilidades/nivelAlto/superNova.h"
#include "habilidades/nivelAlto/vazioAbsoluto.h"

#include "personagens/personagem.h"
#include "personagens/fadas/aisha.h"
#include "personagens/fadas/bloom.h"
#include "personagens/fadas/flora.h"
#include "personagens/fadas/musa.h"
#include "personagens/fadas/stella.h"
#include "personagens/fadas/tecna.h"

#include "personagens/inimigos/darcy.h"
#include "personagens/inimigos/icy.h"
#include "personagens/inimigos/stormy.h"
#include "personagens/inimigos/ghoul.h"
#include "personagens/inimigos/golemDePedra.h"
#include "personagens/inimigos/feiticeiroDeTorrenuvosa.h"
#include "personagens/inimigos/monstroDoPantano.h"
#include "personagens/inimigos/monstroDoPesadelo.h"
#include "personagens/inimigos/sentinelaEletrica.h"
#include "personagens/inimigos/knut.h"

using namespace std;

// função auxiliar para limpar a tela de forma simples
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void iniciarHubDoJogo() {
    // 1. INICIALIZAÇÃO DO JOGO (Acontece uma única vez)
    cout << "Bem-vinda ao RPG do Clube das Winx!" << endl;

    Inventario<Pocao*> inventarioPocoes;
    Inventario<Armadura*> inventarioArmaduras;

    inventarioPocoes.adicionarItem(new ElixirDaVida());// iteem adicional pro jogador 
    cout << "Voce ganhou um item de brinde por entrar no jogo!" << endl; 

    // Criamos o diário de missões e o populamos com todas as missões do jogo.
    ControladorDeMissoes diario;
    diario.adicionarMissao(new Missao_SombrasEmAlfea());
    diario.adicionarMissao(new Missao_EcosDaCorrupcao());
    diario.adicionarMissao(new Missao_SussurrosNaBiblioteca());
    diario.adicionarMissao(new Missao_GiganteEnfurecido());
    diario.adicionarMissao(new Missao_oLamentoDoOgro());
    diario.adicionarMissao(new Missao_TempestadeEmZenith());
    diario.adicionarMissao(new Missao_CoracaoDeMagix());

     // Criamos a "lista" de fadas disponíveis
    Bloom bloom;
    Stella stella;
    Flora flora;
    Aisha aisha;
    Musa musa;
    Tecna tecna;
    vector<Personagem*> fadasDisponiveis = {&bloom, &stella, &flora, &aisha, &musa, &tecna};

    bool jogoRodando = true;

    // 2. LOOP PRINCIPAL DO JOGO
    while (jogoRodando) {
        cout << "\n\n===== PÁTIO DE ALFEA (MENU PRINCIPAL) =====" << endl;
        cout << "1. Quadro de Missões" << endl;
        cout << "2. Ver Status das Fadas" << endl;
        cout << "3. Sair do Jogo" << endl;
        cout << "Sua escolha: ";

        int escolhaMenu;
        cin >> escolhaMenu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolhaMenu = 0;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        limparTela();

        switch (escolhaMenu) {
            case 1: {// QUADRO DE MISSÕES
                diario.mostrarMissoesDisponiveis();
                diario.mostrarMissoesAtivas();

                cout << "\nDigite o ID da missão que deseja iniciar (ou 0 para voltar): ";
                int idMissao;
                cin >> idMissao;

                if (idMissao == 0) break;

                Missao* missaoEscolhida = nullptr;
                try {
                    missaoEscolhida = diario.getMissao(idMissao);
                    if (!missaoEscolhida) {
                        throw runtime_error("Missão não encontrada com o ID fornecido.");
                    }
                } catch (const exception& e) {
                    cout << "Erro ao recuperar missão: " << e.what() << endl;
                    break;
                }

                bool podeIniciar = true;

                if (missaoEscolhida->isPrincipal()) {
                    Missao* missaoPrincipalAnterior = nullptr;
                    for (int idAnterior = idMissao - 1; idAnterior > 0; --idAnterior) {
                        Missao* missaoCandidata = diario.getMissao(idAnterior);
                        if (missaoCandidata && missaoCandidata->isPrincipal()) {
                            missaoPrincipalAnterior = missaoCandidata;
                            break;
                        }
                    }

                    if (missaoPrincipalAnterior && missaoPrincipalAnterior->getEstado() != EstadoMissao::COMPLETA) {
                        cout << "Você precisa completar a missão principal '" 
                             << missaoPrincipalAnterior->getTitulo() << "' primeiro!" << endl;
                        podeIniciar = false;
                    }
                }

                if (!podeIniciar) {
                    break;
                }

                cout << "\nEscolha uma fada para esta missão:" << endl;
                for (int i = 0; i < fadasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << fadasDisponiveis[i]->getNome() << " (Nível " << fadasDisponiveis[i]->getNivel() << ")" << endl;
                }
                cout << "Sua escolha: ";
                int escolhaFada;
                cin >> escolhaFada;

                try {
                    if (escolhaFada <= 0 || escolhaFada > fadasDisponiveis.size()) {
                        throw runtime_error("Escolha de fada inválida.");
                    }

                    Personagem* fadaParaMissao = fadasDisponiveis[escolhaFada - 1];

                    cout << "\n" << fadaParaMissao->getNome() << " se prepara para a missão '" << missaoEscolhida->getTitulo() << "'!" << endl;
                    cout << "Pressione Enter para continuar...";
                    cin.get(); cin.get();
                    limparTela();

                    if (idMissao == 1) {
                        static_cast<Missao_SombrasEmAlfea*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 2) {
                        static_cast<Missao_EcosDaCorrupcao*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 3) {
                        static_cast<Missao_SussurrosNaBiblioteca*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 4) {
                        static_cast<Missao_GiganteEnfurecido*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 5) {
                        static_cast<Missao_oLamentoDoOgro*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 6) {
                        static_cast<Missao_TempestadeEmZenith*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    } else if (idMissao == 7) {
                        static_cast<Missao_CoracaoDeMagix*>(missaoEscolhida)->executar(*fadaParaMissao, inventarioPocoes, inventarioArmaduras);
                    }

                    if (!fadaParaMissao->estaVivo()) {
                        cout << "\nApesar da falha, a energia de Alfea te reanima." << endl;
                    }

                    fadaParaMissao->recuperarTudo();
                    cout << "\nRetornando ao Pátio de Alfea. Pressione Enter para continuar...";
                    cin.get(); cin.get();
                    limparTela();

                } catch (const exception& e) {
                    cout << "Erro: " << e.what() << endl;
                }
                break;

            }
            case 2: {// VER STATUS
                cout << "\nVer status de qual fada?" << endl;
                for (int i = 0; i < fadasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << fadasDisponiveis[i]->getNome() << endl;
                }
                cout << "Sua escolha: ";
                int escolhaFadaStatus;
                cin >> escolhaFadaStatus;

                if (escolhaFadaStatus > 0 && escolhaFadaStatus <= fadasDisponiveis.size()) {
                    limparTela();
                    fadasDisponiveis[escolhaFadaStatus - 1]->mostrarStatusCompleto();
                    cout << "\nPressione Enter para voltar ao menu...";
                    cin.get(); cin.get();
                    limparTela();
                } else {
                    cout << "Escolha inválida." << endl;
                }
                break;
            }
            case 3: {//sair
                cout << "Obrigada por jogar! Até a próxima!" << endl;
                jogoRodando = false;
                break;
            }
            default:
                cout << "Opção inválida! Por favor, tente novamente." << endl;
                break;
        }//fim switch
    }//fim while 
     // O destrutor do 'diario' e dos 'inventarios' será chamado automaticamente,
    // limpando a memória das missões e itens criados com 'new'.
}
