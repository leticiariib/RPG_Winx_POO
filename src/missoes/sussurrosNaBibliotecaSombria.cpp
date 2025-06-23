#include "missoes\sussurrosNaBibliotecaSombria.h"
#include "batalha.h"
#include "personagens\inimigos\monstroDoPesadelo.h"
#include "personagens\inimigos\darcy.h"
#include "inventario\armaduras\braceleteConcentracao.h"
#include <vector>
#include <iostream>

Missao_SussurrosNaBiblioteca::Missao_SussurrosNaBiblioteca() 
    : MissaoPrincipal(3, "Sussurros na Biblioteca Sombria", "Darcy está corrompendo uma biblioteca antiga. Impeça-a antes que ela encontre o que procura.", {}, true) 
{
    objetivos.push_back({"Navegue pelas ilusões sombrias", false});
    objetivos.push_back({"Confronte a Bruxa das Ilusões", false});

    recompensa.xp = 1000;
    recompensa.itens.push_back(new BraceleteConcentracao());
}

void Missao_SussurrosNaBiblioteca::executar(Personagem& fadaEscolhida, Inventario<Pocao*>& invP, Inventario<Armadura*>& invA) {
    iniciar();
    
    std::cout << "\nVocê entra na biblioteca e as sombras dançam nas paredes. As palavras escritas nos livros parecem se contorcer, formando criaturas de pesadelo." << std::endl;
    mostrarProgresso();

    // Batalha 1: Contra os novos inimigos
    MonstroDoPesadelo pesadelo1, pesadelo2;
    std::vector<Inimigo*> grupoDePesadelos = {&pesadelo1, &pesadelo2};
    Batalha batalha1(fadaEscolhida, grupoDePesadelos, invP, invA);
    bool vitoria1 = batalha1.iniciar();

    if (!vitoria1) {
        std::cout << "Os pesadelos foram avassaladores... A missão falhou." << std::endl;
        resetar();
        return; 
    }

    objetivos[0].concluido = true;
    std::cout << "\nAo derrotar as criaturas, as ilusões se dissipam, revelando um grande salão onde Darcy está, levitando sobre um livro antigo." << std::endl;
    mostrarProgresso();
    
    std::cout << "'Tola! Você não pode parar o poder que encontrei aqui!', ela gargalha." << std::endl;

    // Batalha 2: Chefe Darcy
    Darcy darcy;
    std::vector<Inimigo*> chefe = {&darcy};
    Batalha batalha2(fadaEscolhida, chefe, invP, invA);
    bool vitoria2 = batalha2.iniciar();

    if (!vitoria2) {
        std::cout << "O poder sombrio de Darcy era forte demais... A missão falhou." << std::endl;
        resetar();
        return;
    }

    objetivos[1].concluido = true;
    
    // Conclusão e Recompensa
    std::cout << "\nDarcy foi derrotada e foge, deixando o livro para trás. A biblioteca está a salvo por enquanto." << std::endl;
    Recompensa recompensaFinal = completar(fadaEscolhida);

    std::cout << "\nItens recebidos como recompensa:" << std::endl;
    for (Item* itemRecompensa : recompensaFinal.itens) {
        Armadura* armadura = dynamic_cast<Armadura*>(itemRecompensa);
        if (armadura) {
            invA.adicionarItem(armadura);
        }
    }
    this->recompensa.itens.clear(); 
}