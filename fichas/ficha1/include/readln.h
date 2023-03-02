#ifndef READLN_H
#define READLN_H

#include <unistd.h> // ssize_t

#define READLN_MAX_BUFFER_SIZE 1024
#define READLN_FILE_PATH "readlnTest.txt"

ssize_t readln(int fd, char *buffer, int size);

#endif
