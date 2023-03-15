#include "../include/ex5.h"

#include <stdio.h>
#include <unistd.h> // sys calls
#include <sys/wait.h> // wait() and macros
#include <stdlib.h> // rand()

void populateMatrix(int matrix[LINES][COLS]) {
  int line;
  int col;

  for (line = 0; line < LINES; line++) {
    for (col = 0; col < COLS; col++) {
      matrix[line][col] = rand() % 100;
    }
  }
}

void printMatrix(int matrix[LINES][COLS]) {
  int line, col;

  // just print col index numbers
  for (col = 0; col < COLS; col++) printf("%3d ", col);
  printf("\n\n");

  for (line = 0; line < LINES; line++) {
    for (col = 0; col < COLS; col++) {
      printf("%3d ", matrix[line][col]);
    }
    printf("  - %d\n", line);
  }
}

void ex5() {
  int line, col;

  int matrix[LINES][COLS];
  populateMatrix(matrix);

  int toFindNum = 5;

  // For each line, creates a process
  for (line = 0; line < LINES; line++) {
    if (fork() == 0) {

      // each process should search in one col
      for (col = 0; col < COLS; col++) {
        if (matrix[line][col] == toFindNum) {
          _exit(line);
        }
      }
      _exit(0);
    }
  }

  // for each child, wait
  for (line = 0; line < LINES; line++) {
    int childExitCode;
    pid_t terminatedChildPid = wait(&childExitCode);

    if (childExitCode > 0) {
      printf("[pai] Número encontrado pelo filho: %d; linha: %d\n", terminatedChildPid, WEXITSTATUS(childExitCode));
    }
  }
}
