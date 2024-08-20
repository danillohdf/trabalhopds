#include <../include/doctest.h>
#include "../include/jogador.hpp"
#include <sstream>

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

// Testa a funcionalidade de listagem de jogadores
TEST_CASE("Testa listagem de jogadores") {
    Jogador::cadastrarJogador("Apelido3", "Nome3");
    Jogador::cadastrarJogador("Apelido2", "Nome2");

    // Lista por apelido
    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());
    
    Jogador::listarJogadoresPorOrdemApelido();
    
    std::cout.rdbuf(old);

    std::string result = output.str();
    CHECK(result.find("Apelido2 - Nome2") != std::string::npos);
    CHECK(result.find("Apelido3 - Nome3") != std::string::npos);

    // Lista por nome
    output.str("");
    Jogador::listarJogadoresPorOrdemNome();

    result = output.str();
    CHECK(result.find("Nome2 - Apelido2") != std::string::npos);
    CHECK(result.find("Nome3 - Apelido3") != std::string::npos);
}
// Testa o estado inicial e limpeza de dados
TEST_CASE("Testa estado inicial e limpeza de dados") {
    Jogador jogador1("Nome1", "Apelido1");
    Jogador jogador2("Nome2", "Apelido2");

    // Inicialmente, jogadores não devem estar cadastrados
    CHECK(Jogador::encontrarJogador("Apelido1") == nullptr);
    CHECK(Jogador::encontrarJogador("Apelido2") == nullptr);

    // Adiciona jogadores e verifica
    Jogador::cadastrarJogador("Apelido1", "Nome1");
    Jogador::cadastrarJogador("Apelido2", "Nome2");
    CHECK(Jogador::encontrarJogador("Apelido1") != nullptr);
    CHECK(Jogador::encontrarJogador("Apelido2") != nullptr);

    // Remove jogadores e verifica
    Jogador::removerJogador("Apelido1");
    Jogador::removerJogador("Apelido2");
    CHECK(Jogador::encontrarJogador("Apelido1") == nullptr);
    CHECK(Jogador::encontrarJogador("Apelido2") == nullptr);
}

// Testa mensagens de erro para operações inválidas
TEST_CASE("Testa mensagens de erro para operações inválidas") {
    // Tentativa de remover jogador que não existe
    CHECK_NOTHROW(Jogador::removerJogador("ApelidoInexistente"));

    // Verifica se não há impacto no cadastro de jogadores
    Jogador::cadastrarJogador("ApelidoExistente", "NomeExistente");
    CHECK(Jogador::encontrarJogador("ApelidoExistente") != nullptr);
}
