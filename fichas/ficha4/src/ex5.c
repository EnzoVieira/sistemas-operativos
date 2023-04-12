#include "../include/ex5.h"

#include <stdio.h>
#include <unistd.h>

void ex5() {
  int fd[2];
  pipe(fd);

  if (fork() == 0) {
    close(fd[0]);

    int i = 1;

    while (i < 10) {
      printf("[child] Enviando %d\n", i);
      write(fd[1], &i, sizeof(int));

      i++;
    }

    close(fd[1]);
    _exit(0);
  }

  close(fd[1]);

  int res = 0;

  while (read(fd[0], &res, sizeof(int)) != 0) {
    printf("[father] Recebi %d\n", res);
  }

  close(fd[0]);
}
