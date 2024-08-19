#include "../include/jogador.hpp"


/* Funções */

std::vector<Jogador> Jogador::jogadores;

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

int Jogador::getDerrotasReversi() const
{
    return derrotasReversi;
}

int Jogador::getDerrotasLig4() const
{
    return derrotasLig4;
}

int Jogador::getVitoriasReversi() const
{
    return vitoriasReversi;
}

int Jogador::getVitoriasLig4() const
{
    return vitoriasLig4;
}


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

void Jogador::cadastrarJogador(const std::string& apelido, const std::string& nome){
    for(const auto& jogador : jogadores){
        if(jogador.getApelido() == apelido){
            std::cerr << "ERRO: jogador duplicado \n";
            return;
        }
    }
    jogadores.emplace_back(nome, apelido); //Adicionar o jogador à lista, o que estava faltando
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
        std::cout << jogador.getApelido() << " - " << jogador.getNome() << " (V: "
        << jogador.getVitorias() << " D: " << jogador.getDerrotas() << ")\n";
    }
}

void Jogador::listarJogadoresPorOrdemNome() {
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b){
        return a.getNome() < b.getNome();
    });
    for (const auto& jogador : jogadores){
        std::cout << jogador.getNome() << " (" << jogador.getApelido() << ") - V: "
        << jogador.getVitorias() << " D: " << jogador.getDerrotas() << "\n";
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
                    << jogador.getVitorias() << " " << jogador.getDerrotas() << "\n";
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
        int vitorias, derrotas;

        while (arquivo >> apelido >> nome >> vitorias >> derrotas) {
            Jogador jogador(nome, apelido);
            jogador.setVitorias(vitorias);
            jogador.setDerrotas(derrotas);
            jogadores.push_back(jogador);
        }
        arquivo.close();
    }
}