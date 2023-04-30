#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <limits.h> // PIPE_BUF

#include "../include/fifo.h"

int main() {
  int bytesRead;
  char buffer[PIPE_BUF];

  createFIFO();
  
  int fd = open("fifo", O_RDONLY);
  int fd2 = open("fifo", O_WRONLY);

  while ((bytesRead = read(fd, buffer, PIPE_BUF)) > 0) {
    write(1, buffer, bytesRead);
  }

  close(fd);
  close(fd2);

  return 0;
}
