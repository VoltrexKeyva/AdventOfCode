#include <string.h>
#include "arrayutil.h"
#define CHUNK_SIZE 10

static uint16_t parse_int(const char * str) {
    uint16_t result = 0;
    
    while ((*str >= '0') && (*str <= '9')) {
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    
    return result;
}

array_t new_array(void) {
    array_t arr = malloc(sizeof(_array_t));

    arr->size = 0;
    arr->capacity = CHUNK_SIZE;
    arr->data = malloc(CHUNK_SIZE * sizeof(uint16_t));

    return arr;
}

void append_array(array_t arr, const uint16_t elem) {
    if (arr->size < arr->capacity) {
append:
        arr->data[arr->size] = elem;
        arr->size += 1;
    } else {
        arr->capacity += CHUNK_SIZE;
        arr->data = realloc(arr->data, arr->capacity * sizeof(uint16_t));
		goto append;
    }
}

array_t parse_array(char * str) {
    array_t arr = new_array();
    char * token = strtok(str, "\n");
    
    while (token != NULL) {
        append_array(arr, parse_int(token));
        token = strtok(NULL, "\n");
    }
    
    return arr;
}