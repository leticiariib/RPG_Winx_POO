

#include <iostream>
#include <vector>
#include <memory>

#include "include/personagens/personagem.h"
#include "include/batalha.h"
#include "include/habilidades/habilidade.h"
#include "include/inventario/inventario.h"
#include "include/inventario/item.h"
#include "include/inventario/armaduras/armadura.h"
#include "include/inventario/armaduras/braceleteConcentracao.h"
#include "include/inventario/armaduras/capaDeGuardia.h"
#include "include/inventario/armaduras/mantoDeEnchantrix.h"
#include "include/inventario/pocoes/elixirDaVida.h"
#include "include/inventario/pocoes/pocoes.h"
#include "include/inventario/pocoes/poDeFada.h"

#include "include/habilidades/danoContinuo/chamasPersistentes.h"
#include "include/habilidades/danoContinuo/curtoCircuito.h"
#include "include/habilidades/danoContinuo/esporosVenenosos.h"
#include "include/habilidades/danoContinuo/nevascaCongelante.h"
#include "include/habilidades/danoContinuo/rajadaSombria.h"
#include "include/habilidades/danoContinuo/redemoinho.h"

#include "include/habilidades/danoDireto/chamaDoDragao.h"
#include "include/habilidades/danoDireto/estilhacoDeGelo.h"
#include "include/habilidades/danoDireto/jatoDeAgua.h"
#include "include/habilidades/danoDireto/mareAscendente.h"
#include "include/habilidades/danoDireto/ondaSonora.h"
#include "include/habilidades/danoDireto/pancadaRochosa.h"
#include "include/habilidades/danoDireto/pancadaSombria.h"
#include "include/habilidades/danoDireto/raioDeEnergia.h"
#include "include/habilidades/danoDireto/relampago.h"
#include "include/habilidades/danoDireto/setaDasTrevas.h"

#include "include/missoes/controladorDeMissoes.h"
#include "include/missoes/missao.h"

#include "include/habilidades/nivelAlto/abracoDaNatureza.h"
#include "include/habilidades/nivelAlto/crescendoEstilhacante.h"
#include "include/habilidades/nivelAlto/firewallDigital.h"
#include "include/habilidades/nivelAlto/fortificar.h"
#include "include/habilidades/nivelAlto/furacaoDestruidor.h"
#include "include/habilidades/nivelAlto/furiaDoDragao.h"
#include "include/habilidades/nivelAlto/ondaDeHipnose.h"
#include "include/habilidades/nivelAlto/pilarDeAgua.h"
#include "include/habilidades/nivelAlto/superNova.h"
#include "include/habilidades/nivelAlto/vazioAbsoluto.h"

#include "include/personagens/personagem.h"
#include "include/personagens/fadas/aisha.h"
#include "include/personagens/fadas/bloom.h"
#include "include/personagens/fadas/flora.h"
#include "include/personagens/fadas/musa.h"
#include "include/personagens/fadas/stella.h"
#include "include/personagens/fadas/tecna.h"

#include "include/personagens/inimigos/darcy.h"
#include "include/personagens/inimigos/icy.h"
#include "include/personagens/inimigos/stormy.h"
#include "include/personagens/inimigos/ghoul.h"
#include "include/personagens/inimigos/golemDePedra.h"
#include "include/personagens/inimigos/feiticeiroDeTorrenuvosa.h"
#include "include/personagens/inimigos/monstroDoPantano.h"



using namespace std;

void mostrarMenuHabilidades(Personagem& p) {
    cout << "\nHabilidades de " << p.getNome() << ":\n";
    for (int i = 0; i < p.getHabilidades().size(); ++i) {
        cout << "  [" << i << "] " << p.getHabilidades()[i]->getNome() << endl;
    }
}

int main() {
    cout << "==== INICIANDO SIMULACAO DE BATALHA ====\n";

    Bloom bloom;
    Musa musa;
    Flora flora;
    Aisha aisha;
    Stella stella;
    Tecna tecna;


    bloom.ganharXP(1000);  
    musa.ganharXP(700);    
    flora.ganharXP(1000);  
    aisha.ganharXP(800);   
    stella.ganharXP(800);  
    tecna.ganharXP(1000);   

    Darcy darcy;
    Icy icy;
    Stormy stormy;
    Ghoul ghoul;
    GolemDePedra golem;
    FeiticeiroDeTorrenuvosa feiticeiro;
    MonstroDoPantano monstro;

    cout << "\n==== SIMULANDO COMBATE ====\n";

    bloom.mostarStatus();
    darcy.mostarStatus();

    mostrarMenuHabilidades(bloom);
    bloom.usarHabilidade(0, darcy); 
    darcy.prepararParaNovoTurno();

    mostrarMenuHabilidades(bloom);
    bloom.usarHabilidade(1, darcy); 
    darcy.prepararParaNovoTurno();

    bloom.usarHabilidade(2, darcy); 
    darcy.prepararParaNovoTurno();

    cout << "\n==== STATUS FINAL ====\n";
    bloom.mostarStatus();
    darcy.mostarStatus();

    cout << "\n==== FIM DA SIMULACAO ====\n";
    return 0;
}
