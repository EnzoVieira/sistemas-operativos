#include "../include/ex2.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int ex2() {
  printf("[father] Before execute\n");

  if (fork() == 0) {
    printf("[child] Before execute\n");

    int ret = execlp("ls", "ls", "-l", NULL);
    perror("Exec error");

    printf("[child] After execute\n");
    _exit(ret);
  }

  wait(NULL);
  printf("[father] After execute\n");

  return 0;
}
