#pragma once
#ifndef LIG4_HPP
#define LIG4_HPP

#include <string>
#include <vector>
#include <jogador.hpp>

class Lig4{

public: 
    void iniciarJogo(const Jogador& jogador1, const Jogador& jogador2);
    void executarPartida();
    void exibirPlacar();

private: 
    Jogador jogador1;
    Jogador jogador2;
    char tabuleiro[6][7];
    void inicializarTabuleiro();
    bool movimentoValido(int coluna);
    void realizarJogada(int coluna, char peca);

};

#endif //LIG4_HPP