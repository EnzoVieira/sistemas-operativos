#include "../include/ex2.h"

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

void ex2() {
  ssize_t bytesRead;

  int fdetc = open("/etc/passwd", O_RDONLY, 0666);
  int fdsaida = open("./saida.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
  int fderror = open("./erros.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);

  dup2(fdetc, 0);
  close(fdetc);

  dup2(fdsaida, 1);
  close(fdsaida);

  dup2(fderror, 2);
  close(fderror);

  if (fork() == 0 ) {
    char buffer[PIPE_BUF];
    while ((bytesRead = read(0, buffer, PIPE_BUF)) > 0) {
      write(1, buffer, bytesRead);
    }

    printf("terminei\n");
    // fflush(stdout);

    _exit(0);
  }
}
