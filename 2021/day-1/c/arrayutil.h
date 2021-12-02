#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H

#include <stdlib.h>
#include <stdint.h>

// specialized array type
typedef struct {
    uint16_t * data;
    uint16_t capacity;
    uint16_t size;
} _array_t, * array_t;

array_t parse_array(char *);

#endif