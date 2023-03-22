#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Invalid arguments\n");
    exit(-1);
  }

  for (int i = 1; i < argc; i++) {
    if (fork() == 0) {
      printf("[child] Executing %s\n", argv[i]);
      int ret = execlp(argv[i], argv[i], NULL);

      perror("Execute error");
      _exit(ret);
    }
  }

  return 1;
}
