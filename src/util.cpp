/* Inclusões */
#include "util.hpp"
#include <iostream>

/* Funções */
void util_ImprimeTracinhos(int nTracinhos){
    for(int i = 0; i < nTracinhos; i++){
        std::cout << "-";
    }
    std::cout << '\n';
}

void util_removeQuebraLinhaFinal(std::string& dados){
    if(!dados.empty() && dados.back() == '\n'){
        dados.pop_back();
    }
}