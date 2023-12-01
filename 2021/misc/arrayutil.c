#include "arrayutil.h"
#define CHUNK_SIZE 10

array_t new_array(void) {
  array_t arr = malloc(sizeof(_array_t));

  arr->size = 0;
  arr->capacity = CHUNK_SIZE;
  arr->data = malloc(CHUNK_SIZE * sizeof(num_t));

  return arr;
}

void append_array(array_t arr, const num_t elem) {
  if (arr->size < arr->capacity) {
  append:
    arr->data[arr->size] = elem;
    arr->size += 1;
  } else {
    arr->capacity += CHUNK_SIZE;
    arr->data = realloc(arr->data, arr->capacity * sizeof(num_t));
    goto append;
  }
}