#include "../include/ex1.h"

#include <stdio.h>
#include <unistd.h>

void ex1() {
  int fd[2];

  pipe(fd);

  if (fork() == 0) {
    close(fd[1]);

    int res = 0;
    read(fd[0], &res, sizeof(int));

    close(fd[0]);

    printf("[child] Recebi %d\n", res);
    _exit(0);
  }

  close(fd[0]);

  int i = 1000;
  printf("[father] Enviando %d em 5s\n", i);
  sleep(5);
  write(fd[1], &i, sizeof(int));

  close(fd[1]);
}
