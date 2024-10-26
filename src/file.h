#ifndef FILE_H
#define FILE_H

#include "Token.h"
#include "flag.h"
#include "stdarg.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define read_only 00
#define write_only 01
#define read_write 02
#define ONE_BLOCK 4096

typedef struct {
  int fileDescriptor;
  char *buffer;
} file_t;

file_t *init_file(file_t *file, char *path, flag_t *flags) {
  file->fileDescriptor = open(path, flags->flags);
  file->buffer = malloc(sizeof(ONE_BLOCK));
  return file;
}

void read_file(file_t *file, int size) {
  read(file->fileDescriptor, file->buffer, size);
}

void print_buffer(file_t *file) { printf("%s", file->buffer); }

#endif
