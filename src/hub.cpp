#include "hub.h"

#include <iostream>
#include <vector>
#include <memory>

#include "include/personagens/personagem.h"
#include "include/batalha.h"
#include "include/habilidades/habilidade.h"
#include "include/inventario/inventario.h"
#include "include/inventario/item.h"
#include "include/inventario/armaduras/armadura.h"
#include "include/inventario/armaduras/braceleteConcentracao.h"
#include "include/inventario/armaduras/capaDeGuardia.h"
#include "include/inventario/armaduras/mantoDeEnchantrix.h"
#include "include/inventario/pocoes/elixirDaVida.h"
#include "include/inventario/pocoes/pocoes.h"
#include "include/inventario/pocoes/poDeFada.h"

#include "include/habilidades/danoContinuo/chamasPersistentes.h"
#include "include/habilidades/danoContinuo/curtoCircuito.h"
#include "include/habilidades/danoContinuo/esporosVenenosos.h"
#include "include/habilidades/danoContinuo/nevascaCongelante.h"
#include "include/habilidades/danoContinuo/rajadaSombria.h"
#include "include/habilidades/danoContinuo/redemoinho.h"

#include "include/habilidades/danoDireto/chamaDoDragao.h"
#include "include/habilidades/danoDireto/estilhacoDeGelo.h"
#include "include/habilidades/danoDireto/jatoDeAgua.h"
#include "include/habilidades/danoDireto/mareAscendente.h"
#include "include/habilidades/danoDireto/ondaSonora.h"
#include "include/habilidades/danoDireto/pancadaRochosa.h"
#include "include/habilidades/danoDireto/pancadaSombria.h"
#include "include/habilidades/danoDireto/raioDeEnergia.h"
#include "include/habilidades/danoDireto/relampago.h"
#include "include/habilidades/danoDireto/setaDasTrevas.h"
#include "include/habilidades/danoDireto/sombraDoMedo.h"

#include "include/missoes/controladorDeMissoes.h"
#include "include/missoes/missao.h"
#include "include/missoes/ecosDaCorrupcao.h"
#include "include/missoes/missaoGiganteEnfurecido.h"
#include "include/missoes/recompensa.h"
#include "include/missoes/sombrasEmAlfea.h"
#include "include/missoes/sussurrosNaBibliotecaSombria.h"


#include "include/habilidades/nivelAlto/abracoDaNatureza.h"
#include "include/habilidades/nivelAlto/crescendoEstilhacante.h"
#include "include/habilidades/nivelAlto/firewallDigital.h"
#include "include/habilidades/nivelAlto/fortificar.h"
#include "include/habilidades/nivelAlto/furacaoDestruidor.h"
#include "include/habilidades/nivelAlto/furiaDoDragao.h"
#include "include/habilidades/nivelAlto/ondaDeHipnose.h"
#include "include/habilidades/nivelAlto/pilarDeAgua.h"
#include "include/habilidades/nivelAlto/superNova.h"
#include "include/habilidades/nivelAlto/vazioAbsoluto.h"

#include "include/personagens/personagem.h"
#include "include/personagens/fadas/aisha.h"
#include "include/personagens/fadas/bloom.h"
#include "include/personagens/fadas/flora.h"
#include "include/personagens/fadas/musa.h"
#include "include/personagens/fadas/stella.h"
#include "include/personagens/fadas/tecna.h"

#include "include/personagens/inimigos/darcy.h"
#include "include/personagens/inimigos/icy.h"
#include "include/personagens/inimigos/stormy.h"
#include "include/personagens/inimigos/ghoul.h"
#include "include/personagens/inimigos/golemDePedra.h"
#include "include/personagens/inimigos/feiticeiroDeTorrenuvosa.h"
#include "include/personagens/inimigos/monstroDoPantano.h"
#include "include/personagens/inimigos/monstroDoPesadelo.h"

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
                    }
                    // TENHO QUE ADD AS OUTRAS MISSOES AQUI

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