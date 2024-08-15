#pragma once
#ifndef UTIL_h
#define UTIL_h

/* Inclusões */
#include <string>

/* Funções */

/**
 * Função auxiliar para imprimir hífens.
 * @param nTracinhos Número de tracinhos a ser impresso.
 */
void util_ImprimeTracinhos(int nTracinhos);
/**
 * Função que remove o \n deixado pelo fgets().
 * @param dados Endereço da string a ser modificada.
 */
void util_removeQuebraLinhaFinal(std::string& dados);

#endif  // UTIL_h