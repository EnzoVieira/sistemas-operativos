#ifndef PERSON_H
#define PERSON_H

typedef struct person_t Person;

int writePerson(char *name, int age);
int updatePerson(char *name, int newAge);
int updateByRegister(int reg, int newAge);
int list();

#endif
