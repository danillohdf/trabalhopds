#include "../include/jogo.hpp"

// Construtor
Jogo::Jogo(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
}

bool Jogo::verificarFimDeJogo() const {
    return false;
}

// Destrutor virtual
Jogo::~Jogo() {}
