#include "include\missoes\tempestadeEmZenith.h"
#include "include\batalha.h"
#include "include\personagens\inimigos\sentinelaEletrica.h"
#include "include\personagens\inimigos\stormy.h"
#include "include\inventario\armaduras\mantoDeEnchantrix.h" 
#include <vector>
#include <iostream>

using namespace std; 

Missao_TempestadeEmZenith::Missao_TempestadeEmZenith() 
    : MissaoPrincipal(6, "Tempestade em Zenith", "Stormy está sobrecarregando a Rede de Energia de Zenith, o mundo de Tecna. Impeça-a antes que a cidade entre em colapso.", {}, true) 
{
    objetivos.push_back({"Neutralize os guardas robóticos corrompidos", false});
    objetivos.push_back({"Confronte a Bruxa das Tempestades", false});

    recompensa.xp = 1200;
    recompensa.itens.push_back(new MantoDeEnchantix());
}

void Missao_TempestadeEmZenith::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar();
    
    cout << "\nVocê chega em Zenith e encontra a cidade sob uma tempestade de raios. Os sistemas estão em curto. Drones de segurança, corrompidos pela energia caótica, te identificam como uma ameaça." << endl;
    mostrarProgresso();

    // Batalha 1: Inimigos tecnológicos
    SentinelaEletrica sentinela1, sentinela2;
    vector<Inimigo*> grupoDeSentinelas = {&sentinela1, &sentinela2};
    Batalha batalha1(fadaEscolhida, grupoDeSentinelas, invP, invA);
    bool vitoria1 = batalha1.iniciar();

    if (!vitoria1) {
        cout << "As sentinelas te sobrecarregaram... A missão falhou." << endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    cout << "\nCom os guardas desativados, você avança até o núcleo do reator de energia. Stormy está lá, absorvendo o poder e gargalhando em meio aos relâmpagos." << endl;
    mostrarProgresso();
    
    cout << "'Gostou dos meus fogos de artifício, fadinha? Agora sinta a tempestade de verdade!'" << endl;

    // Batalha 2: Chefe Stormy
    Stormy stormy;
    vector<Inimigo*> chefe = {&stormy};
    Batalha batalha2(fadaEscolhida, chefe, invP, invA);
    bool vitoria2 = batalha2.iniciar();

    if (!vitoria2) {
        cout << "A fúria da tempestade de Stormy era implacável... A missão falhou." << endl;
        resetar();
        return;
    }

    objetivos[1].concluido = true;
    
    // Conclusão e Recompensa
    cout << "\nStormy foi derrotada e a tempestade em Zenith se acalma. A rede de energia está a salvo." << endl;
    Recompensa recompensaFinal = completar(fadaEscolhida);

    cout << "\nItens recebidos como recompensa:" << endl;
    for (Item* itemRecompensa : recompensaFinal.itens) {
        Armadura* armadura = dynamic_cast<Armadura*>(itemRecompensa);
        if (armadura) {
            invA.adicionarItem(armadura);
        }
    }
    this->recompensa.itens.clear(); 
}