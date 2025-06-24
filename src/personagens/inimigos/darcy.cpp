#include "personagens/inimigos/darcy.h"
#include "habilidades/danoContinuo/rajadaSombria.h" // Habilidade existente
#include "habilidades/nivelAlto/ondaDeHipnose.h"
#include "habilidades/nivelAlto/vazioAbsoluto.h"

Darcy::Darcy()
    // cefe hipnotica, caracteristicas: Magia e Velocidade altas, Ataque bom, Defesa mediana.

    : Chefe("Darcy, Bruxa das Ilusões", 230, 120, 50, 80, 80) {
    
    this->nivel = 10;

    habilidades.push_back(new RajadaSombria()); // Dano contínuo
    habilidades.push_back(new OndaDeHipnose());   // Dano com debuff
    habilidades.push_back(new VazioAbsoluto());   // Dano com roubo de vida
}