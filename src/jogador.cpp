#include "../include/jogador.hpp"
#include <fstream>
#include <vector>

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

void Jogador::incrementarVitorias()
{
    ++vitorias;
}
void Jogador::incrementarDerrotas()
{
    ++derrotas;
}

void Jogador::salvarJogador() const{
    std::ofstream arquivo("jogadores.txt,",std::ios::app);
    if(arquivo.is_open()){
        arquivo << apelido << " " << vitorias << " " << derrotas << "\n";
        arquivo.close();
    }
}
void Jogador::carregarJogadores(std::vector<Jogador>& jogadores){
    std::ifstream arquivo("jogadores.txt");
    if(arquivo.is_open()){
        std::string apelido, nome;
        int vitorias, derrotas;

        while (arquivo >> apelido >> nome >> vitorias >> derrotas){
            Jogador jogador(nome, apelido);
            jogador.setVitorias(vitorias);
            jogador.setDerrotas(derrotas);
            jogadores.push_back(jogador);
        }
        arquivo.close();
    }
}