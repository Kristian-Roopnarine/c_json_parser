#ifndef _LEXERH_
#define _LEXERH_
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Lexer {
  char *input;
  int position;
  int readPosition;
  int ch;
  size_t size;
} Lexer;

void read_char(Lexer *lexer);
Lexer *new_lexer(char *input, size_t size);
Token *next_lexer_token(Lexer *);

#endif
