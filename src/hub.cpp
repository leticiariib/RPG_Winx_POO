#include <iostream>
#include <vector>
#include <memory>
#include <limits>

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

    // Criamos os inventários do jogador, que persistirão durante todo o jogo.
    Inventario<Pocao*> inventarioPocoes;
    Inventario<Armadura*> inventarioArmaduras;
    inventarioPocoes.adicionarItem(new ElixirDaVida()); // iteem adicional pro jogador 

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
            case 1: { // QUADRO DE MISSÕES
                diario.mostrarMissoesDisponiveis();
                diario.mostrarMissoesAtivas();

                cout << "\nDigite o ID da missão que deseja iniciar (ou 0 para voltar): ";
                int idMissao;
                cin >> idMissao;

                if (idMissao == 0) break;

                Missao* missaoEscolhida = diario.getMissao(idMissao);

                // Validação da missão
                if (!missaoEscolhida || missaoEscolhida->getEstado() != EstadoMissao::PENDENTE) {
                    cout << "ID de missão inválido ou missão não disponível." << endl;
                    break;
                }
                
                // Pré-requisito simples: Missão 3 só aparece se a 2 for completa.
                bool podeIniciar = true;

                // 1. O pré-requisito SÓ se aplica se a missão escolhida for PRINCIPAL
                if (missaoEscolhida->isPrincipal()) {
                    // 2. Procura pela missão principal anterior, em vez de apenas id-1
                    Missao* missaoPrincipalAnterior = nullptr;
                    for (int idAnterior = idMissao - 1; idAnterior > 0; --idAnterior) {
                        Missao* missaoCandidata = diario.getMissao(idAnterior);
                        if (missaoCandidata && missaoCandidata->isPrincipal()) {
                            missaoPrincipalAnterior = missaoCandidata;
                            break; // Encontrou a principal anterior, pode parar de procurar
                        }
                    }

                    // 3. Se encontrou uma principal anterior, verifica seu estado
                    if (missaoPrincipalAnterior && missaoPrincipalAnterior->getEstado() != EstadoMissao::COMPLETA) {
                        cout << "Você precisa completar a missão principal '" 
                            << missaoPrincipalAnterior->getTitulo() << "' primeiro!" << endl;
                        podeIniciar = false; // Não pode iniciar
                    }
                }

                if (!podeIniciar) {
                    break; // Volta para o menu do Hub
                }

                // ESCOLHA DO PERSONAGEM
                cout << "\nEscolha uma fada para esta missão:" << endl;
                for (int i = 0; i < fadasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << fadasDisponiveis[i]->getNome() << " (Nível " << fadasDisponiveis[i]->getNivel() << ")" << endl;
                }
                cout << "Sua escolha: ";
                int escolhaFada;
                cin >> escolhaFada;

                if (escolhaFada > 0 && escolhaFada <= fadasDisponiveis.size()) {
                    Personagem* fadaParaMissao = fadasDisponiveis[escolhaFada - 1];
                    
                    cout << "\n" << fadaParaMissao->getNome() << " se prepara para a missão '" << missaoEscolhida->getTitulo() << "'!" << endl;
                    cout << "Pressione Enter para continuar...";
                    cin.get();
                    limparTela();
                    
                    // INICIANDO A MISSÃO
                    // Usamos static_cast para chamar o método executar da classe específica da missão
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

                    // Lógica Pós-Missão: Recupera a fada para que ela esteja pronta para a próxima
                    if (!fadaParaMissao->estaVivo()) {
                         cout << "\nApesar da falha, a energia de Alfea te reanima." << endl;
                    }
                    fadaParaMissao->recuperarTudo();
                    cout << "\nRetornando ao Pátio de Alfea. Pressione Enter para continuar...";
                    cin.get();
                    limparTela();

                } else {
                    cout << "Escolha de fada inválida." << endl;
                }
                break;
            }
            case 2: { // VER STATUS
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
                    cin.get(); // Pausa a tela
                    limparTela();
                } else {
                    cout << "Escolha inválida." << endl;
                }
                break;
            }
            case 3: { // SAIR
                cout << "Obrigada por jogar! Até a próxima!" << endl;
                jogoRodando = false;
                break;
            }
            default:
                cout << "Opção inválida! Por favor, tente novamente." << endl;
                break;
        } // Fim do switch
    } // Fim do while

    // O destrutor do 'diario' e dos 'inventarios' será chamado automaticamente,
    // limpando a memória das missões e itens criados com 'new'.
}