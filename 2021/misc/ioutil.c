#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

char * read_file(const char * filename) {
    FILE * fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;
    
    fseek(fp, 0, SEEK_END);
    
    const uint16_t file_size = (uint16_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char * data = malloc(file_size);
    fread(data, file_size, 1, fp);
    fclose(fp);
    
    return data;
}