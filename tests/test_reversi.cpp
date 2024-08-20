#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/reversi.hpp"
#include "../include/jogador.hpp"

// Função auxiliar para converter coordenadas de string para (linha, coluna)
std::pair<int, int> converterParaCoordenadas(const std::string& coordenada, const Reversi& jogo) {
    return jogo.converterEntrada(coordenada);
}

// Teste para a sequência de jogadas que leva ao fim do jogo
TEST_CASE("Teste do jogo Reversi - Simulação de jogada completa") {
    // Criação dos jogadores
    Jogador jogador1("Testador1", "JogadorTeste");
    Jogador jogador2("Testadora2", "JogadoraTeste");

    // Inicialização do jogo Reversi
    Reversi jogo(jogador1, jogador2);

    // Jogadas para simular uma partida no formato de coordenadas com letras
    std::vector<std::string> jogadasStr = {
        "d3", "c5", "b6", "e3", "f3", "e2", "f1", "c3",
        "b3", "d2", "c6", "f2", "e1", "a7", "c4", "c2",
        "c1", "f4", "g5", "a3", "a4", "d1", "g1", "h1",
        "b2", "b1", "g2", "h2", "a2", "a1", "f5", "b4",
        "a6", "d6", "b5", "h6", "g4", "h4", "h3", "g3",
        "h5", "g6", "f6", "e6", "a8", "c7", "e7", "e8",
        "d7", "d8", "c8", "a5", "f8", "f7", "h7", "h8",
        "b7", "b8", "g7", "g8"
    };

    bool jogadaValida;
    for (const auto& jogadaStr : jogadasStr) {
        // Converte a coordenada de string para (linha, coluna)
        std::pair<int, int> coordenada = converterParaCoordenadas(jogadaStr, jogo);
        int linha = coordenada.first;
        int coluna = coordenada.second;

        Jogador* jogadorAtual = jogo.getJogadorAtual();
        jogadaValida = jogo.verificarJogada(linha, coluna, jogadorAtual);
        REQUIRE(jogadaValida);  // Verifica se a jogada é válida

        jogo.fazerJogada(linha, coluna, jogadorAtual);
    }

    REQUIRE(jogo.verificarFimDeJogo());  // Verifica se o jogo terminou
}