#ifndef CONTROLADOR_DE_MISSOES_H
#define CONTROLADOR_DE_MISSOES_H

#include <vector>
#include <map>
#include "missao.h"

class ControladorDeMissoes {
private:
    std::map<int, Missao*> missoes; // Usar um mapa para acesso rápido por ID

public:
    ~ControladorDeMissoes();

    void adicionarMissao(Missao* novaMissao);
    void mostrarMissoesDisponiveis() const;
    void mostrarMissoesAtivas() const;
    Missao* getMissao(int id);
};

#endif