#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <limits.h> // PIPE_BUF

int main() {
  int bytesRead;
  char buffer[PIPE_BUF];

  printf("[client] Open\n");
  int fd = open("fifo", O_WRONLY);

  while ((bytesRead = read(0, buffer, PIPE_BUF)) > 0) {
    write(fd, buffer, bytesRead);
  }

  printf("[client] Close\n");
  close(fd);

  return 0;
}
