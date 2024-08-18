#include "../include/reversi.hpp"

//Inicializa tabuleiro e atribui aleatoriamente as cores dos jogadores
Reversi::Reversi(Jogador& jogador1, Jogador& jogador2)
    : Jogo(8, 8) {
    inicializarTabuleiro();
    if (rand() % 2 == 0) {
        jogadorPreto = &jogador1;
        jogadorBranco = &jogador2;
    } else {
        jogadorPreto = &jogador2;
        jogadorBranco = &jogador1;
    }
    jogadorAtual = jogadorPreto;
}

// Função que inicia o jogo e exibe o estado inicial do tabuleiro
void Reversi::iniciarJogo() {
    std::cout << "Jogo Reversi Iniciado" << std::endl;
    exibirTabuleiro();
    std::cout <<jogadorAtual->getApelido() << ", voce joga primeiro" << std::endl;
}

// Exibe o tabuleiro no estado atual, incluindo bordas e coordenadas
void Reversi::exibirTabuleiro() {
    // Exibe as coordenadas das colunas
    std::cout << " ";
    for (int i = 0; i < colunas; ++i)
        std::cout << "   " << char('a' + i);
    std::cout << std::endl;

    // Exibe a linha de bordas superior
    std::cout << "  +";
    for (int i = 0; i < colunas; ++i)
        std::cout << "---+";
    std::cout << std::endl;

    // Exibe cada linha do tabuleiro com peças e bordas laterais
    for (int j = 0; j < linhas; ++j) {
        std::cout << std::setw(2) << j + 1 << "|";
        for (int i = 0; i < colunas; ++i) {
            if (tabuleiro[j][i] == pecaPreta) {
                std::cout << " " <<pecaPreta << " |";
            } else if (tabuleiro[j][i] == pecaBranca) {
                std::cout << " " <<pecaBranca << " |";
            } else {
                std::cout << "   |";
            }
        }
        std::cout << std::endl;

        // Exibe a linha de bordas inferior
        std::cout << "  +";
        for (int i = 0; i < colunas; ++i)
            std::cout << "---+";
        std::cout << std::endl;
    }
}

// Faz uma jogada no tabuleiro, verifica se é válida, exibe o tabuleiro atualizado e alterna o jogador
void Reversi::fazerJogada(int linha, int coluna, Jogador* jogador) {
    char simbolo = (jogador == jogadorBranco) ? pecaBranca : pecaPreta;
    if (verificarJogada(linha, coluna, jogador)) {
        tabuleiro[linha][coluna] = simbolo;
        virarPecas(linha, coluna, jogador);
        std::cout << "Jogada feita por " << jogador->getNome() << std::endl;
        exibirTabuleiro();
        alternarJogador();
    } else {
        std::cout << "Jogada invalida! Tente novamente, " << jogador->getNome() << std::endl;
    }
}

// Verifica se a jogada feita pelo jogador é válida em qualquer direção
bool Reversi::verificarJogada(int linha, int coluna, Jogador* jogador) {
    // Verifica se a jogada está dentro dos limites do tabuleiro e se a posição está vazia
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || tabuleiro[linha][coluna] != ' ') {
        return false;
    }

    char pecaJogador = (jogador == jogadorPreto) ? pecaPreta : pecaBranca;
    char pecaOponente = (pecaJogador == pecaPreta) ? pecaBranca : pecaPreta;
    bool jogadaValida = false;

    // Direções possíveis para verificar jogadas válidas
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    // Percorre cada direção para verificar se existe uma jogada válida
    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool temPecaOponenteEntre = false;

        // Verifica se há peças do oponente entre a peça atual e outra peça do jogador
        while (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == pecaOponente) {
            x += dx;
            y += dy;
            temPecaOponenteEntre = true;
        }

        // Se há peças do oponente entre as peças do jogador, a jogada é válida
        if (temPecaOponenteEntre && x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == pecaJogador) {
            jogadaValida = true;
        }
    }

    return jogadaValida;
}

