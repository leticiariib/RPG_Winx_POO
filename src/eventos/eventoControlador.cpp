#include "eventos/eventoControlador.h"

EventoControlador::EventoControlador(int intervaloInicial)
    : intervalo(intervaloInicial), contadorTurnos(0) {}

void EventoControlador::avancarTurno() {
    contadorTurnos++;
}

bool EventoControlador::deveDispararEvento() {
    if (contadorTurnos >= intervalo) {
        contadorTurnos = 0;
        return true;
    }
    return false;
}
