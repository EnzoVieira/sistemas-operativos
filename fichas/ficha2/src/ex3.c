#include "../include/ex3.h"

#include <stdio.h>
#include <unistd.h> // sys calls
#include <sys/wait.h> // wait() and macros

void ex3() {
  for (int i = 0; i < 10; i++) {
    int pid = fork();

    if (pid == 0) {
      printf("Filho: meu pid %d, pid do pai %d\n", getpid(), getppid());
      _exit(i + 1);
    }

    int exitedChildCode;
    int childPid = wait(&exitedChildCode);
  
    printf("Pai diz: pid do filho terminado %d com código %d\n", childPid, WEXITSTATUS(exitedChildCode));
  }
}
