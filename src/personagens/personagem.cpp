#include "personagem.h"
#include <cmath> 

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
    int crescimentoVida = 15;
    int crescimentoMagia = 10;
    float crescimentoAtaque = 5;
    float crescimentoDefesa = 3;

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

