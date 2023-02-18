#include "../include/mycp.h"

#include <stdio.h>
#include <fcntl.h> // open() O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <unistd.h> // write()
#include <stdlib.h> // exit()

#define MAX_BUFFER_SIZE 1000

int mycp(const char *fromPath, const char *toPath) {
  int bytesWriten = 0, bytesRead = 0, nsyscalls = 0;
  ssize_t resr = 0, resw = 0;
  char buffer[MAX_BUFFER_SIZE];

  int fdOrigin = open(fromPath, O_RDONLY);
  if (fdOrigin < 0) {
    perror("Error open");
    return -1;
  }

  int fdDestiny = open(toPath, O_WRONLY | O_CREAT | O_TRUNC, 0640);
  if (fdDestiny < 0) {
    perror("Error open");
    return -1;
  }

  while ((resr = read(fdOrigin, buffer, MAX_BUFFER_SIZE)) > 0) {
    bytesRead += resr;

    resw = write(fdDestiny, buffer, resr);
    bytesWriten += resw;

    nsyscalls += 2;
  }

  printf("calls: %d\n", nsyscalls);

  close(fdOrigin);
  close(fdDestiny);

  if (bytesWriten - bytesRead != 0) {
    return -1;
  }

  return 0;
}
