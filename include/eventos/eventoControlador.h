#ifndef EVENTO_CONTROLADOR_H
#define EVENTO_CONTROLADOR_H

class EventoControlador {
private:
    int contadorTurnos;
    int intervalo;

public:
    EventoControlador(int intervaloInicial = 3); //a cada 3 turnos 1 evento acontece, ajustavel por aqui
    bool deveDispararEvento();
    void avancarTurno();
};

#endif
