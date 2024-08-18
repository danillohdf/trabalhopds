#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogo.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

const char pecaPreta = 'X';
const char pecaBranca = 'O';

class Reversi : public Jogo {
private:
    void inicializarTabuleiro();
    void alternarJogador();
    void virarPecas(int linha, int coluna, Jogador *jogador);
    static const int tamanho = 8; 

    Jogador* jogadorPreto;
    Jogador* jogadorBranco;
    Jogador* jogadorAtual;


public:
    Reversi(Jogador& jogador1, Jogador& jogador2);

    void iniciarJogo() override;
    void exibirTabuleiro() override;

    void fazerJogada(int linha, int coluna, Jogador* jogador) override;
    bool verificarJogada(int linha, int coluna, Jogador* jogador) override;
    bool verificarFimDeJogo() const override;
    Jogador *getJogadorAtual() const;
    std::pair<int, int> converterEntrada(const std::string& entrada) const;

};

#endif // REVERSI_HPP
