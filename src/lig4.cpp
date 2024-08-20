#include "lig4.hpp"

Lig4::Lig4(Jogador& j1, Jogador& j2)
    : Jogo(linhas, colunas), // Inicialize a classe base primeiro
      jogador1Simbolo('X'), 
      jogador2Simbolo('O'), 
      jogador1(&j1), 
      jogador2(&j2), 
      jogadorAtual(&j1) { // Inicialize os membros em ordem de declaração
    inicializarTabuleiro();
}

void Lig4::iniciarJogo() {
    std::cout << "Jogo Lig4 Iniciado" << std::endl;
    exibirTabuleiro();
    std::cout << jogadorAtual->getApelido() << ", você joga primeiro." << std::endl;
}

void Lig4::exibirTabuleiro() {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            char c = tabuleiro[i][j];
            std::cout << "|" << (c ? c : ' ');
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < colunas; ++j) {
        std::cout << " " << j + 1 << " ";
    }
    std::cout << std::endl;
}

void Lig4::fazerJogada(int linha, int coluna, Jogador* jogador) {
    if (verificarJogada(linha, coluna, jogador)) {
        int linhaDisponivel = -1;
        for (int i = linhas - 1; i >= 0; --i) {
            if (tabuleiro[i][coluna] == ' ') {
                linhaDisponivel = i;
                break;
            }
        }
        if (linhaDisponivel != -1) {
            tabuleiro[linhaDisponivel][coluna] = (jogador == jogador1) ? jogador1Simbolo : jogador2Simbolo;
            if (verificarVitoria(linhaDisponivel, coluna, jogador)) {
                std::cout << "Jogador " << jogador->getApelido() << " venceu!" << std::endl;
                verificarFimDeJogo();
            } else {
                alternarJogador();
                std::cout << "Jogada feita por " << jogador->getNome() << std::endl;
                exibirTabuleiro();
            }
        } else {
            std::cout << "Coluna cheia! Tente novamente." << std::endl;
        }
    } else {
        std::cout << "Jogada inválida! Tente novamente." << std::endl;
    }
}

bool Lig4::verificarJogada(int linha, int coluna, Jogador* jogador) const {
    if (coluna < 0 || coluna >= colunas || linha < 0 || linha >= linhas) {
        return false;
    }
    return true;
}

bool Lig4::verificarVitoria(int linha, int coluna, Jogador* jogador) {
    char simbolo = (jogador == jogador1) ? jogador1Simbolo : jogador2Simbolo;

    // Verifica todas as direções (horizontal, vertical e diagonal)
    const int direcoes[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (auto& direcao : direcoes) {
        int dx = direcao[0];
        int dy = direcao[1];
        int contagem = 1;

        for (int i = 1; i < 4; ++i) {
            int x = linha + i * dx;
            int y = coluna + i * dy;

            if (x < 0 || x >= linhas || y < 0 || y >= colunas || tabuleiro[x][y] != simbolo) {
                break;
            }
            ++contagem;
        }

        for (int i = 1; i < 4; ++i) {
            int x = linha - i * dx;
            int y = coluna - i * dy;

            if (x < 0 || x >= linhas || y < 0 || y >= colunas || tabuleiro[x][y] != simbolo) {
                break;
            }
            ++contagem;
        }

        if (contagem >= 4) {
            return true;
        }
    }
    return false;
}

bool Lig4::verificarFimDeJogo() const {
    bool tabuleiroCheio = true;
    for (int j = 0; j < colunas; ++j) {
        if (tabuleiro[0][j] == ' ') {
            tabuleiroCheio = false;
            break;
        }
    }

    if (tabuleiroCheio) {
        std::cout << "Empate! O tabuleiro está cheio." << std::endl;
        return true;
    }

    return false;
}

Jogador* Lig4::getJogadorAtual() const {
    return jogadorAtual;
}

void Lig4::inicializarTabuleiro() {
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
}

void Lig4::alternarJogador() {
    jogadorAtual = (jogadorAtual == jogador1) ? jogador2 : jogador1;
}
