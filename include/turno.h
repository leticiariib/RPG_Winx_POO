#ifndef TURNO_H
#define TURNO_H

class Turno {
private:
    int numeroTurno;

public:
    Turno() : numeroTurno(1) {}

    void proximoTurno() {
        numeroTurno++;
    }

    int getTurnoAtual() const {
        return numeroTurno;
    }
};

#endif
