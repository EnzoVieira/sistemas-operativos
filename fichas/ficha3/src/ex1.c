#include "../include/ex1.h"

#include <stdio.h>
#include <unistd.h>

int ex1() {
  printf("[1.0] Before execute\n");

  int ret = execlp("ls", "ls", "-l", NULL);
  perror("Exec error");

  printf("[1.0] After execute\n");

  return ret;
}
