#include "personagens/inimigos/ghoul.h"
#include "habilidades/danoDireto/pancadaSombria.h" // Habilidade do Ghoul

Ghoul::Ghoul()
    // status baixo no geral, inimigo para o início do jogo.

    : Inimigo("Ghoul de Torrenuvosa", 50, 20, 10, 15, 50) {
    
    habilidades.push_back(new PancadaSombria());
}