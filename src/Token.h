#ifndef TOKEN_H
#define TOKEN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  Sharp,      // #
  LeftParen,  // (
  RightParen, // )
  LeftBrace,  // {
  RightBrace, // }
  Comma,      // ,
  Dot,        // .
  Plus,       // +
  Minus,      // -
  Mod,        // %
  Equal,      // =
  Backslash,  // \

  // Keywords

  define,
  ifdef,
  if_,
  else_,
  elif_,
} TokenType;

typedef struct {
  TokenType token_type;
} token_t;

void push_token(token_t *token_structure, TokenType token_type) {
  token_structure->token_type = token_type;
}

void token_print(token_t *token) {
  switch (token->token_type) {
  case Sharp:
    printf("Token: Sharp (#)\n");
    break;
  case LeftParen:
    printf("Token: LeftParen ('(')\n");
    break;
  case RightParen:
    printf("Token: RightParen (')')\n");
    break;
  case LeftBrace:
    printf("Token: LeftBrace ('{')\n");
    break;
  case RightBrace:
    printf("Token: RightBrace ('}')\n");
    break;
  case Comma:
    printf("Token: Comma (',')\n");
    break;
  case Dot:
    printf("Token: Dot ('.')\n");
    break;
  case Plus:
    printf("Token: Plus ('+')\n");
    break;
  case Minus:
    printf("Token: Minus ('-')\n");
    break;
  case Mod:
    printf("Token: Mod ('%')\n");
    break;
  case Equal:
    printf("Token: Equal ('=')\n");
    break;
  case Backslash:
    printf("Token: Backslash ('\')\n");
    break;

  case define:
    printf("Token: define ('#define')\n");
    break;
  case ifdef:
    printf("Token: ifdef ('#ifdef')\n");
    break;
  case if_:
    printf("Token: if_ ('#if')\n");
    break;
  case else_:
    printf("Token: else_ ('#else')\n");
    break;
  case elif_:
    printf("Token: elif_ ('#elif')\n");
    break;
  }
}

TokenType get_token_type(token_t *token) {
  switch (token->token_type) {
  case Sharp:
    return Sharp;
    break;
  case LeftParen:
    return LeftParen;
    break;
  case RightParen:
    return RightParen;
    break;
  case LeftBrace:
    return LeftBrace;
    break;
  case RightBrace:
    return RightBrace;
    break;
  case Comma:
    return Comma;
    break;
  case Dot:
    return Dot;
    break;
  case Plus:
    return Plus;
    break;
  case Minus:
    return Minus;
    break;
  case Mod:
    return Mod;
    break;
  case Equal:
    return Equal;
    break;
  case Backslash:
    return Backslash;
    break;
  case define:
    return define;
    break;
  case ifdef:
    return ifdef;
    break;
  case if_:
    return if_;
    break;
  case else_:
    return else_;
    break;
  case elif_:
    return elif_;
    break;
  }
}

TokenType get_token_from_str(char *buffer) {
  if (strcmp(buffer, "#") == 0)
    return Sharp;
  else if (strcmp(buffer, "(") == 0)
    return LeftParen;
  else if (strcmp(buffer, ")") == 0)
    return RightParen;
  else if (strcmp(buffer, "{") == 0)
    return LeftBrace;
  else if (strcmp(buffer, "}") == 0)
    return RightBrace;
  else if (strcmp(buffer, ",") == 0)
    return Comma;
  else if (strcmp(buffer, ".") == 0)
    return Dot;
  else if (strcmp(buffer, "+") == 0)
    return Plus;
  else if (strcmp(buffer, "-") == 0)
    return Minus;
  else if (strcmp(buffer, "=") == 0)
    return Equal;
  else if (strcmp(buffer, "\\") == 0)
    return Backslash;
  else if (strcmp(buffer, "#define") == 0)
    return define;
  else if (strcmp(buffer, "#ifdef") == 0)
    return ifdef;
  else if (strcmp(buffer, "#if") == 0)
    return if_;
  else if (strcmp(buffer, "#else") == 0)
    return else_;
  else if (strcmp(buffer, "#elif") == 0)
    return elif_;
}
token_t **get_tokens(int count, TokenType ftoken, ...) {
  va_list ap;
  int i;
  token_t **result = malloc(count * sizeof(token_t *));

  result[0] = malloc(sizeof(token_t));
  push_token(result[0], ftoken);

  va_start(ap, ftoken);

  for (i = 1; i < count; i++) {
    result[i] = malloc(sizeof(token_t));
    TokenType token = va_arg(ap, TokenType);

    push_token(result[i], token);
  }
  va_end(ap);

  return result;
}

/*void init_token_t(token_t * token_structure,
                  TokenType tok_type)
{
  token_structure->token_type = tok_type;
}*/

void token_deinit(token_t *t) { free(t); }

#endif
