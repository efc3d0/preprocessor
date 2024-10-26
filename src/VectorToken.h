#ifndef VECTORTOKEN_H
#define VECTORTOKEN_H
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  token_t **items;
  int total;
} VectorToken_t;

void vector_resize(VectorToken_t *v, int new_size) {
  token_t **new_items = realloc(v->items, sizeof(token_t *) * new_size);
  if (!new_items) {
    perror("error in memory allocating");
    return;
  }

  v->items = new_items;
}

token_t *vector_get(VectorToken_t *v, int index) {
  if (index >= 0 && index < v->total)
    return v->items[index];
  return NULL;
}

void vector_print(VectorToken_t *v, int index) {
  token_t *item = vector_get(v, index);
  if (item)
    token_print(item);
}

void vector_init(VectorToken_t *v) {
  v->total = 0;
  v->items = malloc(sizeof(token_t *) * 255);
}

void vector_add(VectorToken_t *v, token_t *item) {
  if (v->total % 255 == 0)
    vector_resize(v, v->total + 255);

  v->items[v->total++] = item;
}

void vector_deinit(VectorToken_t *v) { free(v); }
#endif
