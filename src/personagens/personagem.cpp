#include "personagens/personagem.h"
#include "habilidades/habilidade.h"
#include <cmath> 
#include <string> 

using namespace std; 

Personagem::~Personagem() {
    for (Habilidade* hab : habilidades) {
        delete hab;
    }
    habilidades.clear();
}

void Personagem::receberDano(float dano) {
    if (dano < 0) dano = 0;
    vida -= dano;
    if (vida < 0) vida = 0;
    cout << nome << " recebeu " << dano << " de dano. Vida restante: " << vida << "\n";
}

void Personagem::defender() {
    cout << nome << " está se defendendo, dobrando sua defesa para o próximo ataque!" << endl;
    defesa *= 2; // Dobra a defesa temporariamente
    estaDefendendo = true;
}

// chamar esse metodo no início de cada turno do personagem
void Personagem::prepararParaNovoTurno() {
    if (estaDefendendo) {
        defesa = defesaBase;
        estaDefendendo = false;
    }
    // Recupera 10% da magia máxima a cada turno.
    float regenMagia = this->magiaMaxima * 0.1f; 
    this->magia += regenMagia;
    if (this->magia > this->magiaMaxima) {
        this->magia = this->magiaMaxima; // garante que não ultrapasse o máximo
    }
    atualizarTurno();
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

void Personagem::ganharXP(int xpGanho) {
    if (!estaVivo()) return;

    xpAtual += xpGanho;
    cout << nome << " ganhou " << xpGanho << " de XP!" << endl;

    // Loop para o caso de o personagem subir múltiplos níveis de uma vez
    while (xpAtual >= xpParaProximoNivel) {
        subirDeNivel();
    }
}

void Personagem::subirDeNivel() {
    nivel++;
    cout << "----------------------------------------" << endl;
    cout << nome << " subiu para o Nível " << nivel << "!" << endl;
    cout << "----------------------------------------" << endl;
    
    xpAtual -= xpParaProximoNivel; 
    xpParaProximoNivel = static_cast<int>(xpParaProximoNivel * 1.5);

    //valores de atributos aumentados por subir de nivel
    int crescimentoVida = 25;
    int crescimentoMagia = 15;
    float crescimentoAtaque = 8;
    float crescimentoDefesa = 5;

    vidaMaxima += crescimentoVida;
    magiaMaxima += crescimentoMagia;
    ataque_magico += crescimentoAtaque;
    defesa += crescimentoDefesa;
    defesaBase = defesa;

    // recupera toda a vida e magia ao subir de nível
    vida = vidaMaxima;
    magia = magiaMaxima;

    cout << "Vida Máxima: +" << crescimentoVida << endl;
    cout << "Magia Máxima: +" << crescimentoMagia << endl;
    cout << "Ataque Mágico: +" << crescimentoAtaque << endl;
    cout << "Defesa: +" << crescimentoDefesa << endl;

    checarDesbloqueioHabilidades();
}

void Personagem::usarHabilidade(int indiceHabilidade, Personagem& alvo) {
    if (indiceHabilidade < 0 || indiceHabilidade >= habilidades.size()) {
        cout << "Índice de habilidade inválido!" << endl;
        return;
    }

    Habilidade* habilidadeEscolhida = habilidades[indiceHabilidade];
    
    float fatorReducao = getFatorReducaoCustoMagia();
    float custoFinal = habilidadeEscolhida->getCusto() * fatorReducao;

    if (magia >= custoFinal) {
        magia -= custoFinal;
        cout << nome << " usou '" << habilidadeEscolhida->getNome() 
             << "' gastando " << custoFinal << " de magia." << endl;
        habilidadeEscolhida->aplicar(*this, alvo);
    } else {
        cout << nome << " não tem magia suficiente para usar '" << habilidadeEscolhida->getNome() 
             << "'. Custo necessário: " << custoFinal << ", Magia disponível: " << round(magia) << endl;
    }
}

void Personagem::atualizarTurno() {
    // processando efeitos contínuos 
    for (auto it = efeitos.begin(); it != efeitos.end(); ) {    
        // se tiver palavra "dano" no tipo será válido 
        if (it->tipo.find("dano") != string::npos) {
            cout << nome << " sofre " << it->dano_por_turno << " de dano de '" << it->tipo << "'!" << endl;
            receberDano(it->dano_por_turno);
        } 
        it->duracao--;
        // se a duração acabou, remove o efeito da lista
        if (it->duracao <= 0) {
            cout << "O efeito '" << it->tipo << "' em " << nome << " acabou." << endl;
            it = efeitos.erase(it); // erase() retorna o próximo iterador válido
        } else {
            ++it; // Se não removeu, avança para o próximo
        }
    }

    // processar buffs temporários 
    for (auto it_buff = buffs.begin(); it_buff != buffs.end(); ) {
        it_buff->duracao--;

        if (it_buff->duracao <= 0) {
            cout << "O buff '" << it_buff->tipo << "' em " << nome << " acabou." << endl;
            // Se o tipo do buff CONTÉM a palavra "defesa", remove o bônus de defesa.
            if (it_buff->tipo.find("defesa") != string::npos) {
                this->defesa -= it_buff->valor;
                if (this->defesa < this->defesaBase) {
                    this->defesa = this->defesaBase; // Garante que a defesa não fique menor que a base
                }
                cout << nome << " perdeu um bônus de defesa." << endl;
            } 
            else if (it_buff->tipo.find("reducao_custo_magia") != string::npos) {
                cout << nome << " não tem mais redução no custo de magia." << endl;
            }
            it_buff = buffs.erase(it_buff);
        } else {
            ++it_buff;
        }
    }
}

void Personagem::mostrarStatusCompleto() const {
    cout << "\n===== FICHA DE " << nome << " =====" << endl;
    cout << "Nível: " << nivel << endl;
    cout << "XP: " << xpAtual << " / " << xpParaProximoNivel << endl;
    cout << "--------------------------" << endl;
    cout << "Vida: " << vida << " / " << vidaMaxima << endl;
    cout << "Magia: " << round(magia) << " / " << round(magiaMaxima) << endl;
    cout << "--------------------------" << endl;
    cout << "Ataque Mágico: " << ataque_magico << endl;
    cout << "Defesa: " << defesa << endl;
    cout << "Velocidade: " << velocidade << endl;
    cout << "--------------------------" << endl;
    cout << "Habilidades Conhecidas:" << endl;
    
    if (habilidades.empty()) {
        cout << "  Nenhuma habilidade conhecida." << endl;
    } else {
        for (int i = 0; i < habilidades.size(); ++i) {
            cout << "  " << i + 1 << ". " << habilidades[i]->getNome() << endl;
        }
    }
    cout << "==========================\n" << endl;
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

void Personagem::recuperarVida(float quantidade) {
    vida += quantidade;
    if (vida > vidaMaxima) vida = vidaMaxima;
    cout << nome << " recuperou " << quantidade << " de vida!" << endl;
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

void Personagem::recuperarTudo() {
    this->vida = this->vidaMaxima;
    this->magia = this->magiaMaxima;
    cout << getNome() << " teve sua energia totalmente restaurada!" << endl;
}

void Personagem::ajustarVidaMaxima(float multiplicador) {
        this->vidaMaxima = static_cast<int>(this->vidaMaxima * multiplicador);
        if (this->vida > this->vidaMaxima) {
            this->vida = this->vidaMaxima;
        }
}

