#include "../include/jogador.hpp"
#include "../include/reversi.hpp"
#include "../include/lig4.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    std::string input_line, opcao;
    Jogador::carregarJogadores();

    do {
        std::string arg1, arg2, arg3;

        // Exibe o menu
        std::cout << "(CJ <Apelido> <Nome>)\t\t\tCadastrar Jogador\n"
                  << "(RJ <Apelido>)\t\t\t\tRemover Jogador\n"
                  << "(LJ [A|N])\t\t\t\tListar Jogadores\n"
                  << "(EP [R|L] <Jogador1> <Jogador2>)\tExecutar Partida\n"
                  << "(FS)\t\t\t\t\tFinalizar Sistema\n";
        std::cout << ">> ";
        
        getline(std::cin, input_line);
        std::istringstream iss(input_line);
        iss >> opcao;

        if (opcao == "CJ") {
            if (iss >> arg1) {
                getline(iss, arg2);
                Jogador::cadastrarJogador(arg1, arg2);
            } else {
                std::cerr << "<Faltam argumentos.>\n";
            }
        } else if (opcao == "RJ") {
            if (iss >> arg1) {
                Jogador::removerJogador(arg1);
            } else {
                std::cerr << "<Faltam argumentos.>\n";
            }
        } else if (opcao == "LJ") {
            if (iss >> arg1) {
                if (arg1 == "A") {
                    Jogador::listarJogadoresPorOrdemApelido();
                } else if (arg1 == "N") {
                    Jogador::listarJogadoresPorOrdemNome();
                } else {
                    std::cerr << "<Erro na leitura da opção.>\n";
                }
            } else {
                std::cerr << "<Faltam argumentos.>\n";
            }
        }else if (opcao == "EP") {
            if (iss >> arg1 >> arg2 >> arg3) {
                Jogador* jogador1 = Jogador::encontrarJogador(arg2);
                Jogador* jogador2 = Jogador::encontrarJogador(arg3);

                if (jogador1 && jogador2 && jogador1 != jogador2) {
                    if (arg1 == "R") {
                        Reversi jogoReversi(*jogador1, *jogador2);
                        jogoReversi.iniciarJogo();

                        // Simulação de jogadas até o fim do jogo
                        std::string entrada;
                        bool jogadaValida;

                        while (!jogoReversi.verificarFimDeJogo()) {
                            Jogador* jogadorAtual = jogoReversi.getJogadorAtual();

                            std::cout << "\n" << jogadorAtual->getApelido() << ", faça sua jogada (coluna linha): ";
                            std::cin >> entrada;

                            // Modificado para suportar GCC mais antigo
                            auto result = jogoReversi.converterEntrada(entrada);
                            int linha = result.first;
                            int coluna = result.second;

                            if (linha != -1 && coluna != -1) {
                                std::cout << "Linha: " << linha << ", Coluna: " << coluna << std::endl;

                                jogadaValida = jogoReversi.verificarJogada(linha, coluna, jogadorAtual);
                                
                                if (jogadaValida) {
                                    jogoReversi.fazerJogada(linha, coluna, jogadorAtual);
                                } else {
                                    std::cout << "Jogada inválida! Tente novamente." << std::endl;
                                }
                            } else {
                                std::cout << "Entrada inválida! Tente novamente no formato coluna linha." << std::endl;
                            }
                        }

                        std::cout << "O jogo terminou! \n" << std::endl;

                    } else if (arg1 == "L") {
                Lig4 jogoLig4(*jogador1, *jogador2);
                jogoLig4.iniciarJogo();

                while (!jogoLig4.getJogoEncerrado()) {
                    Jogador* jogadorAtual = jogoLig4.getJogadorAtual();
                    std::string entrada;
                    bool jogadaValida;

                    std::cout << "\n" << jogadorAtual->getApelido() << ", faça sua jogada (coluna): ";
                    std::cin >> entrada;

                    int coluna = std::stoi(entrada);

                    if (coluna >= 0 && coluna < Lig4::getColunas()) {
                        jogadaValida = jogoLig4.verificarJogada(0, coluna, jogadorAtual);
                        
                        if (jogadaValida) {
                            jogoLig4.fazerJogada(0, coluna, jogadorAtual);
                        } else {
                            std::cout << "Jogada inválida! Tente novamente." << std::endl;
                        }
                    } else {
                        std::cout << "Entrada inválida! Tente novamente no formato coluna." << std::endl;
                    }
                }

                std::cout << "O jogo terminou! \n" << std::endl;
                std::cout << jogador1->getApelido() << " tem " << jogador1->getVitoriasLig4() << " vitórias no Lig4\n";
                std::cout << jogador2->getApelido() << " tem " << jogador2->getVitoriasLig4() << " vitórias no Lig4\n";

            } else {
                std::cout << "Tipo de jogo não reconhecido." << std::endl;
            }
        } else {
            std::cout << "Jogadores inválidos ou são o mesmo jogador." << std::endl;
        }
    } else {
        std::cout << "Argumentos insuficientes para a opção 'EP'." << std::endl;
    }
}
else if (opcao == "FS") {
            std::cerr << "<Salvando...>\n";
            // Salvar jogadores
            Jogador::salvarJogadores();
            std::cerr << "<Saindo...>\n";
            break;
        } else {
            std::cerr << "<Erro na leitura da opção.>\n";
        }
    } while (opcao != "FS");

    return 0;
}
