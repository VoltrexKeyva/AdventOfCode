#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if   _INTEGER_BIT_TYPE == 16
typedef uint16_t num_t;
#elif _INTEGER_BIT_TYPE == 32
typedef uint32_t num_t;
#endif

char * read_file(const char * filename) {
    FILE * fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;
    
    fseek(fp, 0, SEEK_END);
    
    const num_t file_size = (num_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char * data = malloc(file_size);
    fread(data, file_size, 1, fp);
    fclose(fp);
    
    return data;
}