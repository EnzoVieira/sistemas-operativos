CC = gcc
CFLAGS = -Wall -Wextra

APPS = ./apps
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
SRC = ./src

APPS_FILES = $(wildcard $(APPS)/*.c)
APPS_TARGET = $(patsubst $(APPS)/%.c, $(BIN)/%.out, $(APPS_FILES))

FILES = $(wildcard $(SRC)/*.c)
DEPS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(FILES))

all: $(DEPS) $(APPS_TARGET)

run: $(DEPS) $(APPS_TARGET)
	@$(BIN)/main.out

# Gera arquivos objeto
$(OBJ)/%.o: $(FILES)
	$(CC) $(CFLAGS) -c $(SRC)/$*.c -I $(INCLUDE) -o $@

# Gera arquivo principal
$(BIN)/%.out: $(FILES) $(APPS_FILES)
	$(CC) $(CFLAGS) $(APPS)/$*.c $(OBJ)/*.o -I $(INCLUDE) -o $@

### EX 4.2
cont: $(BIN)/controller.out
	$(BIN)/controller.out a.out b.out c.out

$(BIN)/controller.out: $(APPS)/controller.c
	$(CC) $(CFLAGS) $(APPS)/controller.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/controller.out
	@gcc -Wall aux.c -o $(BIN)/a.out
	@gcc -Wall aux.c -o $(BIN)/b.out
	@gcc -Wall aux.c -o $(BIN)/c.out
###


clean:
	rm -rf $(OBJ)/* $(BIN)/*