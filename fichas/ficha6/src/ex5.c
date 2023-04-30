#include "../include/ex5.h"

#include <unistd.h>

void ex5() {
  int fd[2];

  char *command1[] = { "ls", "/etc", NULL };
  char *command2[] = { "wc", "-l", NULL };

  pipe(fd);

  if (fork() == 0) {
    close(fd[0]);

    dup2(fd[1], 1);
    close(fd[1]);

    execvp(command1[0], command1);

    _exit(0);
  }

  close(fd[1]);

  if (fork() == 0) {
    close(fd[1]);

    dup2(fd[0], 0);
    close(fd[0]);

    execvp(command2[0], command2);

    _exit(0);
  }

  close(fd[0]);
}