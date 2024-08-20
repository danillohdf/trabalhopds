#include "lig4.hpp"

Lig4::Lig4(Jogador& j1, Jogador& j2)
    : Jogo(linhas, colunas),
      jogador1Simbolo('X'),
      jogador2Simbolo('O'),
      jogador1(&j1),
      jogador2(&j2),
      jogadorAtual(&j1),
      jogoEncerrado(false) { // Inicialize jogoEncerrado
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
                verificarEEncerrarJogo(jogador);
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

void Lig4::verificarEEncerrarJogo(Jogador* jogador) {
    std::cout << "Jogador " << jogador->getApelido() << " venceu!" << std::endl;

    // Atualiza as estatísticas dos jogadores
    if (jogador == jogador1) {
        jogador1->incrementarVitorias();
        jogador1->incrementarVitoriasLig4();
        jogador2->incrementarDerrotas();
        jogador2->incrementarDerrotasLig4();
    } else {
        jogador2->incrementarVitorias();
        jogador2->incrementarVitoriasLig4();
        jogador1->incrementarDerrotas();
        jogador1->incrementarDerrotasLig4();
    }

    // Exibe as estatísticas atualizadas
    std::cout << jogador1->getApelido() << " tem " << jogador1->getVitoriasLig4() << " vitórias no Lig4" << std::endl;
    std::cout << jogador2->getApelido() << " tem " << jogador2->getVitoriasLig4() << " vitórias no Lig4" << std::endl;

    // Marca o jogo como encerrado
    jogoEncerrado = true;
}