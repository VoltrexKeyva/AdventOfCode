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

array_t parse_array(char * str) {
    array_t arr = malloc(sizeof(_array_t));
    
    arr->size = 0;
    arr->capacity = CHUNK_SIZE;
    arr->data = malloc(CHUNK_SIZE * sizeof(uint16_t));
    
    char * token = strtok(str, "\n");

    while (token != NULL) {
        if (arr->size < arr->capacity) {
arr_set:
            arr->data[arr->size] = parse_int(token);
            arr->size++;
        } else {
            arr->capacity += CHUNK_SIZE;
            arr->data = realloc(arr->data, arr->capacity * sizeof(uint16_t));
            goto arr_set;
        }
        
        token = strtok(NULL, "\n");
    }
    
    return arr;
}