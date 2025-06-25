#include "missoes\oLamentoDoOgro.h"
#include "batalha.h"
#include "personagens\inimigos\knut.h"
#include "inventario\pocoes\elixirDaVida.h"
#include <vector>
#include <iostream>

using namespace std; 

Missao_oLamentoDoOgro::Missao_oLamentoDoOgro() 
    : MissaoSecundaria(5, "O Lamento do Ogro", "Knut foi visto causando problemas. Ele parece mais confuso do que mau. Talvez uma lição possa acalmá-lo.", {}, false) 
{
    objetivos.push_back({"Encontre e acalme Knut", false});

    recompensa.xp = 450;
    recompensa.itens.push_back(new ElixirDaVida());
}

void Missao_oLamentoDoOgro::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar();
    
    cout << "\nNos arredores de Magix, você ouve um barulho de destruição. É Knut, o ogro, esmurrando árvores e rochas." << endl;
    cout << "'Bruxas más me deixaram!', ele grita. 'Knut esmaga tudo agora!' Ele te vê e avança, cego pela frustração." << endl;
    mostrarProgresso();

    // Batalha contra o mini-chefe Knut
    Knut knut;
    vector<Inimigo*> inimigos = {&knut};
    Batalha batalha(fadaEscolhida, inimigos, invP, invA);
    bool vitoria = batalha.iniciar();

    if (!vitoria) {
        cout << "A força bruta de Knut foi demais... Missão falhou." << endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    
    // Conclusão e Recompensa
    cout << "\nApós a batalha, Knut se senta, exausto. 'Knut entendeu... Fada forte, mas não má como Trix. Knut para de quebrar coisas...'" << endl;
    cout << "Como agradecimento, ele te entrega uma poção que encontrou." << endl;
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