#include "lexer.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CHUNKSIZE = 16 * 1024;

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

  size_t size = 0;
  size_t index = 0;
  char *buffer = NULL, *tmp = NULL;
  int ch;

  while ((ch = fgetc(fd)) != EOF) {
    if (size <= index) {
      size += CHUNKSIZE;
      tmp = realloc(buffer, size);
      if (!tmp) {
        printf("issue with allocating more memory");
        free(buffer);
        break;
      }
      buffer = tmp;
    }
    buffer[index++] = ch;
  }

  free(tmp);

  Lexer *lexer = new_lexer(buffer, index);
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
