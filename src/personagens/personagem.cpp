#include "personagem.h"

Personagem::Personagem(string n, int v, float m, float am, float d, int velo)
    : nome{n}, vida{v}, magia{m}, ataque_magico{am}, defesa{d}, velocidade{velo} {}

void Personagem::receberDano(float dano) {
    if (dano < 0) dano = 0;
    vida -= dano;
    if (vida < 0) vida = 0;
    cout << nome << " recebeu " << dano << " de dano. Vida restante: " << vida << "\n";
}

void Personagem::reduzirVelocidade(int quantidade) {
    velocidade -= quantidade;
    if (velocidade < 0) velocidade = 0;
    cout << nome << " teve a velocidade reduzida em " << quantidade
         << ". Nova velocidade: " << velocidade << "\n";
}

void Personagem::aplicarEfeito(EfeitoContinuo& efeito) {
    efeitos.push_back(efeito);
    cout << nome << " recebeu efeito: " << efeito.tipo << " por "
         << efeito.duracao << " turnos.\n";
}

void Personagem::usarHabilidade(Habilidade& habilidade, Personagem& alvo) {
    float fatorReducao = getFatorReducaoCustoMagia();
    float custoFinal = habilidade.getCusto() * fatorReducao;

    if (magia >= custoFinal) {
        magia -= custoFinal;
        cout << nome << " usou a habilidade '" << habilidade.getNome() << "' gastando " << custoFinal << " de magia." << endl;
        habilidade.aplicar(*this, alvo); 
    } else {
        cout << nome << " não tem magia suficiente para usar '" << habilidade.getNome() << "'." << endl;
    }
}

void Personagem::atualizarTurno() {
    // Processar efeitos de dano contínuo
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

    // Processar buffs temporários
    for (int i = 0; i < buffs.size(); ++i) {
        buffs[i].duracao--;

        if (buffs[i].duracao <= 0) {
            if (buffs[i].tipo == "defesa") {
                defesa -= buffs[i].valor;
                cout << nome << " perdeu o bônus de defesa de " << buffs[i].valor << "." << endl;
            }
            else if (buffs[i].tipo == "reducao_custo_magia") {
                cout << nome << " perdeu o efeito de redução de custo de magia." << endl;
            }
            else if (buffs[i].tipo == "invisibilidade") {
                cout << nome << " não está mais invisível." << endl;
            }

            buffs.erase(buffs.begin() + i);
            --i;
        }
    }
}

void Personagem::mostarStatus() const {
    cout << "Status de " << nome << " - Vida: " << vida
         << " - Magia: " << magia << endl;
}

void Personagem::recuperarVidaPercentual(float porcentagem) {
    int vidaRecuperada = static_cast<int>(vidaMaxima * porcentagem);
    vida += vidaRecuperada;
    if (vida > vidaMaxima) vida = vidaMaxima;
    cout << nome << " recuperou " << vidaRecuperada << " pontos de vida!" << endl;
}

void Personagem::recuperarMagiaPercentual(float porcentagem) {
    float magiaRecuperada = magiaMaxima * porcentagem;
    magia += magiaRecuperada;
    if (magia > magiaMaxima) magia = magiaMaxima;
    cout << nome << " recuperou " << magiaRecuperada << " pontos de magia!" << endl;
}

void Personagem::aumentarDefesaTemporaria(float porcentagem, int turnos) {
    float aumento = defesaBase * porcentagem;
    defesa += aumento;

    BuffTemporario buff;
    buff.tipo = "defesa";
    buff.valor = aumento;
    buff.duracao = turnos;

    buffs.push_back(buff);

    cout << nome << " ganhou +" << aumento << " de defesa por " << turnos << " turnos!" << endl;
}


void Personagem::adicionarReducaoDeDano(float porcentagem) {
    reducaoDeDano += porcentagem;
    cout << nome << " agora recebe " << (porcentagem * 100) << "% a menos de dano enquanto o efeito durar!" << endl;
}

void Personagem::adicionarBuff(const BuffTemporario& buff) {
            buffs.push_back(buff);
}

float Personagem::getFatorReducaoCustoMagia() const {
    float fator = 1.0f;
    for (const auto& buff : buffs) {
        if (buff.tipo == "reducao_custo_magia") {
            fator *= buff.valor; 
        }
    }
    return fator;
}

