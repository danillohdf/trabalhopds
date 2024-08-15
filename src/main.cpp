/* Inclusões */
#include <iostream>
#include "../include/error.hpp"
#include "../include/util.hpp"
using namespace std;

/* Constantes */

/* Tipos/Classes */

/* Funções */
int main(int argc, char * argv[])
{
    char opcao;

    do {
        util_ImprimeTracinhos(30);
        cout <<
        "(1) Cadastrar Jogador\n"
        "(2) Remover Jogador\n"
        "(3) Listar Jogadores\n"
        "(4) Executar Partida\n"
        "(0) Finalizar Sistema\n"
        ">> ";
        
        cin >> opcao;

        switch(opcao){
            case '0':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            default:
                cerr << "<Erro na leitura da opção.>\n";
                break;
        }
    } while(opcao != '0');

    return SUCESSO;
}