# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

# Arquivos fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/test_%.o, $(TEST_SRCS))

# Nome dos executáveis
TARGET = $(BIN_DIR)/main.exe
TEST_TARGET = $(BIN_DIR)/test_reversi.exe

# Regra para compilar o executável principal
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar o executável de teste
$(TEST_TARGET): $(OBJ_DIR)/test_reversi.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogo.o $(OBJ_DIR)/reversi.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_DIR)/test_reversi.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogo.o $(OBJ_DIR)/reversi.o -Iinclude

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar arquivos de teste .cpp em .o
$(OBJ_DIR)/test_reversi.o: $(TEST_DIR)/test_reversi.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objetos e executáveis
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(TEST_TARGET)

# Regra para executar testes
test: $(TEST_TARGET)
	$(TEST_TARGET)