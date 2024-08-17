#include "../include/lig4.hpp"
#include <iostream>

void Lig4::iniciarJogo(const Jogador& j1, const Jogador& j2){
    jogador1 = j1;
    jogador2 = j2;
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro(){
    //Aqui vamos inicializar o tabuleiro vazio
    for(int i = 0; i < 6; i++){
        for(int j = 0; i < 7; j++){
            tabuleiro[i][i] = ' ';
        }
    }
}

bool Lig4::movimentoValido(int coluna){
    //Verificar se a coluna permite uma jogada válida
    if(coluna < 0 || coluna >= 7){
        return false;
    }
    return tabuleiro[0][coluna] == ' '; //Se a coluna não estiver cheia
}

void Lig4::realizarJogada(int coluna, char peca){
    if(movimentoValido(coluna)){ //Retirei um ponto e vírgula que estava aqui errado
        for(int i = 5; i >= 0; i--){
            if(tabuleiro[i][coluna] == ' '){
                tabuleiro[i][coluna] = peca;
                break;
            }
        }
    //Aqui realiza a jogada
    }else{
        std::cerr <"Movimento inválido na coluna" << coluna << std::endl;
    }
}

void Lig4::executarPartida(){
    //Aqui temos a lógica inicial para começar a partida
}

void Lig4::exibirPlacar(){
    std::cout << "Placar do Lig4\n";
}