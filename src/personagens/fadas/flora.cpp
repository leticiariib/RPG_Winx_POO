#include "personagens/fadas/flora.h"
#include "habilidades/danoDireto/jatoDeAgua.h"
#include "habilidades/danoContinuo/esporosVenenosos.h"
#include "habilidades/nivelAlto/abracoDaNatureza.h" // Habilidade de Nível Alto

Flora::Flora() : Personagem("Flora", 120, 100, 50, 60, 60) {
    // Caract. : vida e Defesa altas, ideal para batalhas longas

    habilidades.push_back(new JatoDeAgua());
    habilidades.push_back(new EsporosVenenosos());
}

bool Flora::temHabilidade(const string& nomeHabilidade) const {
    for (const auto& hab : habilidades) {
        if (hab->getNome() == nomeHabilidade) return true;
    }
    return false;
}

void Flora::checarDesbloqueioHabilidades() {
    // No Nível 5, Flora aprofunda sua conexão com a natureza para se proteger.
    if (getNivel() >= 5 && !temHabilidade("Abraço da Natureza")) {
        habilidades.push_back(new AbracoDaNatureza());
        cout << getNome() << " ouviu o chamado da natureza e desbloqueou: Abraço da Natureza!" << endl;
    }
}