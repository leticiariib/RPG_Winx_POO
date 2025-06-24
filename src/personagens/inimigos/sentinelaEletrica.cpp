#include "include\personagens\inimigos\sentinelaEletrica.h"
#include "include\habilidades\danoDireto\raioDeEnergia.h" 

SentinelaEletrica::SentinelaEletrica()
    // caracteristicas: status equilibrados, um soldado robótico padrão.

    : Inimigo("Sentinela Elétrica", 150, 60, 45, 60, 60) {
    
    this->nivel = 9;
    habilidades.push_back(new RaioDeEnergia());
}