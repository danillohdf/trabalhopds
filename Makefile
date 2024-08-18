# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos Source e Object
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/jogo.exe

# Compilador
CXX = g++
CXX_FLAGS = -O2 -Wall -Wextra -Wpedantic -std=c++17

# Comandos específicos para Windows
MKDIR = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
RM = rmdir /s /q

# Target principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJS)
	@echo "Criando diretório $(BIN_DIR)"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -o $@ $^

# Compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compilando $<"
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

# Limpeza
clean:
	@echo "Limpando diretórios"
	$(RM) $(OBJ_DIR) 2>nul || true
	$(RM) $(BIN_DIR) 2>nul || true
