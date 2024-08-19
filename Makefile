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

# Regra para compilar o executável
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objetos e executáveis
clean:
	powershell -Command "Remove-Item -Path $(OBJ_DIR)\*.o -ErrorAction SilentlyContinue"
	powershell -Command "Remove-Item -Path $(TARGET) -ErrorAction SilentlyContinue"