// Verifica se o jogo chegou ao fim, determina o vencedor e exibe a mensagem de vitória
bool Reversi::verificarFimDeJogo() const {
    int numPecasPretas = 0, numPecasBrancas = 0;

    // Conta o número de peças de cada jogador no tabuleiro
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            if (tabuleiro[i][j] == pecaPreta) {
                ++numPecasPretas;
            } else if (tabuleiro[i][j] == pecaBranca) {
                ++numPecasBrancas;
            }
        }
    }
     // Verifica as condições de fim de jogo, incrimenta numero de vitorias e imprimi numero de vitorias dos jogadores
    if (numPecasPretas == 0 || numPecasBrancas == 0 || (numPecasPretas + numPecasBrancas == tamanho * tamanho)) {
        if (numPecasPretas > numPecasBrancas) {
            std::cout << jogadorPreto->getApelido() << " venceu!" << std::endl;
            jogadorPreto->incrementarVitorias();
            std::cout << jogadorPreto->getApelido() << "tem " << jogadorPreto->getVitorias() << "vitorias" << std::endl;
            std::cout << jogadorBranco->getApelido() << "tem " << jogadorBranco->getVitorias() << "vitorias" << std::endl;
        } else if (numPecasBrancas > numPecasPretas) {
            std::cout << jogadorBranco->getApelido() << " venceu!" << std::endl;
            jogadorBranco->incrementarVitorias();
            std::cout << jogadorPreto->getApelido() << "tem " << jogadorPreto->getVitorias() << "vitorias" << std::endl;
            std::cout << jogadorBranco->getApelido() << "tem " << jogadorBranco->getVitorias() << "vitorias" << std::endl;
        } else {
            std::cout << "O jogo terminou em empate!" << std::endl;
        }
        return true;
    }
    return false;
}

// Inicializa o tabuleiro com a configuração padrão de início do jogo
void Reversi::inicializarTabuleiro() {
    tabuleiro.resize(8, std::vector<char>(8, ' '));
    tabuleiro[3][3] = pecaBranca;
    tabuleiro[3][4] = pecaPreta;
    tabuleiro[4][3] = pecaPreta;
    tabuleiro[4][4] = pecaBranca;
    
}

// Alterna entre os jogadores após cada jogada
void Reversi::alternarJogador() {
    jogadorAtual = (jogadorAtual == jogadorPreto) ? jogadorBranco : jogadorPreto;
}

// Retorna o jogador atual (aquele que deve fazer a próxima jogada)
Jogador* Reversi::getJogadorAtual() const {
    return jogadorAtual;
}

// Vira as peças do oponente após uma jogada válida, conforme as regras do Reversi
void Reversi::virarPecas(int linha, int coluna, Jogador* jogador) {
    char simbolo = (jogador == jogadorBranco) ? pecaBranca : pecaPreta;
    char oponente = (simbolo == pecaPreta) ? pecaBranca : pecaPreta;

    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool temPecaOponenteEntre = false;

        while (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == oponente) {
            x += dx;
            y += dy;
            temPecaOponenteEntre = true;
        }

        if (temPecaOponenteEntre && x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == simbolo) {
            x = linha + dx;
            y = coluna + dy;
            while (tabuleiro[x][y] == oponente) {
                tabuleiro[x][y] = simbolo;
                x += dx;
                y += dy;
            }
        }
    }
}


std::pair<int, int> Reversi::converterEntrada(const std::string& entrada) const {
    int linha = -1, coluna = -1;

    if (entrada.size() == 2) {
        char colunaChar = std::tolower(entrada[0]);
        char linhaChar = entrada[1];

        if (colunaChar >= 'a' && colunaChar <= 'h' && linhaChar >= '1' && linhaChar <= '8') {
            coluna = colunaChar - 'a';
            linha = linhaChar - '1';
        }
    }

    return std::make_pair(linha, coluna);
}