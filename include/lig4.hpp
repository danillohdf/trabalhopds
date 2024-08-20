#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogo.hpp"
#include "jogador.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

class Lig4 : public Jogo {
private:
    static const int linhas = 6; // Ajuste conforme necessário
    static const int colunas = 7; // Ajuste conforme necessário
    char jogador1Simbolo;
    char jogador2Simbolo;
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogadorAtual;
    std::vector<std::vector<char>> tabuleiro;

    void inicializarTabuleiro();
    void alternarJogador();
    bool verificarJogadasValidas(Jogador* jogador) const;
    bool verificarVitoria(int linha, int coluna, Jogador* jogador);

public:
    Lig4(Jogador& jogador1, Jogador& jogador2);

    void iniciarJogo() override;
    void exibirTabuleiro() override;
    void fazerJogada(int linha, int coluna, Jogador* jogador) override;
    bool verificarJogada(int linha, int coluna, Jogador* jogador) const override;
    bool verificarFimDeJogo() const override;
    Jogador* getJogadorAtual() const;
    std::pair<int, int> converterEntrada(const std::string& entrada) const;

    static int getColunas() { return colunas; } // Adicione este método para acessar a constante
};

#endif // LIG4_HPP
