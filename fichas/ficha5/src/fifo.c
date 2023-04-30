#include "../include/fifo.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int createFIFO() {
  int res = mkfifo("fifo", 0666);
  if (res == -1) {
    perror("FIFO error");
    return -1;
  }

  printf("Created FIFO\n");

  return res;
}
