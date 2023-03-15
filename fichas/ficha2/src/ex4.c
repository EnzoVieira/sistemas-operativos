#include "../include/ex4.h"

#include <stdio.h>
#include <unistd.h> // sys calls
#include <sys/wait.h> // wait() and macros

void ex4() {
  int i;

  for (i = 0; i < 10; i++) {
    if (!fork()) _exit(i+1);
  }

  for (i = 0; i < 10; i++) {
    int exitedChildCode;
    int childTerminatedPid = wait(&exitedChildCode);
    printf("Pai: child pid %d with exited code: %d\n", childTerminatedPid, WEXITSTATUS(exitedChildCode));
  }
}
