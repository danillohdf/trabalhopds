#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/reversi.hpp"
#include "../include/jogador.hpp"

// Teste para a sequência de jogadas que leva ao fim do jogo
TEST_CASE("Teste do jogo Reversi - Simulação de jogada completa") {
    // Criação dos jogadores
    Jogador jogador1("Testador1", "JogadorTeste");
    Jogador jogador2("Testadora2", "JogadoraTeste");

    // Inicialização do jogo Reversi
    Reversi jogo(jogador1, jogador2);

    // Jogadas para simular uma partida
    std::vector<std::pair<int, int>> jogadas = {
        {3, 4}, {5, 3}, {6, 2}, {3, 5}, {3, 6}, {2, 5}, {1, 6}, {3, 3},
        {3, 2}, {2, 4}, {6, 3}, {2, 6}, {1, 5}, {7, 1}, {4, 3}, {3, 2},
        {2, 1}, {5, 4}, {6, 5}, {3, 1}, {4, 1}, {1, 4}, {2, 7}, {3, 8},
        {1, 1}, {1, 2}, {2, 1}, {2, 2}, {6, 7}, {6, 8}, {5, 6}, {5, 7},
        {4, 6}, {5, 7}, {6, 5}, {7, 4}, {7, 5}, {7, 6}, {8, 1}, {7, 3},
        {8, 6}, {7, 7}, {8, 7}, {8, 8}, {7, 6}, {8, 6}, {7, 8}, {8, 7},
        {6, 7}, {7, 8}
    };

    bool jogadaValida;
    for (const auto& jogada : jogadas) {
        int linha = jogada.first;
        int coluna = jogada.second;

        Jogador* jogadorAtual = jogo.getJogadorAtual();
        jogadaValida = jogo.verificarJogada(linha, coluna, jogadorAtual);
        REQUIRE(jogadaValida);  // Verifica se a jogada é válida

        jogo.fazerJogada(linha, coluna, jogadorAtual);
    }

    REQUIRE(jogo.verificarFimDeJogo());  // Verifica se o jogo terminou
}
