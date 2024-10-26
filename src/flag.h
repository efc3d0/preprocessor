
#ifndef FLAG_H
#define FLAG_H

typedef struct {
  int flags;
} flag_t;

flag_t *init_flags(flag_t *ptr, int flag) {
  ptr->flags = flag;
  return ptr;
}

#endif
