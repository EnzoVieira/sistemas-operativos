#include "../include/ex5.h"
#include "../include/ex6.h"

#include <stdio.h>
#include <unistd.h> // sys calls
#include <sys/wait.h> // wait() and macros
#include <stdlib.h> // rand()

void printPidArray(pid_t *arr) {
  for (int i = 0; i < LINES; i++) {
    printf("pid: %d\n", arr[i]);
  }
}

void ex6() {
  int line, col;

  int matrix[LINES][COLS];
  populateMatrix(matrix);

  int toFindNum = 5;

  pid_t pidsArray[LINES];

  // For each line, creates a process
  for (line = 0; line < LINES; line++) {
    pid_t pid = fork();
    if (pid == 0) {

      // each process should search in one col
      for (col = 0; col < COLS; col++) {
        if (matrix[line][col] == toFindNum) {
          _exit(line+1);
        }
      }

      _exit(0);
    }

    pidsArray[line] = pid;
  }

  printPidArray(pidsArray);

  // for each child, wait
  for (line = 0; line < LINES; line++) {
    int childExitCode;
    pid_t terminatedChildPid = waitpid(pidsArray[line], &childExitCode, 0);

    if (childExitCode > 0) {
      printf("[pai] Número encontrado pelo filho: %d; linha: %d\n", terminatedChildPid, WEXITSTATUS(childExitCode));
    }
  }
}
