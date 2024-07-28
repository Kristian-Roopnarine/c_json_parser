#include "token.h"
#include <stdlib.h>

Token *create_token(const char *type, int literal) {
  Token *ptr = (Token *)malloc(sizeof(Token));
  ptr->type = type;
  ptr->literal = literal;
  return ptr;
};
