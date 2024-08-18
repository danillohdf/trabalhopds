#pragma once
#ifndef JOGADOR_hpp
#define JOGADOR_hpp

/* Inclusões */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>


/* Tipos/Classes */
class Jogador {
private:
    std::string nome;
    std::string apelido;
    int vitorias;
    int derrotas;
    static std::vector<Jogador> jogadores; // Lista de jogadores cadastrados

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

    //Método auxiliar para incrementar vitorias e derrotas
    void incrementarVitorias();
    void incrementarDerrotas();

    //Funções de gerenciamento de jogadores
    static void cadastrarJogador(const std::string& nome, const std::string& apelido);
    static void removerJogador(const std::string& apelido);
    static void listarJogadoresPorOrdemApelido();
    static void listarJogadoresPorOrdemNome();
    static Jogador* encontrarJogador(const std::string& apelido);

    // Método construtor
    Jogador(const std::string& nome, const std::string& apelido)
        : nome(nome), apelido(apelido), vitorias(0), derrotas(0) {} // Lista de inicialização
    
    void salvarJogador() const;
    static void carregarJogadores(std::vector<Jogador>& jogadores);
};

#endif // JOGADOR_hpp