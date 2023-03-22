#include "../include/ex7.h"

#include "../include/ex5.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> // rand()
#include <time.h> // time()
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_*

void printMatrix2() {
  int line, col;

  int fd = open("matrix.bin", O_CREAT | O_RDONLY, 0640);

  // just print col index numbers
  for (col = 0; col < COLS; col++) printf("%3d ", col);
  printf("\n\n");

  for (line = 0; line < LINES; line++) {
    for (col = 0; col < COLS; col++) {
      int buff;
      read(fd, &buff, sizeof(int));
      printf("%3d ", buff);
    }
    printf("  - %d\n", line);
  }

  close(fd);
}

void populateMatrix2() {
  int fd = open("matrix.bin", O_CREAT | O_RDWR | O_TRUNC, 0640);

  for (int line = 0; line < LINES; line++) {
    for(int col = 0; col < COLS; col++) {
      int generatedNum = rand() % 100;

      write(fd, &generatedNum, sizeof(int));
    }
  }

  close(fd);
}

void searchInMatrix() {
  for (int line = 0; line < LINES; line++) {
    if (fork() == 0) {

      int fd = open("matrix.bin", O_RDONLY, 0640);

      for (int col = 0; col < COLS; col++) {
        if ()
      }

      close(fd);
      _exit(-1);

    }
  }
}

int ex7() {
  populateMatrix2();
  printMatrix2();

  searchInMatrix();

  return 0;
}