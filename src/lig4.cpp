#include "../include/lig4.hpp"
#include <iostream>

void Lig4::iniciarJogo(const Jogador& j1, const Jogador& j2){
    jogador1 = j1;
    jogador2 = j2;
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro(){
    //Aqui vamos inicializar o tabuleiro vazio
}

bool Lig4::movimentoValido(int coluna){
    //Verificar se a coluna permite uma jogada válida
    return true; //Reprodução(simular)
}

void Lig4::realizarJogada(int coluna, char peca){
    if(movimentoValido(coluna));{
    //Aqui realiza a jogada
    }
}

void Lig4::executarPartida(){
    //Aqui temos a lógica inicial para começar a partida
}

void Lig4::exibirPlacar(){
    std::cout << "Placar do Lig4\n";
}