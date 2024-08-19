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

    int vitoriasReversi;
    int derrotasReversi;
    int vitoriasLig4;
    int derrotasLig4;

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
    void incrementarVitoriasReversi();
    void incrementarVitoriasLig4();
    void incrementarDerrotasReversi();
    void incrementarDerrotasLig4();

    //Funções de gerenciamento de jogadores
    static void cadastrarJogador(const std::string& nome, const std::string& apelido);
    static void removerJogador(const std::string& apelido);
    static void listarJogadoresPorOrdemApelido();
    static void listarJogadoresPorOrdemNome();
    static Jogador* encontrarJogador(const std::string& apelido);

    // Método construtor
    Jogador(const std::string& nome, const std::string& apelido)
        : nome(nome), apelido(apelido), vitorias(0), derrotas(0) {} // Lista de inicialização
    
    static void salvarJogadores();
    static void carregarJogadores();
};

#endif // JOGADOR_hpp