#include "parser.h"
#include <string.h>

static num_t parse_int(const char * str) {
    num_t result = 0;
    
    while ((*str >= '0') && (*str <= '9')) {
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    
    return result;
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