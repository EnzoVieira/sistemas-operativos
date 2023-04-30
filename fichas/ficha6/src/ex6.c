#include "../include/ex6.h"

#include <unistd.h>

#define RD_END 0
#define WR_END 1

void ex6() {
  int i;

  char *commands[][5] = {
    { "grep", "-v", "^#", "/etc/passwd", NULL },
    { "cut", "-f7", "-d:", NULL },
    { "uniq", NULL },
    { "wc", "-l", NULL }
  };
  int numberOfCommands = 4;
  int fd[3][2];
  
  for (i = 0; i < numberOfCommands; i++) {

    // if first command
    if (i == 0) {
      // Create pipe
      pipe(fd[i]);

      if (fork() == 0) {
        close(fd[i][RD_END]);

        // Redirects STDOUT to pipe
        dup2(fd[i][WR_END], STDOUT_FILENO);
        close(fd[i][WR_END]);

        execvp(commands[i][0], commands[i]);

        _exit(0);
      }

      close(fd[i][WR_END]);
    }

    // If last command
    else if (i == numberOfCommands-1) {
      if (fork() == 0) {
        // Reads from last pipe
        dup2(fd[i-1][RD_END], STDIN_FILENO);
        close(fd[i-1][RD_END]);

        execvp(commands[i][0], commands[i]);

        _exit(0);
      }
    }

    // If not the first neither the last
    else {
      // Create pipe
      pipe(fd[i]);

      if (fork() == 0) {
        close(fd[i][RD_END]);

        // Reads from last pipe
        dup2(fd[i-1][RD_END], STDIN_FILENO);
        close(fd[i-1][RD_END]);

        // Writes to next pipe
        dup2(fd[i][WR_END], STDOUT_FILENO);
        close(fd[i][WR_END]);

        execvp(commands[i][0], commands[i]);

        _exit(0);
      }

      close(fd[i][WR_END]);
    }
  }
}
