# Projeto de Jogos

Este projeto implementa jogos de tabuleiro, como Reversi e Lig4, com um sistema de gerenciamento de jogadores. O projeto é construído em C++ e utiliza o [doctest](https://github.com/doctest/doctest) para testes unitários.

## Estrutura do Projeto

- `bin/`: Contém os executáveis gerados pela compilação.
- `include/`: Contém arquivos de cabeçalho (.hpp).
- `obj/`: Guarda arquivos objeto (.o ou .obj) criados durante a compilação.
- `src/`: Contém arquivos de código-fonte (.cpp).
- `tests/`: Abriga arquivos de teste para validação do código.
- `.gitignore`: Lista arquivos e pastas que o Git deve ignorar.
- `Makefile`: Contém instruções para automatizar a compilação do projeto.
- `README.md`: Fornece informações sobre o projeto, como descrição e instruções.


### Compilar o Projeto

Para compilar o projeto, utilize o comando:
make

Para compilar e executar os testes, utilize o comando:
make test


### Como Usar
Compile o projeto com make.

Execute o programa principal com o comando:
./bin/main.exe

No menu interativo, você pode:

Cadastrar um novo jogador: CJ <Apelido> <Nome>
Remover um jogador: RJ <Apelido>
Listar jogadores por ordem de apelido ou nome: LJ [A|N]
Executar uma partida de Reversi ou Lig4: EP [R|L] <Jogador1> <Jogador2>
Finalizar o sistema: FS

### Como rodar o arquivo teste.
Compile o arquivo de teste com make test

Execute o arquivo de teste com o comando:
./bin/test_reversi.exe