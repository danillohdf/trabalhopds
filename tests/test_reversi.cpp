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
        {2, 3}, {4, 5}, {5, 6}, {2, 4}, {5, 5}, {2, 2}, {1, 5}, {3, 2},
        {2, 6}, {1, 4}, {2, 5}, {5, 4}, {1, 2}, {0, 6}, {2, 1}, {2, 0},
        {5, 7}, {6, 5}, {0, 3}, {1, 3}, {1, 0}, {0, 5}, {7, 0}, {7, 1},
        {5, 2}, {4, 3}, {5, 6}, {7, 3}, {5, 1}, {4, 1}, {7, 2}, {7, 4},
        {6, 6}, {6, 7}, {5, 3}, {4, 0}, {3, 1}, {2, 7}, {2, 8}, {3, 0},
        {4, 7}, {1, 7}, {1, 6}, {0, 4}, {0, 7}, {2, 9}, {3, 7}, {1, 1},
        {2, 8}, {1, 8}, {0, 6}, {0, 5}, {1, 4}, {2, 6}, {1, 2}, {2, 5}
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
