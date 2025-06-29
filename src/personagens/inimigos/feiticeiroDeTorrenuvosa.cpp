#include "personagens/inimigos/feiticeiroDeTorrenuvosa.h"
#include "habilidades/danoContinuo/rajadaSombria.h" 
#include "habilidades/danoDireto/setaDasTrevas.h"

//inimigo medio 
FeiticeiroDeTorrenuvosa::FeiticeiroDeTorrenuvosa()
    : Inimigo("Feiticeiro de Torrenuvosa", 70, 50, 25, 50, 60) {

    this->nivel = 7;
    habilidades.push_back(new SetaDasTrevas());
    habilidades.push_back(new RajadaSombria());
}