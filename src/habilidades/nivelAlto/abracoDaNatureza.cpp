#include "habilidades/nivelAlto/abracoDaNatureza.h"
#include "personagens/personagem.h"
#include <iostream>

AbracoDaNatureza::AbracoDaNatureza()
    : Habilidade("Abraço da Natureza", 50, 40) {} // "Dano base" aqui será usado como "cura base"

void AbracoDaNatureza::aplicar(Personagem& atacante, Personagem& alvo) {
    float cura = dano_base + atacante.getAtaque() * 0.5; // A cura escala com o poder mágico
    
    atacante.recuperarVida(cura); 

    cout << atacante.getNome() << " usou o Abraço da Natureza, recuperando "
         << cura << " pontos de vida!\n";
}

void AbracoDaNatureza::mostrarDetalhes() const {
    cout << "- " << nome << " (Ultimate) -" << endl;
    cout << "Tipo: Cura (Natureza)" << endl;
    cout << "Cura base: " << dano_base << endl;
    cout << "Custo de magia: " << custo_magia << endl;
    cout << "Descrição: Canaliza a energia vital da natureza para curar ferimentos profundos." << endl;
}