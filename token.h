#ifndef _TOKENH_
#define _TOKENH_
#include <stdlib.h>

typedef struct Token {
  int literal;
  const char *type;
} Token;

Token *create_token(const char *, int);

static const char *LBRACE = "LBRACE";
static const char *RBRACE = "RBRACE";
static const char *COLON = "COLON";
static const char *ILLEGAL = "ILLEGAL";
static const char *TOKEN_EOF = "TOKEN_EOF";

#endif
