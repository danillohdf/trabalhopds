# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = $(BIN_DIR)/main.exe
TEST_TARGET = $(BIN_DIR)/test_reversi.exe

# Regra para compilar o executável principal
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar o executável de teste
$(TEST_TARGET): $(OBJS) obj/test_reversi.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) obj/test_reversi.o

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar o arquivo de teste
obj/test_reversi.o: tests/test_reversi.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objetos e executáveis
clean:
	powershell -Command "Remove-Item -Path $(OBJ_DIR)\*.o -ErrorAction SilentlyContinue"
	powershell -Command "Remove-Item -Path $(TARGET) -ErrorAction SilentlyContinue"
	powershell -Command "Remove-Item -Path $(TEST_TARGET) -ErrorAction SilentlyContinue"
