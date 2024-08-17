#include "../include/jogador.hpp"
#include <fstream>

/* Funções */

void Jogador::setNome(const std::string nome)
{
    this->nome = nome;
}
std::string Jogador::getNome() const
{
    return nome;
}

void Jogador::setApelido(const std::string apelido)
{
    this->apelido = apelido;
}
std::string Jogador::getApelido() const
{
    return apelido;
}

void Jogador::setVitorias(int vitorias)
{
    this->vitorias = vitorias;
}
int Jogador::getVitorias() const
{
    return vitorias;
}

void Jogador::setDerrotas(int derrotas)
{
    this->derrotas = derrotas;
}
int Jogador::getDerrotas() const
{
    return derrotas;
}

void Jogador::salvarJogador(){
    std::ofstream arquivo("jogadores.txt,",std::ios::app);
    if(arquvivo.is_open()){
        arquivo << apeido << " " << vitorias << " " << derrotas << "\n";
        arquivo.close();
    }

}
void Jogador::carregarJogadores(){
    std::ifstream arquivo("jogadores.txt");
    if(arquivo.is_open()){
        std:string apelido, nome;
        int vitorias, derrotas;
        while (arquivo >> apelido >> nome >> vitorias >> derrotas){
            jogadores.emplace_back(nome,apelido);
            jogadores.back().setVitorias(vitorias);
            jogadores.back().setDerrotas(derrotas);
        }
        arquivo.close();
    }
}