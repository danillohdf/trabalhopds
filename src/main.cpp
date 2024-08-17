/* Inclusões */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <jogador.hpp>
#include "../include/error.hpp"
#include "../include/util.hpp"
#include "../include/jogador.hpp"
using namespace std;

/* Constantes */
#define N_TRACINHOS_MENU    (50)

/* Tipos/Classes */

/* Funções */
int main(int argc, char * argv[])
{
    string input_line, opcao;

    do {
        string arg1, arg2, arg3;

        util_ImprimeTracinhos(N_TRACINHOS_MENU);
        cout <<
        "(CJ <Apelido> <Nome>)\t\t\tCadastrar Jogador\n"
        "(RJ <Apelido>)\t\t\t\tRemover Jogador\n"
        "(LJ [A|N])\t\t\t\tListar Jogadores\n"
        "(EP [R|L] <Jogador1> <Jogador2>)\tExecutar Partida\n"
        "(FS)\t\t\t\t\tFinalizar Sistema\n";
        util_ImprimeTracinhos(N_TRACINHOS_MENU);
        cout << ">> ";
        
        // Lê a linha inteira, sem ser interrompido pelo espaço
        getline(cin, input_line);
        
        // Permite processar a linha de entrada como uma stream de entrada
        istringstream iss(input_line);
        iss >> opcao;

        if (opcao == "CJ"){
            if(iss >> arg1){
                getline(iss, arg2);
                // Se arg1 não é repetido, cadastrarJogador(arg1, arg2)
            } else cerr << "<Faltam argumentos.>\n";
        } else if (opcao == "RJ"){
            if(iss >> arg1){
                // removerJogador(arg1)
            } else cerr << "<Faltam argumentos.>\n";
            // Se jogador arg1 existe, removerJogador(arg1)
        } else if (opcao == "LJ" || opcao == "LJ"){
            if(iss >> arg1){
                if(arg1 == "A"){
                    // Listar, ordenado por apelido
                } else if (arg1 == "N"){
                    // Listar, ordenado por nome
                } else cerr << "<Erro na leitura da opção.>\n";
            } else cerr << "<Faltam argumentos.>\n";
        } else if (opcao == "EP"){
            if(iss >> arg1 >> arg2 >> arg3){
                if(arg1 == "R"){
                    // Reversi
                    // Se jogadores existem, Reversi(arg2, arg3)
                } else if (arg1 == "L"){
                    // Lig4
                    // Se jogadores existem e arg2 != arg3, Lig4(arg2, arg3)
                } else cerr << "<Erro na leitura da opção.>\n";
            } else cerr << "<Faltam argumentos.>\n";
        } else if (opcao == "FS"){
            cerr << "<Salvando...>\n";
            // salvarEstado()
            cerr << "<Saindo...>\n";
        } else {
            cerr << "<Erro na leitura da opção.>\n";
        }
    } while(opcao != "FS");

    return SUCESSO;
}

std::vector<Jogador> jogadores;
 void cadastrarJogadores(const std::string& apelido, const std::string& nome){
    for(const auto& jogador : jogadores){
        if(jogador.getApelido() == apelido){
            std::cerr << "ERR0: jogador duplicado\n";
            return;
        }
    }
    jogadores.emplace_back(nome,apelido);
    jogadores.back().salvarJogador(); //Salvar o jogador no arquivo
    std::cout << "Jogador" << apelido << "cadastrado com sucesso\n";
 }

 void removerJogador(const std::string& apelido){
    auto it = std::remove_if(jogadores.begin(), jogadores.end()),
        [&](const Jogador& jogador){
            return jogador.getApelido() == apelido;)};
    if (it != jogadores.end()){
        jogadores.erase(it, jogadores.end());
        //Atualizar o arquivo depois que o jogador foi removido
        std::cout << "Jogador " << apelido << " removido com sucesso!\n";
    }
    else {
        std:cerr << "Erro: jogador não existe\n";
    }
        } 
}

void listarJogadoresPorOrdemDeApelido(){
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b){
        return a.getApelid() < b.getApelido();
    });
    for(const auto& jogador : jogadores) {
        std::cout << jogador.getApelido() << " - " << jogador.getNome() << " (V: "
        << jogador.getVitorias() << " D: " << jogador.getDerrotas() << ")\n";
    }
}

void listarJogadoresPorOrdemDeNome(){
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b){
        return a.getNome() < b.getNome();
    });
    for (const auto& jogador : jogadores){
        std::cout << jogador.getNome() << " (" << jogador.getApelido() << ") - V: "
        << jogador.getVitorias() << " D: " << jogador.getDerrotas() << "\n";
    }
}