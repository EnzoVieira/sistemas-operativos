#include "../include/mycp.h"
#include "../include/mycat.h"
#include "../include/person.h"
#include "../include/readln.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h> // open() O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <unistd.h> // close()

int main(int argc, char *argv[]) {
  // mycp(argv[1], argv[2]);
  // mycat();

  // PERSON_H
  if (argc == 4 && strcmp("-i", argv[1]) == 0) {
    writePerson(argv[2], atoi(argv[3]));
  }
  else if (argc == 4 && strcmp("-u", argv[1]) == 0) {
    updatePerson(argv[2], atoi(argv[3]));
  }
  else if (argc == 4 && strcmp("-o", argv[1]) == 0) {
    updateByRegister(atoi(argv[2]), atoi(argv[3]));
  }
  else if (argc == 2 && strcmp("-l", argv[1]) == 0) {
    list();
  }

  // READLN_H
  int fdReadln = open(READLN_FILE_PATH, O_RDONLY | O_CREAT, 0640);
  if (fdReadln < 0) {
    perror("Error open");
    return -1;
  }

  char buffer[READLN_MAX_BUFFER_SIZE];
  readln(fdReadln, buffer, READLN_MAX_BUFFER_SIZE);

  close(fdReadln);

  return 0;
}
