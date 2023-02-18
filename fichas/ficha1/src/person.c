#include "../include/person.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h> // open() O_RDONLY, O_WRONLY, O_CREAT, O_*
#include <unistd.h> // write()
#include <stdlib.h> // exit()

#define MAX_NAME_LEN 32
#define FILE_NAME "pessoas.bin"

struct person_t {
  char name[MAX_NAME_LEN];
  int age;
};

void printPerson(Person *p) {
  printf("Name: %s; Age: %d\n", p->name, p->age);
}

Person newPerson(char *name, int age) {
  Person p = {0};

  p.age = age;

  size_t nameLen = strlen(name);
  if (nameLen > MAX_NAME_LEN) {
    printf("Name too long\n");
    exit(1);
  }

  memcpy(p.name, name, nameLen);

  return p;
}

int writePerson(char *name, int age) {
  int fdDestiny = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0640);
  if (fdDestiny < 0) {
    perror("Error open");
    return -1;
  }

  Person person = newPerson(name, age);
  write(fdDestiny, &person, sizeof(person));

  close(fdDestiny);

  return 1;
}

int updatePerson(char *name, int newAge) {
  int fd = open(FILE_NAME, O_RDWR, 0640);
  if (fd < 0) {
    perror("Error open");
    return -1;
  }

  int resr = 0;
  Person p;
  while ( (resr = read(fd, &p, sizeof(p))) > 0 && strcmp(p.name, name) != 0 );

  // mover o ponteiro de arquivo
  if (lseek(fd,-(off_t) sizeof(p),SEEK_CUR) < 0) {
    perror("Error lseek");
    close(fd);
    return -1;
  }

  p.age = newAge;
  write(fd, &p, sizeof(p));

  close(fd);

  return 0;
}

int list() {
  int fd = open(FILE_NAME, O_RDONLY, 0640);
  if (fd < 0) {
    perror("Error open");
    return -1;
  }

  Person p;
  while (read(fd, &p, sizeof(p)) > 0) {
    printPerson(&p);
  }

  close(fd);

  return 0;
}
