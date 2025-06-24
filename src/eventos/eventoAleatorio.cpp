#include "eventos/eventoAleatorio.h"
#include <iostream>

EventoAleatorio::EventoAleatorio() {
    rng.seed(random_device{}());
    inicializarEventos();
}

void EventoAleatorio::inicializarEventos() {
    eventos.clear();

    // evento 01
    Evento e1;
    e1.titulo = "Explosao Magica!";
    e1.descricao = "Uma explosao magica inesperada ocorre perto de voce nos corredores de Alfea.";

    Opcao o1;
    o1.descricao = "Tentar conter a explosao (perde magia)";
    o1.impactoMagia = -10;
    o1.mensagemFinal = "Voce conseguiu estabilizar a magia, mas se cansou.";

    Opcao o2;
    o2.descricao = "Correr para longe (nada acontece)";
    o2.mensagemFinal = "Voce se afastou a tempo. Ufa!";

    e1.opcoes = {o1, o2};
    eventos.push_back(e1);

    // seg evento
    Evento e2;
    e2.titulo = "Fonte Curativa";
    e2.descricao = "Voce encontra uma antiga fonte de agua encantada nos jardins.";

    Opcao o3;
    o3.descricao = "Beber da agua (recupera vida)";
    o3.impactoVida = +15;
    o3.mensagemFinal = "Sua energia foi restaurada com a agua magica!";

    Opcao o4;
    o4.descricao = "Ignorar e seguir em frente";
    o4.mensagemFinal = "Voce prefere nao arriscar.";

    e2.opcoes = {o3, o4};
    eventos.push_back(e2);

    // terceiro evento
    Evento e3;
    e3.titulo = "Livro Voador";
    e3.descricao = "Um grimorio voador escapa das estantes!";

    Opcao o5;
    o5.descricao = "Perseguir e capturar (perde vida)";
    o5.impactoVida = -5;
    o5.mensagemFinal = "Voce o pegou, mas bateu a cabeca!";

    Opcao o6;
    o6.descricao = "Deixar ele ir";
    o6.mensagemFinal = "O livro foge, mas nada de ruim acontece.";

    e3.opcoes = {o5, o6};
    eventos.push_back(e3);
}

EventoAleatorio::Evento EventoAleatorio::sortearEvento() {
    uniform_int_distribution<> dist(0, eventos.size() - 1);
    return eventos[dist(rng)];
}

void EventoAleatorio::executarOpcao(const Opcao& opcao, Personagem& personagem) {
    if (opcao.impactoVida != 0) {
        int novaVida = personagem.getVida() + opcao.impactoVida;
        personagem.setVida(novaVida);
    }
    if (opcao.impactoMagia != 0) {
        int novaMagia = personagem.getMagia() + opcao.impactoMagia;
        personagem.setMagia(novaMagia);
    }
    std::cout << "\n[" << opcao.mensagemFinal << "]\n";
}
