#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/ex3.h"
#include "../include/ex4.h"
#include "../include/ex5.h"
#include "../include/ex6.h"
#include "../include/ex7.h"

int main() {
  // int pid = fork();
  // if (pid < 0) {
  //   perror("Error fork");
  //   return -1;
  // }

  // if (pid == 0) {
  //   printf("Filho diz: pid %d\n", getpid());
  //   printf("Filho diz: pid pai %d\n", getppid());
  // } else {
  //   wait(NULL);
  //   printf("Pai diz: pid %d\n", getpid());
  //   printf("Pai diz: pid pai %d\n", getppid());
  // }

  // ex3();
  // ex4();
  // ex5();
  // ex6();
  ex7();

  return 0;
}
