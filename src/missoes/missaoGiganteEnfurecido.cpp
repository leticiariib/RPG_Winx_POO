#include "missoes\missaoGiganteEnfurecido.h"
#include "batalha.h"
#include "personagens\inimigos\golemDePedra.h"
#include "inventario\armaduras\capaDeGuardia.h" 
#include <vector>
#include <iostream>

Missao_GiganteEnfurecido::Missao_GiganteEnfurecido() 
    // o último parâmetro 'false' indica que esta NÃO é uma missão principal
    : MissaoSecundaria(4, "O Gigante Enfurecido", "Um Golem de Pedra pacífico enlouqueceu perto de um vilarejo. Acalme-o antes que ele cause mais destruição.", {}, false) 
{
    objetivos.push_back({"Acalme o Golem de Pedra", false});

    recompensa.xp = 400;
    recompensa.itens.push_back(new CapaDaGuardia());
}

void Missao_GiganteEnfurecido::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar();
    
    std::cout << "\nUm aldeão assustado te guia até a pedreira. 'Ele sempre nos protegeu', diz ele, 'mas agora... ele só enxerga inimigos!'" << std::endl;
    std::cout << "Você encontra o Golem de Pedra, seus olhos de cristal brilhando com uma luz sombria. Ele se vira e ataca sem hesitar!" << std::endl;
    mostrarProgresso();

    GolemDePedra golem;
    std::vector<Inimigo*> inimigos = {&golem};
    Batalha batalha(fadaEscolhida, inimigos, invP, invA);
    bool vitoria = batalha.iniciar();

    if (!vitoria) {
        std::cout << "A defesa do Golem era impenetrável... A missão falhou." << std::endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    
    // Conclusão e Entrega da Recompensa
    std::cout << "\nCom a derrota, a luz sombria nos olhos do Golem se apaga. Ele se senta pacificamente. A corrupção do Orbe o estava enlouquecendo." << std::endl;
    Recompensa recompensaFinal = completar(fadaEscolhida);

    std::cout << "\nItens recebidos como recompensa pela sua ajuda:" << std::endl;
    for (Item* itemRecompensa : recompensaFinal.itens) {
        Armadura* armadura = dynamic_cast<Armadura*>(itemRecompensa);
        if (armadura) {
            invA.adicionarItem(armadura);
        }
    }
    this->recompensa.itens.clear(); 
}