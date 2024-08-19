#include "../include/lig4.hpp"
#include <iostream>

Lig4::Lig4(Jogador& jogador1, Jogador& jogador2)
    : Jogo(6, 7), jogador1(&jogador1), jogador2(&jogador2), jogadorAtual(&jogador1) {
    inicializarTabuleiro();
}

// Inicializa o tabuleiro vazio
void Lig4::inicializarTabuleiro() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Verifica se o movimento na coluna é válido
bool Lig4::movimentoValido(int coluna) const {
    if (coluna < 0 || coluna >= 7) {
        return false;
    }
    return tabuleiro[0][coluna] == ' '; // Verifica se a coluna não está cheia
}

// Realiza uma jogada na coluna
void Lig4::realizarJogada(int coluna, char peca) {
    if (movimentoValido(coluna)) {
        for (int i = 5; i >= 0; --i) {
            if (tabuleiro[i][coluna] == ' ') {
                tabuleiro[i][coluna] = peca;
                break;
            }
        }
    } else {
        std::cerr << "Movimento inválido na coluna " << coluna << std::endl;
    }
}

// Exibe o tabuleiro no estado atual
void Lig4::exibirTabuleiro() const {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout << ' ' << tabuleiro[i][j] << ' ';
            if (j < 6) std::cout << '|';
        }
        std::cout << std::endl;
        if (i < 5) {
            std::cout << "  -----------------------------" << std::endl;
        }
    }
}

// Método para iniciar o jogo
void Lig4::iniciarJogo() {
    std::cout << "Início da partida de Lig4" << std::endl;
    exibirTabuleiro();
}

// Executa a partida
void Lig4::executarPartida() {
    // Implementar lógica para executar a partida
}

// Exibe o placar
void Lig4::exibirPlacar() {
    std::cout << "Placar do Lig4" << std::endl;
    std::cout << jogador1->getNome() << " - Vitórias: " << jogador1->getVitorias()
              << ", Derrotas: " << jogador1->getDerrotas() << std::endl;
    std::cout << jogador2->getNome() << " - Vitórias: " << jogador2->getVitorias()
              << ", Derrotas: " << jogador2->getDerrotas() << std::endl;
}

// Verifica se há uma vitória no jogo
bool Lig4::verificarVitoria() const {
    // Verifica se há 4 peças consecutivas em qualquer direção

    // Verifica linhas
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7 - 3; ++j) { // -3 para garantir que haja espaço para 4 peças
            char peca = tabuleiro[i][j];
            if (peca != ' ' && peca == tabuleiro[i][j + 1] && peca == tabuleiro[i][j + 2] && peca == tabuleiro[i][j + 3]) {
                return true;
            }
        }
    }

    // Verifica colunas
    for (int j = 0; j < 7; ++j) {
        for (int i = 0; i < 6 - 3; ++i) { // -3 para garantir que haja espaço para 4 peças
            char peca = tabuleiro[i][j];
            if (peca != ' ' && peca == tabuleiro[i + 1][j] && peca == tabuleiro[i + 2][j] && peca == tabuleiro[i + 3][j]) {
                return true;
            }
        }
    }

    // Verifica diagonais (direita e esquerda)
    for (int i = 0; i < 6 - 3; ++i) {
        for (int j = 0; j < 7 - 3; ++j) { // Diagonais direitas
            char peca = tabuleiro[i][j];
            if (peca != ' ' &&
                peca == tabuleiro[i + 1][j + 1] &&
                peca == tabuleiro[i + 2][j + 2] &&
                peca == tabuleiro[i + 3][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 3; i < 6; ++i) {
        for (int j = 0; j < 7 - 3; ++j) { // Diagonais esquerdas
            char peca = tabuleiro[i][j];
            if (peca != ' ' &&
                peca == tabuleiro[i - 1][j + 1] &&
                peca == tabuleiro[i - 2][j + 2] &&
                peca == tabuleiro[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

// Faz uma jogada e alterna o jogador
void Lig4::fazerJogada(int coluna, Jogador* jogador) {
    char peca = (jogador == jogador1) ? pecaJogador1 : pecaJogador2;
    realizarJogada(coluna, peca);
    if (verificarVitoria()) {
        std::cout << "Jogador " << jogador->getNome() << " venceu!" << std::endl;
        jogador->incrementarVitorias();
        // Alternar jogadores
        jogadorAtual = (jogadorAtual == jogador1) ? jogador2 : jogador1;
    }
}
