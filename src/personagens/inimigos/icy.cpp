#include "icy.h"
#include "estilhacoDeGelo.h" 
#include "nevascaCongelante.h" 

Icy::Icy()
    // chefona: vida alta, ataque mágico muito alto, boa defesa

    : Chefe("Icy, Bruxa do Gelo", 400, 200, 60, 85, 75) {
    
    this->nivel = 10; 

    habilidades.push_back(new EstilhacoDeGelo());
    habilidades.push_back(new NevascaCongelante());
}