#include "Token.h"
#include "file.h"
#include "flag.h"

int main(int argc, char **argv) {
  flag_t *flag = malloc(sizeof(flag_t));
  flag = init_flags(flag, read_write);

  file_t *file = malloc(sizeof(file_t));
  file = init_file(file, argv[1], flag);

  read_file(file, ONE_BLOCK);
  print_buffer(file);

  token_t **res = malloc(sizeof(token_t *) * 10);
  res = get_tokens(3, get_token_from_str("#define"),
                   get_token_from_str("#ifdef"), get_token_from_str("#elif"));
  for (int i = 0; i < 3; i++)
    token_print(*(res + i));

  // VectorToken_t *vector = malloc(sizeof(VectorToken_t));

  // vector_init (vector);

  // vector_add (vector, token);

  // token = vector = 0;
  // vector_deinit (vector);
  // token_deinit (token);

  return 0;
}
