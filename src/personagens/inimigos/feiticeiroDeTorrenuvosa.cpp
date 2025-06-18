#include "feiticeiroDeTorrenuvosa.h"
#include "rajadaSombria.h" 
#include "setaDasTrevas.h"

//inimigo medio 
FeiticeiroDeTorrenuvosa::FeiticeiroDeTorrenuvosa()
    : Inimigo("Feiticeiro de Torrenuvosa", 110, 100, 25, 70, 60) {

    this->nivel = 7;
    habilidades.push_back(new SetaDasTrevas());
    habilidades.push_back(new RajadaSombria());
}