#include <stdlib.h>

#include "arena.c"

struct vec2 {
  i8 x;
  i8 y;
};

int main(void) {
  arena_t a = arena_make(1024 * 1024); // 1MB

  // allocate an int
  i32 *x = arena_allocate(&a, sizeof(i32));
  *x = 64;


  // allocate an array of 10 floats
  f32 *vects = arena_allocate(&a, sizeof(f32) * 10);
  vects[0] = 1.0f;
  vects[1] = 2.0f;
  // ...

  // allocate array of 64 ints with macro
  i8 *nums = allocate_array(&a, i8, 64);
  
  // allocate a single struct with macro
  struct vec2 *my_vec = allocate_struct(&a, struct vec2);

  // allicate zero initialized struct
  struct vec2 *other_vec = allocate_struct_zero(&a, struct vec2);

  // done with the data? reset everything at once
  arena_reset(&a);

  // free all the memory!
  arena_destroy(&a);
  return EXIT_SUCCESS;
}
