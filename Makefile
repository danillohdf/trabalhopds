# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos Source e Object
SRCS = $(wildcard $(SRC_DIR)/*.cpp) # Pega todos os arquivos *.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS)) # Converte-os em *.o
TARGET = $(BIN_DIR)/jogo

# Compilador
CXX = g++

# Flags
CXX_FLAGS = -O2        \
            -Wall      \
            -Wextra    \
            -Wpedantic \
            -std=c++17 \

# Target
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -o $@ $^

# Compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
