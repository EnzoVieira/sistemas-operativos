CC = gcc

APPS = ./apps
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
SRC = ./src

FILES = $(wildcard $(SRC)/*.c)
DEPS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(FILES))

all: $(DEPS) $(BIN)/ficha1

run: $(DEPS) $(BIN)/ficha1
	@rm -rf pessoas.bin
	$(BIN)/ficha1 -i "Enzo Vieira" 17
	$(BIN)/ficha1 -i "Aline Borges" 18
	$(BIN)/ficha1 -l
	$(BIN)/ficha1 -u "Enzo Vieira" 20
	$(BIN)/ficha1 -u "Aline Borges" 21
	$(BIN)/ficha1 -l

# Gera arquivos objeto
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(SRC)/$*.c -I $(INCLUDE) -o $@

# Gera arquivo principal
$(BIN)/ficha1: $(FILES) $(APPS)/ficha1.c
	$(CC) $(APPS)/ficha1.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/ficha1

clean:
	rm -rf $(OBJ)/* $(BIN)/* pessoas.bin