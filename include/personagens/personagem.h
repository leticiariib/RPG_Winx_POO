#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Personagem{
    protected:
        string nome;
        int vida;
        float magia; //energia mágica
        float defesa;
        int velocidade; 
        float ataque_magico;
        vector<EfeitoContinuo> efeitos;
    public:
        Personagem(string n, int v, float m, float am, float d, int velo)
        : nome{n}, vida{v}, magia{m}, ataque_magico{am}, defesa{d}, velocidade{velo} {}
        struct EfeitoContinuo{
        string tipo;
        int dano_por_turno;
        int duracao;
        };
        
        virtual void receberDano(float dano){
            if (dano < 0) dano = 0;
            vida -= dano;
            if (vida < 0) vida = 0;
            cout << nome << " recebeu " << dano << " de dano. Vida restante: " << vida <<"\n";
        }

         void reduzirVelocidade(int quantidade) {
            velocidade -= quantidade;
            if (velocidade < 0) velocidade = 0;
            cout << nome << " teve a velocidade reduzida em " << quantidade
                << ". Nova velocidade: " << velocidade << "\n";
        }

        bool estaVivo() const {return vida > 0;}

        void aplicarEfeito(EfeitoContinuo& efeito) {
           efeitos.push_back(efeito);
           cout << nome << " recebeu efeito: " << efeito.tipo << " por "
              << efeito.duracao << " turnos.\n";
        }

        void atualizarTurno() {
            for (int i = 0; i < efeitos.size(); ++i) {
                if (efeitos[i].tipo == "dano") {
                    receberDano(efeitos[i].dano_por_turno);
                }
                efeitos[i].duracao--;
                if (efeitos[i].duracao <= 0) {
                    efeitos.erase(efeitos.begin() + i);
                    --i;
                }
            }
        }

        virtual void mostarStatus() const {
            cout <<"Status de "<< nome << " - Vida: " << vida << " - Magia: " << magia << endl;
        }

        string getNome() const {return nome;}
        float getAtaque() const {return ataque_magico;}
        float getDefesa() const {return defesa;}
        int getVelocidade() const {return velocidade;}
};

#endif
