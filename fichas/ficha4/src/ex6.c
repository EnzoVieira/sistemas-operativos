#include "../include/ex6.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LINES 10
#define COLS 49

typedef struct {
  int line;
  int findedLength;
  int findedInCols[COLS];
} ProcessDTO;

void createMatrix(int matrix[LINES][COLS]) {
  for (int line = 0; line < LINES; line++) {
    for (int col = 0; col < COLS; col++) {
      matrix[line][col] = rand() % 10;
    }
  }
}

void printMatrix(int matrix[LINES][COLS]) {
  int line, col;

  // just print col index numbers
  for (col = 0; col < COLS; col++) printf("%3d ", col+1);
  printf("\n");
  for (col = 0; col < COLS; col++) printf("----");
  printf("\n");

  for (line = 0; line < LINES; line++) {
    for (col = 0; col < COLS; col++) {
      printf("%3d ", matrix[line][col]);
    }
    printf(" | %d\n", line+1);
  }
}

void search(int matrix[LINES][COLS], int needle, ProcessDTO *processDTO) {
  int findedVectorIndex = 0;

  for (int col = 0; col < COLS; col++) {
    int currentInt = matrix[processDTO->line][col];
    
    if (currentInt == needle) {
      processDTO->findedInCols[findedVectorIndex++] = col+1;
      processDTO->findedLength++;
    }
  }
}

void ex6() {
  int fd[2];
  int matrix[LINES][COLS];

  createMatrix(matrix);
  printMatrix(matrix);

  pipe(fd);

  // create forks for each line
  for (int line = 0; line < LINES; line++) {

    // put them to search the int and write in pipe
    if (fork() == 0) {
      close(fd[0]);

      ProcessDTO pdto;
      pdto.line = line;
      pdto.findedLength = 0;

      search(matrix, line+4, &pdto);

      write(fd[1], &pdto, sizeof(ProcessDTO));

      close(fd[1]);
      _exit(0);
    }

  }

  close(fd[1]);

  // read from pipe of each fork created
  for (int line = 0; line < LINES; line++) {
    ProcessDTO pdto;

    read(fd[0], &pdto, sizeof(ProcessDTO));

    for (int i = 0; i < pdto.findedLength; i++) {
      printf("[father] Encontrado %d na coluna %d linha %d\n", line+4, pdto.findedInCols[i], pdto.line+1);
    }
  }

  close(fd[0]);
}
