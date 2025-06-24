#include "personagens/inimigos/stormy.h"
#include "habilidades/danoDireto/relampago.h"
#include "habilidades/nivelAlto/furacaoDestruidor.h"
#include "habilidades/danoContinuo/redemoinho.h" // Habilidade existente

Stormy::Stormy()
    // caracteristicas de chefe 3: Ataque Mágico altíssimo, mas Defesa e Vida mais baixas.
    : Chefe("Stormy, Bruxa das Tempestades", 230, 130, 40, 95, 78) {
    
    this->nivel = 10;

    habilidades.push_back(new RelampagoFulgurante()); // Dano direto e rápido
    habilidades.push_back(new Redemoinho());          // Dano contínuo
    habilidades.push_back(new FuracaoDestruidor());   // Dano massivo com perfuração
}