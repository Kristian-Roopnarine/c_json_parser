#include "parser.h"
#include <stdlib.h>
#include <string.h>

Parser *new_parser(Lexer *l) {
  Parser *p = (Parser *)malloc(sizeof(Parser));
  p->l = l;
  // sets up parser to fill currToken and peekToken
  next_parser_token(p);
  next_parser_token(p);
  return p;
}

void next_parser_token(Parser *p) {
  p->currToken = p->peekToken;
  p->peekToken = next_lexer_token(p->l);
}

int parse_key(Parser *p) { return 0; }

int parse_value(Parser *p) { return 0; }

int parse_json(Parser *p) {
  if (!peek_token_is(p->currToken->type, LBRACE)) {
    return 1;
  }

  if (peek_token_is(p->currToken->type, RBRACE)) {
    return 0;
  }

  return 1;
}

bool peek_token_is(const char *current_type, const char *expected_type) {
  return strcmp(current_type, expected_type) == 0;
}
