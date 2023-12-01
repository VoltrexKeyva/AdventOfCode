#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H

#include <stdint.h>
#include <stdlib.h>

#if _INTEGER_BIT_TYPE == 16
typedef uint16_t num_t;
#elif _INTEGER_BIT_TYPE == 32
typedef uint32_t num_t;
#endif

// specialized array type
typedef struct {
  num_t* data;
  num_t capacity;
  num_t size;
} _array_t, *array_t;

array_t new_array(void);
void append_array(array_t, const num_t);

#endif