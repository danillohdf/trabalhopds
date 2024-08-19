#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogo.hpp"
#include "jogador.hpp"

class Lig4 : public Jogo {
private:
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogadorAtual;
    char tabuleiro[6][7];
    char pecaJogador1 = 'X'; // Define as peças dos jogadores
    char pecaJogador2 = 'O';

    void inicializarTabuleiro();
    bool movimentoValido(int coluna) const;
    void realizarJogada(int coluna, char peca);
    bool verificarVitoria() const;
    void exibirTabuleiro() const;

public:
    Lig4(Jogador& jogador1, Jogador& jogador2);

    void iniciarJogo() override;
    void executarPartida(); 
    void exibirPlacar();  
    void fazerJogada(int coluna, Jogador* jogador);
};

#endif // LIG4_HPP
