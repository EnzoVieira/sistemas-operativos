#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int i, status, numExecs = 0;

  for (i = 1; i < argc; i++) {
    char path[20] = "./bin/";
    strcat(path, argv[i]);

    if (fork() == 0) {
      do {
        status = system(path);
        sleep(i);
        numExecs++;
      } while (status != 0);

      printf("%s %d\n", argv[i], numExecs);

      _exit(EXIT_SUCCESS);
    }
  }

  for (i = 1; i < argc; i++) {
    pid_t childPid = wait(&status);
    printf("[father] Child %d exited with status %d\n", childPid, WEXITSTATUS(status));
  }

  return 0;
}
