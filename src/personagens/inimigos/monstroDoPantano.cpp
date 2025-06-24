#include "personagens/inimigos/monstroDoPantano.h"
#include "habilidades/danoDireto/pancadaSombria.h"
#include "habilidades/danoContinuo/rajadaSombria.h" 
MonstroDoPantano::MonstroDoPantano()
    //inimigo p/ inicio do jogo
    : Inimigo("Monstro do Pântano", 90, 30, 25, 35, 40) {
 
    habilidades.push_back(new PancadaSombria());
    habilidades.push_back(new RajadaSombria());
}