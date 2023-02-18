#include "../include/mycat.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1000

int mycat() {
  char buffer[MAX_BUFFER_SIZE];
  int resr = 0;

  while ((resr = read(0, buffer, MAX_BUFFER_SIZE)) > 0) {
    write(1, buffer, resr);
  }

  return 0;
}
