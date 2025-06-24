#include "personagens/inimigos/golemDePedra.h"
#include "habilidades/danoDireto/pancadaRochosa.h"
#include "habilidades/nivelAlto/fortificar.h"

GolemDePedra::GolemDePedra()
    // caracteristicas: inimigo fraco
    : Inimigo("Golem de Pedra", 180, 20, 55, 20, 20) {
    
    this->nivel = 6;
    habilidades.push_back(new PancadaRochosa());
    habilidades.push_back(new Fortificar());
}