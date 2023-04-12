#include "../include/ex1Extra.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ex1Extra() {
  char str1[] = "isso é um teste\nessa é outra linha.";
  char str2[] = "teste";

  char *p = strstr(str1, str2);

  if (p)
    printf("First occurrence of string '%s' in '%s' is '%s'", str2, str1, p);
  else
    printf("String not found\n");
}
