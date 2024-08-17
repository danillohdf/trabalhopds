#include "../include/reversi.cpp"
#include <iostream)

void Reversi::iniciarJogo(comst Jogador& j1, const Jogador& j2){
    jogador1 = j1;
    jogador2 = j2;
    inicializarTabuleiro();
}

void Reversi::incializarTabuleiro(){
    //Aqui vamos inicializar o tabuleiro com a configuração padrão do jogo Reversi
}

bool Reversi::movimentoValido(int linha, int coluna, int peca){
    //Aqui vamos verificar se o vovimento realizado é válido
    
    return true; //Reprodução(simular)
}

void Reversi::realizarJogada(int linha, int coluna, int peca){
    if(movimentoValido(linha, coluna, peca)){
        tabuleiro[linha][coluna] = peca;
    }
}

void Reversi::executarPartida(){
    //Aqui temos a lógica incial para começar a partida
}

void Reversi::exibirPlacar(){
    std::cout << "Placar do Reversi\n";
}