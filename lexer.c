#include "lexer.h"
#include <stdlib.h>

char *read_argv_params(int, char *[]);

void read_char(Lexer *lexer) {
  if (lexer->readPosition >= lexer->size) {
    lexer->ch = 0;
    return;
  } else {
    lexer->ch = lexer->input[lexer->readPosition];
  }
  lexer->position = lexer->readPosition;
  lexer->readPosition++;
}

Lexer *new_lexer(char *input, size_t size) {
  Lexer *ptr = (Lexer *)malloc(sizeof(Lexer));
  ptr->input = input;
  ptr->position = 0;
  ptr->readPosition = 0;
  ptr->ch = 0;
  ptr->size = size;
  read_char(ptr);
  return ptr;
}

Token *next_lexer_token(Lexer *l) {
  Token *tok = (Token *)malloc(sizeof(Token));
  switch (l->ch) {
  case '{':
    tok = create_token(LBRACE, l->ch);
    break;
  case '}':
    tok = create_token(RBRACE, l->ch);
    break;
  case 0:
    tok = create_token(TOKEN_EOF, l->ch);
    return tok;
  default:
    tok = create_token(ILLEGAL, l->ch);
    break;
  }
  read_char(l);
  return tok;
}
