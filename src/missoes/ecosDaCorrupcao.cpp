#include "missoes\ecosDaCorrupcao.h"
#include "batalha.h"
#include "personagens\inimigos\monstroDoPantano.h"
#include "personagens\inimigos\feiticeiroDeTorrenuvosa.h"
#include "inventario\pocoes\poDeFada.h"
#include "inventario\pocoes\elixirDaVida.h"
#include <vector>
#include <iostream>
using namespace std; 

Missao_EcosDaCorrupcao::Missao_EcosDaCorrupcao() 
    : MissaoPrincipal(2, "Ecos da Corrupção", "A energia do Orbe está se espalhando. Investigue uma fonte de corrupção nos Pântanos Negros.", {}, true) 
{
    objetivos.push_back({"Derrote a criatura corrompida do pântano", false});
    objetivos.push_back({"Elimine a fonte da energia sombria", false});

    recompensa.xp = 650;
    recompensa.itens.push_back(new PoDeFada());
}

void Missao_EcosDaCorrupcao::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar(); 
    
    // PARTE 1: A CRIATURA DO PÂNTANO 
    cout << "\nFaragonda te envia aos Pântanos Negros. O ar é pesado e a vegetação está doente e retorcida." << endl;
    cout << "De repente, a lama borbulha e uma criatura massiva e corrompida se ergue!" << endl;
    mostrarProgresso();

    // Prepara a primeira batalha
    MonstroDoPantano monstro;
    vector<Inimigo*> inimigos1 = {&monstro};
    Batalha batalha1(fadaEscolhida, inimigos1, invP, invA);
    bool vitoria1 = batalha1.iniciar();

    if (!vitoria1) {
        cout << "A criatura era forte demais... A missão falhou." << endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    cout << "\nCom o monstro derrotado, você percebe que ele era apenas um peão. A energia sombria emana de uma clareira mais adiante." << endl;

    cout << "\nVOCÊ RECEBEU UMA RECOMPENSA DE ETAPA!" << endl;
    int xpBonus = 100;
    fadaEscolhida.ganharXP(xpBonus);
    cout << "Você encontrou um " << "Elixir da Vida" << " no chão!" << endl;
    invP.adicionarItem(new ElixirDaVida());
    mostrarProgresso();

    // PARTE 2: A FONTE 
    cout << "Na clareira, um Feiticeiro de Torrenuvosa realiza um ritual, usando um pequeno fragmento do Orbe para corromper a terra. Ele precisa ser detido!" << endl;
    
    // Prepara a segunda batalha
    FeiticeiroDeTorrenuvosa feiticeiro;
    vector<Inimigo*> inimigos2 = {&feiticeiro};
    Batalha batalha2(fadaEscolhida, inimigos2, invP, invA);
    bool vitoria2 = batalha2.iniciar();

    if (!vitoria2) {
        cout << "O feitiço do bruxo era avassalador... A missão falhou." << endl;
        resetar();
        return;
    }

    objetivos[1].concluido = true;
    
    cout << "\nVocê derrotou o feiticeiro e a corrupção no pântano começa a se dissipar. Você recuperou um fragmento do Orbe!" << endl;
    Recompensa recompensaFinal = completar(fadaEscolhida); 

    cout << "\nItens recebidos como recompensa:" << endl;
    for (Item* itemRecompensa : recompensaFinal.itens) {
        Pocao* pocao = dynamic_cast<Pocao*>(itemRecompensa);
        if (pocao) {
            invP.adicionarItem(pocao);
        }
    }
    this->recompensa.itens.clear(); 
}