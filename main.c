#include "lexer.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int BLKSIZE = 256 * 1024;

char *read_argv_params(int, char **);

int main(int argc, char **argv) {
  FILE *fd;
  char *file_name = (char *)malloc(sizeof(char) * 256);

  file_name = read_argv_params(argc, argv);
  if (file_name) {
    fd = fopen(file_name, "r");
  } else {
    fd = stdin;
  }

  size_t bytes_read = 0;
  size_t size = 0;
  char *buffer = (char *)malloc(sizeof(char) * BLKSIZE);
  do {
    bytes_read = fread(buffer, sizeof(char), BLKSIZE, fd);
    size += bytes_read;
  } while (bytes_read != 0);

  fclose(fd);

  Lexer *lexer = new_lexer(buffer, size);
  Parser *parser = new_parser(lexer);
  int res = parse_json(parser);
  printf("%d\n", res);
  return res;
}

char *read_argv_params(int argc, char **argv) {
  for (char **pArgv = argv + 1; *pArgv != argv[argc]; pArgv++) {
    for (char *i = *pArgv; *i != '\0'; i++) {
      return i;
    }
  }
  return 0;
}
