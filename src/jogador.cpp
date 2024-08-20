#include "../include/jogador.hpp"


/* Funções */

std::vector<Jogador> Jogador::jogadores;

// Set e Get Nome
void Jogador::setNome(const std::string nome)
{
    this->nome = nome;
}
std::string Jogador::getNome() const
{
    return nome;
}

// Set e Get Apelido
void Jogador::setApelido(const std::string apelido)
{
    this->apelido = apelido;
}
std::string Jogador::getApelido() const
{
    return apelido;
}

// Set e Get Vitorias
void Jogador::setVitorias(int vitorias)
{
    this->vitorias = vitorias;
}
int Jogador::getVitorias() const
{
    return vitorias;
}

// Set e Get Derrotas
void Jogador::setDerrotas(int derrotas)
{
    this->derrotas = derrotas; 
}
int Jogador::getDerrotas() const
{
    return derrotas;
}

// Set e Get Derrotas Reversi
void Jogador::setDerrotasReversi(int derrotasReversi)
{
    this->derrotasReversi = derrotasReversi;
}
int Jogador::getDerrotasReversi() const
{
    return derrotasReversi;
}

// Set e Get Derrotas Lig4
void Jogador::setDerrotasLig4(int derrotasLig4)
{
    this->derrotasLig4 = derrotasLig4;
}
int Jogador::getDerrotasLig4() const
{
    return derrotasLig4;
}

// Set e Get Vitorias Reversi
void Jogador::setVitoriasReversi(int vitoriasReversi)
{
    this->vitoriasReversi = vitoriasReversi;
}
int Jogador::getVitoriasReversi() const
{
    return vitoriasReversi;
}

// Set e Get Vitorias Reversi
void Jogador::setVitoriasLig4(int vitoriasLig4)
{
    this->vitoriasLig4 = vitoriasLig4;
}
int Jogador::getVitoriasLig4() const
{
    return vitoriasLig4;
}

//Incrementos das vitorias e derrotas
void Jogador::incrementarVitorias()
{
    ++vitorias;
}
void Jogador::incrementarDerrotas()
{
    ++derrotas;
}
void Jogador::incrementarVitoriasReversi()
{
    ++vitoriasReversi;
}
void Jogador::incrementarVitoriasLig4()
{
    ++vitoriasLig4;
}
void Jogador::incrementarDerrotasReversi(){
    ++derrotasReversi;
}
void Jogador::incrementarDerrotasLig4()
{
    ++derrotasLig4;
}


void Jogador::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    for(const auto& jogador : jogadores) {
        if(jogador.getApelido() == apelido) {
            std::cerr << "ERRO: jogador duplicado\n";
            return;
        }
    }
    jogadores.emplace_back(nome, apelido); // Adicionar o jogador à lista
}

void Jogador::removerJogador(const std::string& apelido) {
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
        [&](const Jogador& jogador){
            return jogador.getApelido() == apelido;
        });
    if (it != jogadores.end()){
        jogadores.erase(it, jogadores.end());
        std::cout << "Jogador " << apelido << " removido com sucesso!\n";
    } else {
        std::cerr << "Erro: jogador não existe\n";
    }
}

void Jogador::listarJogadoresPorOrdemApelido() {
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b){
        return a.getApelido() < b.getApelido();
    });
    for(const auto& jogador : jogadores) {
        std::cout << jogador.getApelido() << " - " << jogador.getNome() << std::endl;
        std::cout << "REVERSI - V: " << jogador.getVitoriasReversi() << " D: " <<jogador.getDerrotasReversi() << std::endl;
        std::cout << "LIG4 - V: " << jogador.getVitoriasLig4() << " D: " <<jogador.getDerrotasLig4() << std::endl;
    }
}

void Jogador::listarJogadoresPorOrdemNome() {
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b){
        return a.getNome() < b.getNome();
    });
    for (const auto& jogador : jogadores){
        std::cout << "REVERSI - V: " << jogador.getVitoriasReversi() << " D: " <<jogador.getDerrotasReversi() << std::endl;
        std::cout << "LIG4 - V: " << jogador.getVitoriasLig4() << " D: " <<jogador.getDerrotasLig4() << std::endl;
    }
}

Jogador* Jogador::encontrarJogador(const std::string& apelido) {
    for (auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            return &jogador;
        }
    }
    return nullptr;
}

void Jogador::salvarJogadores() {
    std::ofstream arquivo("jogadores.txt");
    if (arquivo.is_open()) {
        for (const auto& jogador : jogadores) {
            arquivo << jogador.getNome() << " " << jogador.getApelido() << " "
                    << jogador.getVitorias() << " " << jogador.getDerrotas() << " "
                    << jogador.getVitoriasReversi() << " " << jogador.getDerrotasReversi() << " "
                    << jogador.getVitoriasLig4() << " " << jogador.getDerrotasLig4() << "\n";
        }
        arquivo.close();
        std::cerr << "<Arquivo jogadores.txt salvo com sucesso>\n";
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar.\n";
    }
}
void Jogador::carregarJogadores() {
    std::ifstream arquivo("jogadores.txt");
    if (arquivo.is_open()) {
        std::string apelido, nome;
        int vitorias, derrotas, vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4;

        while (arquivo >> nome >> apelido >> vitorias >> derrotas
                        >> vitoriasReversi >> derrotasReversi
                        >> vitoriasLig4 >> derrotasLig4) {
            Jogador jogador(nome, apelido);
            jogador.setVitorias(vitorias);
            jogador.setDerrotas(derrotas);
            jogador.setVitoriasReversi(vitoriasReversi);
            jogador.setDerrotasReversi(derrotasReversi);
            jogador.setVitoriasLig4(vitoriasLig4);
            jogador.setDerrotasLig4(derrotasLig4);
            jogadores.push_back(jogador);
        }
        arquivo.close();
    }
}