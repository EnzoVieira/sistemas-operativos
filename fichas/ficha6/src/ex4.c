#include "../include/ex4.h"

#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void ex4() {
  ssize_t bytesRead;
  int fd[2];

  pipe(fd);

  if (fork() == 0) {
    close(fd[1]);

    dup2(fd[0], 0);
    close(fd[0]);

    execlp("wc", "wc", NULL);

    _exit(0);
  }

  close(fd[0]);

  char buffer[PIPE_BUF];
  while ((bytesRead = read(0, buffer, PIPE_BUF)) > 0) {
    write(fd[1], buffer, bytesRead);
  }

  close(fd[1]);
}
