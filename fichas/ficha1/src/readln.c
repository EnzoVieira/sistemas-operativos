#include "../include/readln.h"

#include <stdio.h>
#include <fcntl.h> // open() O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <stdlib.h> // exit()

ssize_t readch(int fd, char *buffer) {
  return read(fd, buffer, 100);
}

ssize_t readln(int fd, char *buffer, int size) {
  int i = 0, syscalls = 0;
  ssize_t bytesRead = 0;

  while (i < size - 1 && (bytesRead += readch(fd, buffer)) > 0) {
    write(STDOUT_FILENO, buffer, bytesRead);

    if (buffer[bytesRead] == '\n') break;
    i++;
    syscalls++;
  }

  printf("readln() - Read bytes: %zd; System calls: %d\n", bytesRead, syscalls);

  return bytesRead;
}
