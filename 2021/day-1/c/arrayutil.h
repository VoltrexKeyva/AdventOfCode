#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H

#include <stdlib.h>
#include <stdint.h>

// specialized array type
typedef struct {
    uint16_t * data;
    uint8_t capacity;
    uint16_t size;
} _array_t, * array_t;

#define free_parsed_array(arr) \
    free(arr->data); \
    free(arr);

array_t parse_array(char *);

#endif