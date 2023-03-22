CC = gcc
CFLAGS = -Wall -Wextra

APPS = ./apps
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
SRC = ./src

FILES = $(wildcard $(SRC)/*.c)
DEPS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(FILES))

all: $(DEPS) $(BIN)/ficha2

run: $(DEPS) $(BIN)/ficha2
	@$(BIN)/ficha2

# Gera arquivos objeto
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $(SRC)/$*.c -I $(INCLUDE) -o $@

# Gera arquivo principal
$(BIN)/ficha2: $(FILES) $(APPS)/ficha2.c
	$(CC) $(CFLAGS) $(APPS)/ficha2.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/ficha2

clean_result:
	rm -rf matrix.bin

clean:
	rm -rf $(OBJ)/* $(BIN)/* matrix.bin