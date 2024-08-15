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