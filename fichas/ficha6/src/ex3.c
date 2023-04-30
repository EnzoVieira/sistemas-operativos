#include "../include/ex3.h"

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

void ex3() {
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
    execlp("wc", "wc", NULL);

    _exit(0);
  }
}
