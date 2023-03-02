CC = gcc
CFLAGS = -Wall -Wextra

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
	@$(BIN)/ficha1 -i "Enzo Vieira" 17
# @$(BIN)/ficha1 -i "Aline Borges" 18
# @$(BIN)/ficha1 -l
# @$(BIN)/ficha1 -u "Enzo Vieira" 20
# @$(BIN)/ficha1 -u "Aline Borges" 21
# @$(BIN)/ficha1 -l
# @$(BIN)/ficha1 -o 0 59
# @$(BIN)/ficha1 -o 36 60
# @$(BIN)/ficha1 -l
# @$(BIN)/ficha1

# Gera arquivos objeto
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $(SRC)/$*.c -I $(INCLUDE) -o $@

# Gera arquivo principal
$(BIN)/ficha1: $(FILES) $(APPS)/ficha1.c
	$(CC) $(CFLAGS) $(APPS)/ficha1.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/ficha1

clean_result:
	rm -rf pessoas.bin

clean:
	rm -rf $(OBJ)/* $(BIN)/* pessoas.bin