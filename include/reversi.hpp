#pragma once
#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <string>
#include <vector>
#include <jogador.hpp>


class Reversi{

public: 
    void iniciarJogo(const Jogador& jogador1, const Jogador& jogador2);
    void executarPartida();
    void exibirPlacar();

private:
    Jogador jogador1;
    Jogador jogador2;
    char tabuleiro[8][8];
    void inicializarTabuleiro();
    bool movimentoValido(int linha, int coluna, char peca);
    void realizarJogada(int linha, int coluna, int peca);

};

#endif //REVERSI_HPP