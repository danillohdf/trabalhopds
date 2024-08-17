#pragma once
#ifndef JOGADOR_hpp
#define JOGADOR_hpp

/* Inclusões */
#include <string>
#include <vector>

/* Tipos/Classes */
class Jogador {
private:
    std::string nome;
    std::string apelido;
    int vitorias;
    int derrotas;
public:
    // Setters & Getters
    void setNome(const std::string nome);
    std::string getNome() const;

    void setApelido(const std::string apelido);
    std::string getApelido() const;

    void setVitorias(int vitorias);
    int getVitorias() const;
    
    void setDerrotas(int derrotas);
    int getDerrotas() const;

    // Método construtor
    Jogador(const std::string& nome, const std::string& apelido)
        : nome(nome), apelido(apelido), vitorias(0), derrotas(0) {} // Lista de inicialização
    
    void salvarJogador() const;
    static void carregarJogadores(std::vector<Jogador>& jogadores);
};

#endif // JOGADOR_hpp