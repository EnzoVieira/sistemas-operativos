#include "../include/ex4.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int mysystem(const char *command) {
  char *tok;
  char *commandsArr[30];

  char *commandCopy = strdup(command);

  // Create array of command args
  int i = 0;
  while ((tok = strsep(&commandCopy, " ")) != NULL) {
    commandsArr[i] = strdup(tok);
    i++;
  }
  commandsArr[i] = NULL;

  // Create fork and exec commands
  if (fork() == 0) {
    int ret = execvp(commandsArr[0], commandsArr);

    perror("Error execvp");
    _exit(ret);
  }

  int status;
  pid_t childPid = wait(&status);

  printf("[father] Exited pid %d with status %d\n", childPid, WEXITSTATUS(status));

  return status;
}
