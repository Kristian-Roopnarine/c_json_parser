#ifndef _PARSERH_
#define _PARSERH_
#include "lexer.h"
#include <stdbool.h>

typedef struct Parser {
  Token *currToken;
  Token *peekToken;
  Lexer *l;

} Parser;

Parser *new_parser(Lexer *);
void next_parser_token(Parser *);
int parse_program(Parser *);
int parse_json(Parser *);
int parse_key(Parser *);
int parse_value(Parser *);
bool peek_token_is(const char *, const char *);

#endif
