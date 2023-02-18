#ifndef PERSON_H
#define PERSON_H

typedef struct person_t Person;

void printPerson(Person *p);
int writePerson(char *name, int age);
int updatePerson(char *name, int newAge);
int list();

#endif
