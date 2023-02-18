#include "../include/mycp.h"
#include "../include/mycat.h"
#include "../include/person.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // mycp(argv[1], argv[2]);
  // mycat();

  if (argc == 4 && strcmp("-i", argv[1]) == 0) {
    writePerson(argv[2], atoi(argv[3]));
  }
  else if (argc == 4 && strcmp("-u", argv[1]) == 0) {
    updatePerson(argv[2], atoi(argv[3]));
  }
  else if (argc == 2 && strcmp("-l", argv[1]) == 0) {
    list();
  }

  return 0;
}
