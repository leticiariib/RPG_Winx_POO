#include "personagens\inimigos\sentinelaEletrica.h"
#include "habilidades\danoDireto\raioDeEnergia.h" 

SentinelaEletrica::SentinelaEletrica()
    // caracteristicas: status equilibrados, um soldado robótico padrão.

    : Inimigo("Sentinela Elétrica", 95, 60, 45, 50, 60) {
    
    this->nivel = 9;
    habilidades.push_back(new RaioDeEnergia());
}