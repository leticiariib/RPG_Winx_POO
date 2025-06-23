#include "personagens/inimigos/golemDePedra.h"
#include "habilidades/danoDireto/pancadaRochosa.h"
#include "habilidades/nivelAlto/fortificar.h"

GolemDePedra::GolemDePedra()
    // caracteristicas: Vida e Defesa massivas, Ataque e Velocidade muito baixos. Acho que seria bom p/ inicio/meio jogo
    : Inimigo("Golem de Pedra", 250, 20, 80, 25, 20) {
    
    this->nivel = 6;
    habilidades.push_back(new PancadaRochosa());
    habilidades.push_back(new Fortificar());
}