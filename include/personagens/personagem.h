#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>

using namespace std;

class Personagem{
    protected:
        string nome;
        int vida;
        float mana; //energia mágica
        float ataque_magico;
        float defesa;
    public:
        Personagem(string n, int v, float m, float am, float d)
            : nome{n}, vida{v}, mana{m}, ataque_magico{am}, defesa{d} {}

        virtual void receberDano(float dano){
            vida -= dano;
            if(vida < 0)
                vida = 0;
        }

        virtual void mostarStatus() const {
            cout << nome << " - Vida: " << vida << " - Mana: " << mana << endl;
        }

        float getAtaqueMagico() const {return ataque_magico;}
         float getDefesa() const {return defesa;}
};

#endif
