#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include "jogador.hpp"

class Jogo {
public:
    Jogo(int linhas, int colunas);
    virtual void iniciarJogo() = 0;
    virtual void exibirTabuleiro() = 0;
    virtual void fazerJogada(int linha, int coluna, Jogador* jogador) = 0;
    virtual bool verificarJogada(int linha, int coluna, Jogador* jogador) const = 0;
    virtual bool verificarFimDeJogo() const = 0;
    virtual ~Jogo();
protected:
    std::vector<std::vector<char>> tabuleiro;
    int linhas, colunas;

};

#endif // JOGO_HPP