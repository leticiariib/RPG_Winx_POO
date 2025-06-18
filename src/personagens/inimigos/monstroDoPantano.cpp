#include "monstroDoPantano.h"
#include "pancadaSombria.h"
#include "rajadaSombria.h" 
MonstroDoPantano::MonstroDoPantano()
    //inimigo fraco pra medio
    : Inimigo("Monstro do Pântano", 150, 40, 40, 35, 40) {
 
    habilidades.push_back(new PancadaSombria());
    habilidades.push_back(new RajadaSombria());
}