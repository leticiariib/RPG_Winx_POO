#ifndef RECOMPENSA_H
#define RECOMPENSA_H

#include <vector>
#include "inventario/item.h" 

using namespace std; 

struct Recompensa {
    int xp = 0;
    vector<Item*> itens;
};

#endif