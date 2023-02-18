CC = gcc

APPS = ./apps
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
SRC = ./src

all: mylibs myapps

run: mylibs myapps
	rm -rf pessoas.bin
	$(BIN)/ficha1 -i "Enzo Vieira" 17
	$(BIN)/ficha1 -i "Aline Borges" 18
	$(BIN)/ficha1 -l
	$(BIN)/ficha1 -u "Enzo Vieira" 20
	$(BIN)/ficha1 -u "Aline Borges" 21
	$(BIN)/ficha1 -l

mylibs: \
			$(OBJ)/mycp.o \
			$(OBJ)/mycat.o \
			$(OBJ)/person.o

myapps: $(BIN)/ficha1

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	$(CC) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

clear:
	rm -rf $(BIN)/* $(OBJ)/* pessoas.txt
