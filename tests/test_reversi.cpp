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

// Testa a criação e o funcionamento básico dos métodos de Jogador
TEST_CASE("Testa criação e métodos básicos de Jogador") {
    Jogador jogador("Nome", "Apelido");

    // Testa getters e setters
    CHECK(jogador.getNome() == "Nome");
    CHECK(jogador.getApelido() == "Apelido");

    jogador.setNome("Novo Nome");
    jogador.setApelido("Novo Apelido");

    CHECK(jogador.getNome() == "Novo Nome");
    CHECK(jogador.getApelido() == "Novo Apelido");
}

// Testa os métodos de incremento de vitórias e derrotas
TEST_CASE("Testa incrementos de vitórias e derrotas") {
    Jogador jogador("Nome", "Apelido");

    // Inicialmente, vitórias e derrotas devem ser 0
    CHECK(jogador.getVitorias() == 0);
    CHECK(jogador.getDerrotas() == 0);

    // Incrementa vitórias e derrotas
    jogador.incrementarVitorias();
    jogador.incrementarDerrotas();

    CHECK(jogador.getVitorias() == 1);
    CHECK(jogador.getDerrotas() == 1);

    // Testa os métodos específicos para Reversi e Lig4
    jogador.incrementarVitoriasReversi();
    jogador.incrementarDerrotasReversi();
    jogador.incrementarVitoriasLig4();
    jogador.incrementarDerrotasLig4();

    CHECK(jogador.getVitoriasReversi() == 1);
    CHECK(jogador.getDerrotasReversi() == 1);
    CHECK(jogador.getVitoriasLig4() == 1);
    CHECK(jogador.getDerrotasLig4() == 1);
}

// Testa a funcionalidade de cadastro e remoção de jogadores
TEST_CASE("Testa cadastro e remoção de jogadores") {
    Jogador jogador1("Nome1", "Apelido1");
    Jogador jogador2("Nome2", "Apelido2");

    // Adiciona jogadores
    Jogador::cadastrarJogador("Apelido1", "Nome1");
    Jogador::cadastrarJogador("Apelido2", "Nome2");

    // Verifica se os jogadores foram cadastrados
    CHECK(Jogador::encontrarJogador("Apelido1") != nullptr);
    CHECK(Jogador::encontrarJogador("Apelido2") != nullptr);

    // Remove um jogador
    Jogador::removerJogador("Apelido1");

    // Verifica se o jogador foi removido
    CHECK(Jogador::encontrarJogador("Apelido1") == nullptr);
    CHECK(Jogador::encontrarJogador("Apelido2") != nullptr);
}
// Testa mensagens de erro para operações inválidas
TEST_CASE("Testa mensagens de erro para operações inválidas") {
    // Tentativa de remover jogador que não existe
    CHECK_NOTHROW(Jogador::removerJogador("ApelidoInexistente"));

    // Verifica se não há impacto no cadastro de jogadores
    Jogador::cadastrarJogador("ApelidoExistente", "NomeExistente");
    CHECK(Jogador::encontrarJogador("ApelidoExistente") != nullptr);
}
